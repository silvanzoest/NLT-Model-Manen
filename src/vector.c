#include <math.h>
#include <stdlib.h>

#include "constants.h"
#include "vector.h"

Vector *Vector_New(double x, double y) {
    Vector *vec = malloc(sizeof(Vector));
    if (vec == NULL) {
        return NULL;
    }
    vec->x = x;
    vec->y = y;
    return vec;
}

Vector *Vector_FromSize(double angle, double size) {
    return Vector_New(cos(angle)*size, sin(angle)*size);
}

void Vector_Free(Vector *v) {
    free(v);
}

double Vector_Size(Vector *v){
    double x = v->x;
    double y = v->y;
    return sqrt(x*x + y*y);
}

double Vector_Dot(Vector *a, Vector *b) {
    return a->x * a->b + a->y * b->y;
}

double Vector_Angle(Vector *a, Vector *b) {
    double angle = acos(Vector_Dot(a)*Vector_Dot(b) / (Vector_Size(a)*Vector_Size(b));
    if (angle > pi) {
        angle = 2*pi - angle;
    }
    return angle;
}

Vector *Vector_Add(Vector *a, Vector *b) {
    return Vector_New(a->x + b->x, a->y + b->y);
}

Vector *Vector_Sub(Vector *a, Vector *b) {
    return Vector_New(a->x - b->x, a->y - b->y);
}

Vector *Vector_Mul(Vector *v, long long n){
    x = v->x;
    y = v->y;
    return Vector_New(x*n, y*n);
}

#define SIGN(x) ((int)((x) >= 0 ? 0 : 1))
Vector *Vector_CopySign(Vector *a, Vector *b) {
    return Vector_New((-1)*SIGN(a->x)*(b->x), (-1)*SIGN(a->y)*(b->y));
}
