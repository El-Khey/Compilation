#ifndef __HASH_H__
#define __HASH_H__

#include "../../../lib/colors.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 32

/**
 * @brief Compute hash code for a given lexeme and insert it into the hash table.
 * 
 * @authors Benguezzou Mohamed, Benmamar Djibril
 * @param lexeme : The lexeme to add.
 * @param next : The next index.
 */
void insert_hash(const char* lexeme, int next);

/**
 * @brief Initialize the hash table.
 */
void init_hash_table();

/**
 * @brief Hash function to generate a hash code for a given lexeme.
 * @authors Benguezzou Mohamed, Benmamar Djibril
 * @param lexeme : The lexeme to hash.
 * @param length : The length of the lexeme.
 * @return int : The hash code.
 */
int hash_function(const char* lexeme, int length);

/**
 * @brief Find the value at the given index in the hash table.
 * @authors Benguezzou Mohamed, Benmamar Djibril
 * @param index : The index to find the value.
 * @return int : The value at the given index.
 */
int get_hash_value(int index);

/**
 * @brief Display the contents of the hash table.
 * @authors Benguezzou Mohamed, Benmamar Djibril
 * @param out : The output stream to write to.
 */
void fprintf_hash_table(FILE* out);

#endif // __HASH_H__
