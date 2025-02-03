#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct table table_t;

/**
 * @brief Hash table constructor
 * 
 * @param size_t size of table (array length)
 * 
 * @return *table_t Pointer to new table
 */
table_t *NewTable(size_t size);

/**
 * @brief Hash table destructor
 * 
 * @param **table_t Hash table to delete
 * 
 * @return void
 */
void DeleteTable(table_t **table);


/**
 * @brief Hashes a key (string) into an unsigned long integer
 * using djb2 hashing algorithm
 * 
 * @param char* key
 * 
 * @return unsigned long
 */
unsigned long HashDJB2(const char *key);


/**
 * @brief Returns index to insert/lookup for a given key
 * 
 * @param char* key
 * 
 * @param size_t tableSize
 * 
 * @return size_t
 */
size_t GetIndex(const char *key, size_t tableSize);


/**
 * @brief Inserts key-value pair into hash table
 * 
 * @param table_t* Pointer to table_t
 * 
 * @param char* key
 * 
 * @param void* value (Must be INT, FLOAT, or STRING)
 * 
 */
void InsertPair(table_t * table, const char *key, void *value);
