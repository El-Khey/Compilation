#include "../../../symbol_table/representation/representation_table.h" 
#include "../../../symbol_table/declaration/declaration_table.h" 
#include "../../../type_system/type_inference/type_inference.h"
#include "../../../symbol_table/lexeme/lexeme_table.h"
#include "../../../data/region_table.h"
#include "../common/format_specifiers.h"


void check_print_proc_argument_list(Node *format_string, Node *argument_list) {
    // Step 1: Extract format specifiers from the format string
    const char *format = get_lexeme(format_string->index_lexicographic);
    int expected_count = count_format_specifiers(format);

    // Step 2: Validate argument count
    int actual_count = count_argument_list(argument_list);
    if (expected_count != actual_count) {
        set_error_type(&error, SEMANTIC_ERROR);
        set_error_message(&error, 
            "Argument mismatch in format string at %s.\n"
            "  Format string expects %d arguments, but %d were provided.\n"
            "  Ensure the correct number of arguments are passed to match the format string.\n",
            get_formatted_location(),
            expected_count, 
            actual_count
        );
        yerror(error);
        return;
    }

    // Step 3: Validate argument types
    Node *current_arg = argument_list->child;
    for (int i = 0; i < expected_count; ++i) {
        char specifier = get_nth_format_specifier(format, i);
        int argument_type = resolve_expression_type(current_arg->child);

        if (!is_compatible_with_format_specifier(argument_type, specifier)) {
            set_error_type(&error, TYPE_ERROR);
            set_error_message(&error, 
                "Type mismatch for argument %d at %s.\n"
                "  Argument '%d' has type '%s', but specifier '%c' expects a different type.\n"
                "  Ensure the argument type matches the expected type for the specifier.\n",
                i + 1,
                get_formatted_location(),
                i + 1, 
                get_lexeme(argument_type), 
                specifier
            );
            yerror(error);
        }

        current_arg = current_arg->sibling;
    }
}
