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
	int Quadrant1, Quadrant2, Quadrant3, Quadrant4;
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

/*
There exists at least one set of two consecutive data points, (X[i],Y[i]) and (X[j],Y[j]), such
that X[j] - X[i] < 0. (where i = j-1)
*/
boolean LIC_5() 
{
	int j;
	for (j=1; j <= (NUMPOINTS-1); j++) 
	{
	    if (DOUBLECOMPARE(X[j] - X[j-1], 0) == LT)
	    {
	    	return 1;
	    }
	}
	return 0;
}

/*
There exists at least one set of two data points separated by exactly K PTS consecutive intervening points that are a distance greater than the length, LENGTH1, apart. The condition
is not met when NUMPOINTS < 3.
1 ≤ K PTS ≤ (NUMPOINTS−2)
*/
boolean LIC_7() 
{
	if(NUMPOINTS < 3)
	{
		return 0;
	}
	int i;
	double distance;
	for (i=0; i < NUMPOINTS-2; i++) 
	{
		distance = sqrt(pow(X[i] - X[i+PARAMETERS.K_PTS+1],2)+pow(Y[i] - Y[i+PARAMETERS.K_PTS+1],2));
		if (DOUBLECOMPARE(distance, PARAMETERS.LENGTH1) == GT) 
		{
			return 1; 
		}
	}
	return 0;
}

/*
There exists at least one set of three data points separated by exactly A PTS and B PTS
consecutive intervening points, respectively, that cannot be contained within or on a circle of
radius RADIUS1. The condition is not met when NUMPOINTS < 5.
1 ≤ A PTS, 1 ≤ B PTS
A PTS+B PTS ≤ (NUMPOINTS−3)
*/
boolean LIC_8() 
{
	if(NUMPOINTS < 5)
	{
		return 0;
	}
  	int i;
	for (i=0; i < NUMPOINTS-2- PARAMETERS.A_PTS-PARAMETERS.B_PTS; i++) 
	{
		if(circle(X[i],X[i+PARAMETERS.A_PTS+1],X[i+PARAMETERS.A_PTS+PARAMETERS.B_PTS+2],Y[i],Y[i+PARAMETERS.A_PTS+1],Y[i+PARAMETERS.A_PTS+PARAMETERS.B_PTS+2],PARAMETERS.RADIUS1) == 1)
		{
			return 1;
		}
	}
	return 0;
}