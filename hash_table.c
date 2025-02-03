#include "hash_table.h"

struct table {
	size_t size;    // Size of arr
	list_t **arr;    // Array of linked lists
	bool isEmpty;   // Boolean for if table is empty or not
};

table_t *NewTable(size_t size) {
	table_t *table = malloc(sizeof(table_t));
	table->arr = NewListArr(size);
	table->size = size;
	table->isEmpty = true;

	return table;
}

void DeleteTable(table_t **table) {
	if (table != NULL && *table != NULL) {
		DeleteListArr(&((*table)->arr), (*table)->size);
		free(*table);
		*table = NULL;
	}

	return;
}
