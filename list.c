#include "list.h"
#include <stdio.h>



/**
 * @brief Public node constructor
 * 
 * @param value The value to hold inside node
 * 
 * @return *node_t
 */
node_t *NewNode(const char *key, void *value, ValueType valueType) {
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

void PrintPair(node_t *node) {
	assert(node != NULL);

	switch (node->valueType) {
		case INT:
			printf("{%s: %d}", node->key, *(int *)node->value);
			break;
		case FLOAT:
			printf("{%s: %f}", node->key, *(float *)node->value);
			break;
		case STRING:
			printf("{%s: %s}", node->key, (char *)node->value);
			break;
		
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
	if (node != NULL && *node != NULL) {
		free(*node);
		*node = NULL;
	}

	return;
}


// List Constructor
list_t *NewList() {
	// Allocate memory for list
	list_t *l = malloc(sizeof(list_t));

	if (!l) {
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	l->size = 0;
	l->index = -1;
	l->cursor = NULL;
	l->head = NULL;
	l->tail = NULL;

	return l;
}

list_t **NewListArr(size_t size) {
	list_t **arr = malloc(size * sizeof(list_t *));
	for (size_t i = 0; i < size; i++) {
		arr[i] = NewList();
		printf("New list created at index %ld\n", i);
	}

	return arr;
}

void DeleteListArr(list_t ***arr, size_t size) {
	if (arr != NULL && *arr != NULL) {
		printf("size is %ld\n", size);
		for (size_t i = 0; i < size; i++) {
			printf("Deleting list at index %ld\n", i);
			DeleteList(&(*arr)[i]);
		}
		free(*arr);
		*arr = NULL;
	}

	return;
}

// List Destructor
void DeleteList(list_t **list) {
	/**
	 * TODO: Need to implement with iterating over list
	 */
	if (list != NULL && *list != NULL) {
		printf("Something is not null\n");
		// MoveFront(*list);

		while ((*list)->head != NULL) {
			
			printf("Deleting: ");
			PrintPair(GetHeadNode(*list));
			printf("\n");
			DeleteHead(*list);
			// DeleteNode(&((*list)->cursor));
			// MoveNext(*list);
		};
		printf("No more nodes in list to delete\n");

		free(*list);
		*list = NULL;
	} else {
		printf("List is already null");
	}

	return;
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


// Walk through list, printing node values
void WalkList(list_t *list) {
	assert(list->size > 0);

	MoveFront(list);
	do {
		PrintPair(GetCursorNode(list));
		printf("\n");
		MoveNext(list);
	}
	while(list->cursor != list->tail);

	printf("\n");
	return;
}


// List Prepend
void PrependNode(list_t *list, const char *key, void *value, ValueType valueType) {
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
void AppendNode(list_t *list, const char *key, void *value, ValueType valueType) {
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
node_t *GetHeadNode(list_t *list) {
	assert (list->size > 0);
	return list->head;
}


// Return value of tail node
node_t *GetTailNode(list_t *list) {
	assert (list->size > 0);
	return list->tail;
}


// Return value of current cursor
node_t *GetCursorNode(list_t *list) {
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

const char *GetKey(node_t *node) {
	return node->key;
}


int NodeTest() {
	int val = 5;
	node_t *myNode = NewNode("test", &val, INT);
	if (myNode->prev == NULL && myNode->next == NULL) {
		// printf("Node holds: ", );
		printf("db0\n");
		printf("Node holds "); PrintPair(myNode); printf(" as value.\n");
		printf("\nBefore delete: %p\n", (void *)myNode);
		DeleteNode(&myNode);
		printf("After delete: %p\n", (void *)myNode);
		return 0;
	}
	return 1;
}
