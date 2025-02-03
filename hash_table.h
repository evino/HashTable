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
