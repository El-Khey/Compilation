#ifndef __LCRS_H__
#define __LCRS_H__

#include <stdio.h>
#include <stdlib.h>
#include "node_type.h"

typedef struct Node {
    struct Node* child;            // Pointer to the leftmost child
    struct Node* sibling;          // Pointer to the right sibling
    
    NodeType type;                 // Node type (operator, variable, literal, etc.)
    int index_lexicographic;       // Index in the lexicographic table
    int index_declaration;         // Index in the declaration table
} Node;

/**
 * @brief Creates a new AST node.
 * 
 * @param type Type of the node.
 * @param index_lexicographic Index in the lexicographic table (if applicable).
 * @param index_declaration Index in the declaration table (if applicable).
 * @return A pointer to the newly created node.
 */
Node* construct_node(NodeType type, int index_lexicographic, int index_declaration);

/**
 * @brief Creates a new AST node with default indices.
 * 
 * @param type Type of the node.
 * @return A pointer to the newly created node.
 */
Node* construct_node_default(NodeType type);

/**
 * @brief Adds a child node to the given parent node.
 * 
 * @param parent The parent node to which the child will be added.
 * @param child The child node to add.
 */
void add_child(Node* parent, Node* child);

/**
 * @brief Adds a sibling node to the given node.
 * 
 * @param node The node to which the sibling will be added.
 * @param sibling The sibling node to add.
 */
void add_sibling(Node* node, Node* sibling);

/**
 * @brief Checks if the given node is NULL.
 * 
 * @param node The node to check.
 * @return 1 if the node is NULL, 0 otherwise.
 */
int is_node_null(Node* node);

#endif // __LCRS_H__