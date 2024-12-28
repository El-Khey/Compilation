#ifndef __AST_H__
#define __AST_H__

#include "node_type.h"
#include "lcrs.h"

// AST Root Type
typedef struct Node* AST;

/**
 * @brief Creates an empty AST.
 * @author Benguezzou Mohamed, Djibril Benmamar
 * @return An empty AST (root node is NULL).
 */
AST construct_ast();

/**
 * @brief Formats the AST in a human-readable format.
 * @param node The root of the AST to format.
 * @author Benguezzou Mohamed, Djibril Benmamar
 * @return A formatted string representing the AST.
 */
char* format_ast(Node* node);

/**
 * @brief Prints the AST in a human-readable format.
 * @author Benguezzou Mohamed, Djibril Benmamar
 * @param ast The root of the AST to print.
 */
void fprintf_ast(FILE* out, AST ast);

/**
 * @brief Frees all memory associated with the AST.
 * @author Benguezzou Mohamed, Djibril Benmamar
 * @param ast The root of the AST to free.
 */
void free_ast(AST ast);

#endif // __AST_H__
