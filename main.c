#include <math.h>

#include "nlt.h"

unsigned long long id = 0;

#define OP_WITH_FREE(or, expr) \
Vector *temp##id = or; \
expr; \
Vector_Free(temp##id); \
id++; \
do {} while (0)

const double G = 6.67408e-11;
Object *mars;
Object *phobos;
Object *deimos;
const Vector *UNIT_X;

int init_model(void) {
    mars = Object_New(0, 0, 0, 0, 6.41693e23, , 1);
    if (mars == NULL) {
        return ERROR;
    }
    phobos = Object_New(0, 9377.2e3, 2137.08977, 0, 10.6e15, 0);
    if (phobos == NULL) {
        return ERROR;
    }
    deimos = Object_New(0, -23460e3, -1351.124444, 0, 1.4762e15, 0);
    if (deimos == NULL) {
        return ERROR;
    }
    
    UNIT_X = Vector_New(1, 0);
    if (UNIT_X == NULL) {
        return ERROR;
    }
    
    return SUCCESS;
}

int iteration(void) {
        double dist_pd = Vector_Size(Vector_Sub(phobos, deimos));
        
        double Fg_md = (G* mars->mass* deimos->mass)/  pow(Vector_Size(deimos->location), 2);
        double Fg_mp = (G* mars->mass* phobos->mass)/  pow(Vector_Size(phobos->location), 2);
        double Fg_pd = (G * phobos->mass * deimos->mass) / pow(dist_pd, 2);
        
        Vector *Fgv_md = Vector_FromSize(Vector_Angle(deimos, UNIT_X), Fg_md);
        Vector *Fgv_mp = Vector_FromSize(Vector_Angle(phobos, UNIT_X), Fg_mp);
        Vector *Fgv_pd = Vector_FromSize(Vector_Angle(Vector_Sub(phobos, deimos), UNIT_X), Fg_pd);
        Vector *Fgv_dp = Vector_FromSize(Vector_Angle(Vector_Sub(deimos, phobos), UNIT_X), Fg_pd);
        
        Vector *Fres_phobos = Vector_Add(Fgv_mp, Fgv_dp);
        Vector *Fres_deimos = Vector_Add(Fgv_md, Fgv_pd);
        Vector_Free(Fgv_md);
        Vector_Free(Fgv_mp);
        Vector_Free(Fgv_pd);
        Vector_Free(Fgv_dp);
        
        Vector *a_p = Vector_Mul(Fres_phobos, 1/phobos->mass);
        Vector *a_d = Vector_Mul(Fres_deimos, 1/deimos->mass);
        Vector_Free(Fres_phobos);
        Vector_Free(Fres_deimos);
        
        OP_WITH_FREE(phobos->velocity, Vector_Add(phobos->velocity, Vector_Mul(a_p, dt)));
        OP_WITH_FREE(deimos->velocity, Vector_Add(deimos->velocity, Vector_Mul(a_d, dt)));
 
        OP_WITH_FREE(phobos->location, Vector_Add(phobos->location, Vector_Mul(phobos->velocity, dt)));
        OP_WITH_FREE(deimos->location, Vector_Add(deimos->location, Vector_Mul(deimos->velocity, dt)));
    return SUCCESS;
}
