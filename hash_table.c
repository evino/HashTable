#include "hash_table.h"

struct table {
	size_t size;    // Size of arr
	list_t *arr;    // Array of linked lists
	bool isEmpty;   // Boolean for if table is empty or not
};

int pass() {
	return 1;
}

