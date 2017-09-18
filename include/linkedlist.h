#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    void *ob;
} Node;

typedef struct {
    size_t size;
    Node *head;
    Node *tail;
} LinkedList;

Node *Node_New(void *);
void Node_Free();
LinkedList *LinkedList_New();
void LinkedList_Free(LinkedList *);
int LinkedList_Append(LinkedList *, void *);
int LinkedList_Prepend(LinkedList *, void *); 

#endif /* LINKEDLIST_H */
