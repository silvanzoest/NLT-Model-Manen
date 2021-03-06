#include <stdlib.h>

#include "constants.h"
#include "linkedlist.h"
#include "vector.h"
#include "object.h"

static int intitialized = 0;
static LinkedList *objects;

Object *Object_New(double x, double y, double dx, double dy, double mass, int is_static) {
    if ((!initialized) && Object_Init() == ERROR) {
        return NULL;
    }
    Object *ob = malloc(sizeof(Object));
    if (ob == NULL) {
        return NULL;
    }
    ob->location = Vector_New(x, y);
    if (ob->location == NULL) {
        free(ob);
        return NULL;
    }
    ob->velocity = Vector_New(dx, dy);
    if (ob->velocity == NULL) {
        Vector_Free(ob->location);
        free(ob);
        return NULL;
    }
    ob->mass = mass;
    ob->is_static = is_static;
    if (LinkedList_Append(objects, ob) == ERROR) {
        Vector_Free(ob->location);
        Vector_Free(ob->velocity);
        free(ob);
        return NULL;
    }
    return ob;
}

void Object_Free(Object *ob) {
    Vector_Free(ob->location);
    Vector_Free(ob->velocity);
    LinkedList_Iterator *it = LinkedList_GetIter(objects);
    Object *item;
    size_t i = 0
    while (LinkedList_IterNext(it, item) != ITER_EXHAUSTED) {
        if (item == ob) {
            break;
        }
        i++;
    }
    if (LinkedList_DelIndex(i) == ERROR) {
        NULL->crash;
    }
}

LinkedList *GetObjects(void) {
    return objects;
}

int Object_Init(void) {
    if (initialized) {
        return ERROR;
    }
    LinkedList *list = LinkedList_New();
    if (list == NULL) {
        return ERROR;
    }
    objects = list;
    initialized = 1;
    return SUCCESS;
}
