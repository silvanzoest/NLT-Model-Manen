#include "linkedlist.h"

Node *Node_New(void *ob) {
	Node *node = malloc(sizeof(Node));
	if (node == NULL) {
		return NULL;
	}
	node->ob = ob;
	return node;
}

void Node_Free(Node *node) {
	node->prev = node->next = NULL;
	node->ob = NULL;
	free(node);
}

LinkedList *LinkedList_New() {
	LinkedList *list = malloc(sizeof(LinkedList));
	if (list == NULL) {
		return NULL;
	}
	list->size = 0;
	list->head = list->tail = NULL;
	return list;
}

void LinkedList_Free(LinkedList *list) {
	while (list->head != NULL) {
		Node *current = list->head;
		list->head = current->next;
		Node_Free(current);
	}
	free(list);
}

int LinkedList_Append(LinkedList *list, void *object){
	Node *node = Node_New(object);
	if (node == NULL){
		return 1;
	}
	if (list->size == 0) {
		list->head = node;
		list->tail = node;
	} else {
		list->tail->next = node;
		node->prev = list->tail;
		list ->tail = node;
	}
	list->size++;
	return 0;
}

int LinkedList_Prepend(LinkedList *list, void *object){
	Node *node = Node_New(object);
	if (node == NULL){
		return 1;
	}
	if (list->size == 0) {
		list->head = node;
		list->tail = node;
	} else {
		list->head->prev = node;
		node->next = list->head;
		list ->head = node;
	}
	list->size++;
	return 0;
}