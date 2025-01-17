#include "../../../symbol_table/representation/representation_table.h" 
#include "../../../symbol_table/declaration/declaration_table.h" 
#include "../../../type_system/type_inference/type_inference.h"
#include "../../../symbol_table/lexeme/lexeme_table.h"
#include "../../../data/region_table.h"

int get_func_proc_declaration_index(int index_lexeme_lexicographic) {
    int func_index = find_declaration_index_by_nature(index_lexeme_lexicographic, TYPE_FUNC);
    return (func_index != NULL_VALUE) ? func_index 
                                      : find_declaration_index_by_nature(index_lexeme_lexicographic, TYPE_PROC);
}

void check_func_proc_definition(int index_lexeme_lexicographic) {
    if (get_func_proc_declaration_index(index_lexeme_lexicographic) == NULL_VALUE) {
        set_error_type(&error, SEMANTIC_ERROR);
        set_error_message(&error, 
            "Undeclared function or procedure at %s.\n"
            "  The function or procedure '%s' is not defined in the current scope.\n"
            "  Ensure that the function or procedure is declared before usage.\n",
            get_formatted_location(),
            get_lexeme(index_lexeme_lexicographic)
        );
        yerror(error);
    }
}

void check_func_proc_redefinition(int index_lexeme_lexicographic, char *type) {
    int index_func_proc_declaration = get_func_proc_declaration_index(index_lexeme_lexicographic);
    if (index_func_proc_declaration != NULL_VALUE && peek_region() == get_declaration_region(index_func_proc_declaration)) {
        set_error_type(&error, SEMANTIC_ERROR);
        set_error_message(&error, 
            "Redefinition of %s '%s' at %s.\n"
            "  This identifier '%s' has already been defined.\n"
            "  Consider renaming or modifying the existing definition.\n",
            type,
            get_lexeme(index_lexeme_lexicographic),
            get_formatted_location(),
            get_lexeme(index_lexeme_lexicographic)
        );
        yerror(error);
    }
}

void check_func_prototype(int index_lexeme_lexicographic, Node *return_statement) {
    // functions return type can only be base types (int, float, char, bool)
    int base_type = index_lexeme_lexicographic;
    int expression_type = resolve_expression_type(return_statement->child);

    if (base_type != expression_type) {
        set_error_type(&error, TYPE_ERROR);
        set_error_message(&error, 
            "Type mismatch for function return value at %s.\n"
            "  Function returned value has type '%s', but it should be of type '%s'.\n"
            "  Ensure the function return type matches the expected type.\n",
            get_formatted_location(),
            (expression_type == NULL_VALUE) ? "UNKNOWN" : get_lexeme(expression_type), 
            get_lexeme(base_type)
        );
        yerror(error);
        return;
    }
}

void check_func_proc_argument_list(int index_lexeme_lexicographic, Node *argument_list) {
    int index_declaration = get_func_proc_declaration_index(index_lexeme_lexicographic);
    if (index_declaration == NULL_VALUE) return; // do not check undeclared functions

    Nature nature = get_declaration_nature(index_declaration);

    int parameter_count = resolve_func_proc_parameter_count(index_lexeme_lexicographic, nature);

    // Check argument count validity first
    validate_argument_count(argument_list, parameter_count);

    // Validate argument types
    validate_each_argument(argument_list, parameter_count, index_lexeme_lexicographic, nature);
}
