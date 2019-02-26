#include "decide.h"

typedef int boolean;

// declare LICs
boolean LIC_0();
boolean LIC_1();
boolean LIC_2();
boolean LIC_3();
boolean LIC_4();
boolean LIC_5();
boolean LIC_6();
boolean LIC_7();
boolean LIC_8();
boolean LIC_9();
boolean LIC_10();
boolean LIC_11();
boolean LIC_12();
boolean LIC_13();
boolean LIC_15();

void DECIDE(void)
{
    
}

//There exists at least one set of two consecutive data points that are a distance greater than the length LENGTH1 apart
//See description pdf page 3
boolean LIC_0()
{
    int i;
    double distance;
    for(i=0; i<(NUMPOINTS-1); i++)
    {
        distance=sqrt(pow(X[i]-X[i+1],2)+pow(Y[i]-Y[i+1],2));
        if (DOUBLECOMPARE(distance, PARAMETERS.LENGTH1)==GT)
        {
            return 1; // distance between two points is greater than LENGTH1 (which means the object is fast, indicating a rocket)
        }
    }
    return 0; // distance between two points smaller than LENGTH1
}