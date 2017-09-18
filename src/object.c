#include <stdlib.h>

#include "linkedlist.h"
#include "vector.h"
#include "object.h"

Object *Object_New(float x, float y, float dx, float dy, int is_static) {
    Object *ob = malloc(sizeof(Object));
    if (ob == NULL) {
        return NULL;
    }
    ob->location = Vector_New(x, y);
    if (ob->location == NULL) {
        return NULL;
    }
    ob->velocity = Vector_New(dx, dy);
    if (ob->velocity == NULL) {
        Vector_Free(ob->location);
        return NULL;
    }
    ob->is_static = is_static;
    return ob;
}

void Object_Free(Object *ob) {
    Vector_Free(ob->location);
    Vector_Free(ob->velocity);
}
