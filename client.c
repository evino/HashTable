#include <stdio.h>
#include "list.h"
#include "hash_table.h"

// Integer Test Function
void test_insert_int(table_t *t) {
    char *key1 = "testInt1";
    int value1 = 42;
    InsertPair(t, key1, &value1, INT);

    char *key2 = "testInt2";
    int value2 = 99;
    InsertPair(t, key2, &value2, INT);

    char *key3 = "testInt3";
    int value3 = 123;
    InsertPair(t, key3, &value3, INT);
	
	GetValue(t, key3);
	GetValue(t, key1);
	GetValue(t, key2);

	// Invalid key test test
	char *invalidKey = "Not Here";
    GetValue(t, invalidKey);
}

// Float Test Function
void test_insert_float(table_t *t) {
    char *key1 = "testFloat1";
    float value1 = 3.14;
    InsertPair(t, key1, &value1, FLOAT);

    char *key2 = "testFloat2";
    float value2 = 2.718;
    InsertPair(t, key2, &value2, FLOAT);

    char *key3 = "testFloat3";
    float value3 = 1.618;
    InsertPair(t, key3, &value3, FLOAT);

	GetValue(t, key2);
	GetValue(t, key1);
	GetValue(t, key3);
}

// String Test Function
void test_insert_string(table_t *t) {
    char *key1 = "testString1";
    char *value1 = "Hello, World!";
    InsertPair(t, key1, value1, STRING);

    char *key2 = "testString2";
    char *value2 = "Goodbye, World!";
    InsertPair(t, key2, value2, STRING);

    char *key3 = "testString3";
    char *value3 = "Hello, Universe!";
    InsertPair(t, key3, value3, STRING);

	GetValue(t, key1);
	GetValue(t, key2);
	GetValue(t, key3);
}



int main(int argc, char **argv) {
	printf("Hello from client file!\n");

	// Test node create and delete funcs
	// NodeTest();

	// Create table
	size_t size = 10;
	table_t *t = NewTable(size);
	printf("Table created\n");

	// Insert {"test": 7} into t
	// const char *testKey1 = "testKey";
	// int testValue1 = 7;
	// InsertPair(t, testKey, &testValue, INT);
	
	// GetValue(t, testKey);
	test_insert_int(t);
	test_insert_float(t);
	test_insert_string(t);

	DeleteTable(&t);
	printf("Table deleted\n");


	return 0;
}
