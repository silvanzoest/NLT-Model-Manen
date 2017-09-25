#include <math.h>

#include "nlt.h"

const double G = 6.67408e-11;

int main(void) {
    Object_Init();
    Object *mars = Object_New(0, 0, 0, 0, 6.41693e23, , 1);
    Object *phobos = Object_New(0, 9377.2e3, 2137.08977, 0, 10.6e15, 0);
    Object *deimos = Object_New(0, -23460e3, -1351.124444, 0, 1.4762e15, 0);
    while (1) {
        double Fg_md = (G* mars->mass* deimos->mass)/  pow(Vector_Size(deimos->location), 2);
        double Fg_mp = (G* mars->mass* phobos->mass)/  pow(Vector_Size(phobos->location), 2);
    }
}
