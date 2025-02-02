#include <stdlib.h>
#include <assert.h>


/**
 * @file list.h
 * 
 * Doubly-Linked list header file
 * 
 * @author Evin Odisho
 */



typedef struct list list_t;


/**
 * @brief List constructor
 * 
 * @param void
 * 
 * @return *list_t
 */
list_t *NewList();


/**
 * @breif List destructor
 * 
 * @param **list_t
 * 
 * @return void
 */
void DeleteList(list_t **list);


/**
 * @brief Delete cursor node from list and set cursor val to
 * 
 * @param *list_t
 * 
 * @return void
 */
void DeleteCursor(list_t *list);


/**
 * @brief Delete head node from list
 * 
 * @param *list_t
 * 
 * @return void
 */
void DeleteHead(list_t *list);


/**
 * @brief Prepend node to list
 * 
 * @param *list_t Pointer to list to prepend node to
 * 
 * @param int Value for prepended node to hold
 * 
 * @return void
 */
void PrependNode(list_t *list, int value);


/**
 * @brief Append node to list
 * 
 * @param *list_t Pointer to list to append node to
 * 
 * @param int Value for appended node to hold
 * 
 * @return void
 */
void AppendNode(list_t *list, int value);


/**
 * @brief Get head node value
 * 
 * @param *list_t pointer to list_t object
 * 
 * @return int holding value of head node
 */
int GetHeadNode(list_t *list);


/**
 * @brief Get tail node value
 * 
 * @param *list_t pointer to list_t object
 * 
 * @return int holding value of tail node
 */
int GetTailNode(list_t *list);


/**
 * @brief Get node value cursor is pointing to
 * 
 * @param *list_t pointer to list_t object
 * 
 * @return int holding value of node cursor points to
 */
int GetCursorNode(list_t *list);


/**
 * @brief Move cursor to head node
 * 
 * @param *list_t pointing to your list
 * 
 * @return void
 */
void MoveFront(list_t *list);


/**
 * @brief Move cursor to next node
 * 
 * @param *list_t pointing to your list
 * 
 * @return void
 */
void MoveNext(list_t *list);


/**
 * @brief Move cursor to previous node
 * 
 * @param *list_t pointing to your list
 * 
 * @return void
 */
void MovePrev(list_t *list);


/**
 * @brief Walk through list, printing each node value
 * 
 * @param *list_t pointing to your list
 * 
 * @return void
 */
void WalkList(list_t *list);


/**
 * TODO: DELETE WHEN DONE
 */
int NodeTest();
