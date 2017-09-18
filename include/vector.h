#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    double x;
    double y;
} Vector;

Vector *Vector_New(double, double);
Vector *Vector_FromSize(double, double);
double Vector_Size(Vector *);
double Vector_Dot(Vector *, Vector *);
double Vector_Angle(Vector *, Vector *);
Vector *Vector_Add(Vector *, Vector *);
Vector *Vector_Sub(Vector *, Vector *);
Vector *Vector_Mul(Vector *, long long);
// Vector *Vector_CopySign(Vector *, Vector *);

#endif /* VECTOR_H */
