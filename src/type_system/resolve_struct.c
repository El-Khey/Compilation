#include "../symbol_table/representation_table.h" 
#include "../symbol_table/declaration_table.h" 
#include "../lexer/lexeme_table.h"
#include "../data/region_table.h"

static int resolve_struct_declaration(Node *current_node) {
    int current_type_declaration = find_declaration_index(get_declaration_description(current_node->index_declaration));

    if (get_declaration_nature(current_type_declaration) != TYPE_STRUCT) {
        set_error_type(&error, SEMANTIC_ERROR);
        set_error_message(&error, "Field access is only allowed on struct types.");
        yerror(error);
        return NULL_VALUE;
    }

    return current_type_declaration;
}

static int get_struct_field_index_declaration(int current_type_representation, int field_index) {
    return get_representation_value(current_type_representation + 2 + (field_index * 3));
}

static int get_struct_field_index_lexico(int current_type_representation, int field_index) {
    return get_representation_value(current_type_representation + 1 + (field_index * 3));
}

static int is_field_in_struct(int current_type_representation, int num_fields, int index_lexicographic, int *field_index) {
    for (int i = 0; i < num_fields; i++) {
        if (get_struct_field_index_lexico(current_type_representation, i) == index_lexicographic) {
            *field_index = i;
            return 1;
        }
    }
    return 0;
}

int resolve_field_access(Node *current_node, int current_type_declaration) {
    int current_type_representation = get_declaration_description(current_type_declaration);
    int num_fields = get_representation_value(current_type_representation);

    int index_lexicographic = current_node->index_lexicographic;
    int field_index = -1;
    
    // TODO: Check for array access here 
    if (!is_field_in_struct(current_type_representation, num_fields, index_lexicographic, &field_index)) {
        set_error_type(&error, SEMANTIC_ERROR);
        set_error_message(&error, "Field '%s' does not exist in struct.", get_lexeme(index_lexicographic));
        yerror(error);
        return NULL_VALUE;
    }

    int field_declaration_index = get_struct_field_index_declaration(current_type_representation, field_index);
    if (get_declaration_nature(field_declaration_index) != TYPE_STRUCT && current_node->child != NULL) {
        set_error_type(&error, SEMANTIC_ERROR);
        set_error_message(&error, "Field '%s' is not a struct, so further field access is invalid.", get_lexeme(index_lexicographic));
        yerror(error);
        return NULL_VALUE;
    }

    return field_declaration_index;
}

int resolve_struct_field_access_type(Node *struct_field_access) {
    Node *current_node = struct_field_access;

    int current_type_declaration = resolve_struct_declaration(current_node);
    if (current_type_declaration == NULL_VALUE) {
        return NULL_VALUE;
    }

    current_node = current_node->child;
    while (current_node != NULL && current_node->type == A_STRUCT_FIELD_ACCESS) {
        current_type_declaration = resolve_field_access(current_node, current_type_declaration);
        if (current_type_declaration == NULL_VALUE) {
            return NULL_VALUE;
        }

        current_node = current_node->child;
    }

    return current_type_declaration;
}
