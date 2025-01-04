#ifndef __FUNC_PROC_VALIDATION_H__
#define __FUNC_PROC_VALIDATION_H__

#include "../common/argument_validation.h"
#include "../../validation_utils.h"
#include "../../../ast/ast.h"


/**
 * @brief Retrieves the declaration index of a function or procedure.
 *
 * This function retrieves the declaration index of a function or procedure based on the lexicographic index of the name.
 * If the function or procedure is not found, NULL_VALUE is returned.
 * 
 * @authors Benguezzou Mohamed, Benmamar Djibril
 * @param index_lexeme_lexicographic The lexicographic index of the function or procedure's name.
 * @return The declaration index of the function or procedure.
 */
int get_func_proc_declaration_index(int index_lexeme_lexicographic);

/**
 * @brief Validates the definition of a function or procedure.
 *
 * This function checks if a function or procedure has been defined in the current scope.
 * If the function or procedure has not been defined, an error is thrown.
 *
 * @authors Benguezzou Mohamed, Benmamar Djibril
 * 
 * @param index_lexeme_lexicographic The lexicographic index of the function or procedure's name.
 */
void check_func_proc_definition(int index_lexeme_lexicographic);

/**
 * @brief Checks if a function or procedure has been redefined.
 *
 * This function checks if a function or procedure has been redefined in the current scope.
 * If the function or procedure has been redefined, an error is thrown.
 *
 * @authors Benguezzou Mohamed, Benmamar Djibril
 *
 * @param index_lexeme_lexicographic The lexicographic index of the function or procedure's name.
 * @param type The type of the function or procedure.
 */
void check_func_proc_redefinition(int index_lexeme_lexicographic, char *type);

/**
 * @brief Validates the return statement of a function.
 *
 * This function checks if the return statement of a function matches the expected return type.
 * If the return statement does not match, an error is thrown.
 *
 * @authors Benguezzou Mohamed, Benmamar Djibril
 *
 * @param index_lexeme_lexicographic The lexicographic index of the function's name.
 * @param return_statement The return statement provided in the function.
 */
void check_func_prototype(int index_lexeme_lexicographic, Node *return_statement);

/**
 * @brief Validates the argument list of a function.
 *
 * This function checks if the arguments provided in the function call match the expected arguments.
 * If the arguments do not match, an error is thrown.
 *
 * @authors Benguezzou Mohamed, Benmamar Djibril
 *
 * @param index_lexeme_lexicographic The lexicographic index of the function's name.
 * @param argument_list The argument list provided in the function call.
 */
void check_func_proc_argument_list(int index_lexeme_lexicographic, Node *argument_list);

#endif // __FUNC_PROC_VALIDATION_H__