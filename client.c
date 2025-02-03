#include <stdio.h>
#include "list.h"
#include "hash_table.h"

int main(int argc, char **argv) {
	printf("Hello from client file!\n");

	// Test node create and delete funcs
	// NodeTest();

	// Create table
	size_t size = 10;
	table_t *t = NewTable(size);
	printf("Table created\n");
	DeleteTable(&t);
	printf("Table deleted\n");


	return 0;
}
