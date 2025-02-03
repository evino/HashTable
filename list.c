#include "list.h"
#include <stdio.h>

typedef struct node node_t;



struct list {
	int size;        // Current size of list
	int index;       // Current index of cursor (starts at 0)
	node_t *cursor;  // Current node cursor points to
	node_t *head;    // Head node of list
	node_t *tail;    // Tail node of list
};

struct node {
	ValueType valueType;
	char *key;
	void *value;
	node_t *prev;
	node_t *next;
};


/**
 * @brief Public node constructor
 * 
 * @param value The value to hold inside node
 * 
 * @return *node_t
 */
node_t *NewNode(char *key, void *value, ValueType valueType) {
	// Allocate memory for node
	node_t *n = malloc(sizeof(node_t));

	// Initialize default values
	n->key = key;
	n->value = value;
	n->valueType = valueType;
	n->prev = NULL;
	n->next = NULL;

	return n;
}

void PrintValue(node_t *node) {
	assert(node != NULL);

	switch (node->valueType) {
		case INT:
			printf("{%s: %d}\n", node->key, *(int *)node->value);
			break;
		case FLOAT:
			printf("%f\n", *(float *)node->value);
		case STRING:
			printf("%s\n", (char *)node->value);
		
		default:
			break;
	}

}


/**
 * @brief Private node destructor
 * 
 * @param node Node to delete
 * 
 * @return void
 */
void DeleteNode(node_t **node) {
	if (node != NULL || *node != NULL) {
		free(*node);
		*node = NULL;
	}

	return;
}


// List Constructor
list_t *NewList() {
	// Allocate memory for list
	list_t *l = malloc(sizeof(list_t));

	l->size = 0;
	l->index = -1;
	l->cursor = NULL;
	l->head = NULL;
	l->tail = NULL;

	return l;
}


void DeleteHead(list_t *list) {
	assert(list->size > 0);

	if (list->size == 1) {
		DeleteNode(&(list->head));
		list->head = NULL;
		list->tail = NULL;
		list->cursor = NULL;
	} else {
		list->head= list->head->next;
		DeleteNode(&(list->head->prev));
	}

	list->size--;
}

void DeleteCursor(list_t *list) {
	assert(list->cursor != NULL);

	(list->cursor->prev)->next = list->cursor->next;
	list->cursor->next->prev = list->cursor->prev;
	DeleteNode(&(list->cursor));
}


// List Destructor
void DeleteList(list_t **list) {
	/**
	 * TODO: Need to implement with iterating over list
	 */
	if (list != NULL || *list != NULL) {
		// MoveFront(*list);

		while ((*list)->head != NULL) {
			
			printf("Deleting: ");
			PrintValue(GetHeadNode(*list));
			DeleteHead(*list);
			// DeleteNode(&((*list)->cursor));
			// MoveNext(*list);
		};

		free(*list);
		*list = NULL;
	}

	return;
}


// Walk through list, printing node values
void WalkList(list_t *list) {
	assert(list->size > 0);

	MoveFront(list);
	do {
		PrintValue(GetCursorNode(list));
		MoveNext(list);
	}
	while(list->cursor != list->tail);

	printf("\n");
	return;
}


// List Prepend
void PrependNode(list_t *list, char *key, void *value, ValueType valueType) {
	node_t *node = NewNode(key, value, valueType);
	if (list->size == 0) {
		list->head = node;
		list->tail = node;
	} else {
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
	}

	list->size++;

	return;
}


// List Append
void AppendNode(list_t *list, char *key, void *value, ValueType valueType) {
	node_t *node = NewNode(key, value, valueType);

	if (list->size == 0) {
		list->head = node;
		list->tail = node;
	} else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}

	list->size++;

	return;
}


// Return value of head node
void* GetHeadNode(list_t *list) {
	assert (list->size > 0);
	return list->head;
}


// Return value of tail node
void* GetTailNode(list_t *list) {
	assert (list->size > 0);
	return list->tail;
}


// Return value of current cursor
void* GetCursorNode(list_t *list) {
	assert(list->cursor != NULL && "Cursor value is NULL");
	return list->cursor;
}


// Move cursor to next node
void MoveFront(list_t *list) {
	assert(list->size > 0 && "Cannot call MoveFront() on empty list");
	list->cursor = list->head;

	return;
}


void MoveNext(list_t *list) {
	assert(list->cursor->next != NULL && "Cursor already points to list-tail");
	// if (list->cursor != list->tail) {
		list->cursor = list->cursor->next;
	// }

	return;
}


// Move cursor to previous node
void MovePrev(list_t *list) {
	assert(list->cursor->prev != NULL && "Cursor already points to list-head");
	list->cursor = list->cursor->prev;

	return;
}


int NodeTest() {
	int val = 5;
	node_t *myNode = NewNode("test", &val, INT);
	if (myNode->prev == NULL && myNode->next == NULL) {
		// printf("Node holds: ", );
		printf("db0\n");
		printf("Node holds "); PrintValue(myNode); printf(" as value.\n");
		printf("\nBefore delete: %p\n", (void *)myNode);
		DeleteNode(&myNode);
		printf("After delete: %p\n", (void *)myNode);
		return 0;
	}
	return 1;
}

