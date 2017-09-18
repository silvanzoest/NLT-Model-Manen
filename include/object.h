#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"
#include "linkedlist.h"

typedef struct {
    int is_static;
    Vector *location;
    Vector *velocity;
} Object;

Object *Object_New(double, double, double, double, int);
void Object_Free(Object *);

#endif /* OBJECT_H */
