#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

#define LL_NO_ERROR 0
#define LL_ERROR 1
#define LL_IT_EXHAUSTED 2

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

typedef struct {
    LinkedList *list;
    size_t it_size;
    Node *current;
} LinkedList_Iterator;

Node *Node_New(void *);
void Node_Free();

LinkedList *LinkedList_New();
void LinkedList_Free(LinkedList *);
int LinkedList_Append(LinkedList *, void *);
int LinkedList_Prepend(LinkedList *, void *);
int *LinkedList_PopHead(LinkedList *, void*);
int *LinkedList_PopTail(LinkedList *, void*);
void *LinkedList_GetIndex(LinkedList *, size_t);
int LinkedList_SetIndex(LinkedList *, size_t, void *);
int LinkedList_DelIndex(LinkedList *, size_t);

LinkedList_Iterator LinkedList_GetIter(LinkedList *);
int LinkedList_IterNext(LinkedList_Iterator *, void *);

#endif /* LINKEDLIST_H */
