#include <stdlib.h>

#include "constants.h"
#include "linkedlist.h"

/******************************************************************************
Node methods */

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

/******************************************************************************
Linked list methods */

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
        return ERROR;
    }
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
        }
    list->size++;
    return SUCCESS;
}

int LinkedList_Prepend(LinkedList *list, void *object){
    Node *node = Node_New(object);
    if (node == NULL){
        return ERROR;
    }
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->head->prev = node;
        node->next = list->head
        list->head = node;
    }
    list->size++;
    return SUCCESS;
}

int LinkedList_PopHead(LinkedList *list, void *res) {
    if (list->tail == NULL) {
        return ERROR;
    }
    if (list->size == 1) {
        *res = list->head->ob;
        Node_Free(list->head);
        list->head = list->tail = NULL;
        list->size--;
        return SUCCESS;
    }
    *res = list->head->ob;
    list->head = list->head->next;
    Node_Free(list->head->prev);
    list->head->prev = NULL;
    list->size--;
    return SUCCESS
}

int LinkedList_PopTail(LinkedList *list, void *res) {
    if (list->head == NULL) {
        return ERROR;
    }
    if (list->size == 1) {
        *res = list->tail->ob;
        Node_Free(list->tail);
        list->head = list->tail = NULL;
        list->size--;
        return SUCCESS;
    }
    *res = list->tail->ob;
    list->tail = list->tail->prev;
    Node_Free(list->tail->next);
    list->tail->next = NULL;
    list->size--;
    return SUCCESS
}

Node *_LinkedList_GetNode(LinkedList *list, size_t index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }
    if (index <= list->size / 2) {
        Node *current = list->head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    } else {
        Node *current = list->tail;
        for (size_t i = list->size - 1; i > index; i++) {
            current = current->prev;
        }
        return current;
    }
}

void *LinkedList_GetIndex(LinkedList *list, size_t index) {
    Node *node = _LinkedList_GetNode(list, index);
    if (node == NULL) {
        return NULL;
    }
    return node->ob;
}

int LinkedList_SetIndex(LinkedList *list, size_t index, void *ob) {
    Node *node = _LinkedList_GetNode(list, index);
    if (node == NULL) {
        return ERROR;
    }
    node->ob = ob;
    return SUCCESS;
}

int LinkedList_DelIndex(LinkedList *list, size_t index) {
    if (list->size == 1) {
        if (index != 0) {
            return ERROR;
        }
        Node_Free(list->head);
        list->head = list->tail = 0;
        list->size--;
    } else if (index == 0) {
        list->head = list->head->next;
        Node_Free(list->head->prev);
        list->head->prev = NULL;
        list->size--;
    } else if (index == list->size - 1) {
        list->tail = list->tail->prev;
        Node_Free(list->tail->next);
        list->tail->next = NULL;
        list->size--;
    } else {
        Node *node = _LinkedList_GetNode(list, index);
        if (node == NULL) {
            return ERROR;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        Node_Free(node);
        list->size--;
    }
    return SUCCESS;
}

/******************************************************************************
Iterator methods */

LinkedList_Iterator *LinkedList_GetIter(LinkedList *list) {
    LinkedList_Iterator *it = malloc(sizeof(LinkedList_Iterator));
    if (it == NULL) {
        return NULL;
    }
    it->list = list;
    it->it_size = list->size;
    it->current = list->head;
    return it;
}

int LinkedList_IterNext(LinkedList_Iterator *it, void *res) {
    if (it->list->size != it->it_size) {
        return ERROR;
    }
    if (it->current == NULL) {
        return ITER_EXHAUSTED;
    }
    *res = it->current->ob;
    it->current = it->current->next;
    return SUCCESS;
}
