#include "../symbol_table/representation/representation_table.h" 
#include "../symbol_table/declaration/declaration_table.h" 
#include "../utils/utils.h"
#include "type_system.h"


static int resolve_array_declaration_type(Node *array_access) {
    if (get_declaration_nature(array_access->index_declaration) == TYPE_VAR) {
        int index_array_declaration = get_declaration_description(array_access->index_declaration);
        int index_representation = get_declaration_description(index_array_declaration);
        return get_representation_value(index_representation);
    }

    // When the array is a field in a struct the index_declaration of nature TYPE_ARRAY
    // So no need to find the declaration of the array
    int index_array_declaration = get_declaration_description(array_access->index_declaration);
    int index_representation = get_representation_value(index_array_declaration);

    return index_representation;
}

int resolve_array_access_type(Node *array_access) {
    int index_type_declaration = resolve_array_declaration_type(array_access);
    Node *current_node = array_access->child;

    while (current_node != NULL) {
        if (current_node->type == A_STRUCT_FIELD_ACCESS) {

            // Resolve the field type in the struct
            if (get_declaration_nature(index_type_declaration) != TYPE_STRUCT) {
                set_error_type(&error, SEMANTIC_ERROR);
                set_error_message(&error, "Field access is invalid as the type is not a struct.");
                yerror(error);
                return NULL_VALUE;
            }

            index_type_declaration = resolve_field_access(current_node, index_type_declaration);
            if (index_type_declaration == NULL_VALUE) {
                return NULL_VALUE;
            }

            // Move to the next field access
            current_node = current_node->child;
            continue;
        }

        // STRUCT_FIELD_ACCESS are siblings of A_ARRAY_INDEX_LIST
        current_node = current_node->sibling;
    }

    return index_type_declaration;
}
