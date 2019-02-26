#include <math.h>

// LATER DEMONSTRATE  SOME REFACTORING
/*
...
*/

typedef enum { LT=1111,EQ,GT} COMPTYPE;

// compares floating point numbers -- see Nonfunctional Requirements
static inline
COMPTYPE DOUBLECOMPARE(double A, double B)
{
    if (fabs(A-B)<0.000001) return EQ;
    if (A<B) return LT;
    return GT;
}

// function I will write
void DECIDE(void);