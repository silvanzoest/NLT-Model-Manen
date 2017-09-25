#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"
#include "linkedlist.h"

typedef struct {
    int is_static;
    float mass;
    Vector *location;
    Vector *velocity;
} Object;

Object *Object_New(double, double, double, double, int);
void Object_Free(Object *);

LinkedList *GetObjects(void);

int Object_Init(void);

#endif /* OBJECT_H */
