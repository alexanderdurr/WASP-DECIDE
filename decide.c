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

/*
There exists at least one set of two consecutive data points that are a distance greater than
the length, LENGTH1, apart.
(0 ≤ LENGTH1)
*/
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

/*
There exists at least one set of Q PTS consecutive data points that lie in more than QUADS
quadrants. Where there is ambiguity as to which quadrant contains a given point, priority
of decision will be by quadrant number, i.e., I, II, III, IV. For example, the data point (0,0)
is in quadrant I, the point (-l,0) is in quadrant II, the point (0,-l) is in quadrant III, the point
(0,1) is in quadrant I and the point (1,0) is in quadrant I.
(2 ≤ Q PTS ≤ NUMPOINTS), (1 ≤ QUADS ≤ 3)
*/
boolean LIC_4()
{
    int i;
    for(i=0; i<=NUMPOINTS-PARAMETERS.Q_PTS; i++)
    {
        Quadrant1=0;
        Quadrant2=0;
        Quadrant3=0;
        Quadrant4=0;
        for(j=0, j<PARAMETERS.Q_PTS; j++)
        {
             if(( (DOUBLECOMPARE(X[i+j], 0) == EQ) || (DOUBLECOMPARE(X[i+j], 0) == GT) )&& ( (DOUBLECOMPARE(Y[i+j], 0) == EQ) || (DOUBLECOMPARE(Y[i+j], 0) == GT) ))
			{
				Quadrant1 = 1;
			}
			else if(( (DOUBLECOMPARE(X[i+j], 0) == LT) ) && ( (DOUBLECOMPARE(Y[i+j], 0) == EQ) || (DOUBLECOMPARE(Y[i+j], 0) == GT) ))
			{
				Quadrant2 = 1;
			}
			else if(( (DOUBLECOMPARE(X[i+j], 0) == LT) || (DOUBLECOMPARE(X[i+j], 0) == EQ) )&& ( (DOUBLECOMPARE(Y[i+j], 0) == LT) ))
			{
				Quadrant3 = 1;
			}
			else
			{
				Quadrant4 = 1;
			}
		} 
		if((Quadrant1+Quadrant2+Quadrant3+Quadrant4)>PARAMETERS.QUADS)
		{
			return 1;
		}
	}
	return 0;
} 