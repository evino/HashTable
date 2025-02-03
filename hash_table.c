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


unsigned long HashDJB2(const char *key) {
	unsigned long hash = 5381;
	int c;
	while ((c = *key++)) { // Iterate through characters
		hash = ((hash << 5) + hash) + c;  // hash * 33 + c
	}

	return hash;
}

size_t GetIndex(const char *key, size_t tableSize) {
	unsigned long hash = HashDJB2(key);
	size_t index = hash % tableSize;

	return index;
}

void InsertPair(table_t * table, const char *key, void *value) {
	size_t index = GetIndex(key, table->size);

	AppendNode(table->arr[index], key, value, STRING);
}
