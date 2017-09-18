#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"
#include "linkedlist.h"

typedef struct {
	int is_static;
	Vector *location;
	Vector *velocity;
} Object;

Object *Object_New(double x, double y, int);

#endif /* OBJECT_H */
