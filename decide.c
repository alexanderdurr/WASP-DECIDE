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

/*
Helper function to determine if a set of 3 points is outside of a circle of radius Radius
*/
boolean circle(double X1,double X2,double X3,double Y1,double Y2,double Y3,double Radius)
{
 	double angle12, angle23, angle13;
	double side12 = sqrt(pow(X1 - X2,2)+pow(Y1 - Y2,2));
	double side23 = sqrt(pow(X2 - X3,2)+pow(Y2 - Y3,2));
	double side13 = sqrt(pow(X1 - X3,2)+pow(Y1 - Y3,2));
	if(DOUBLECOMPARE(side12, Radius*2) == GT)
	{
		return 1;
	}
	if(DOUBLECOMPARE(side23, Radius*2) == GT)
	{
		return 1;
	}
	if(DOUBLECOMPARE(side13, Radius*2) == GT)
	{
		return 1;
	}
	if((DOUBLECOMPARE(side13, 0) == EQ)||(DOUBLECOMPARE(side12, 0) == EQ)||(DOUBLECOMPARE(side23, 0) == EQ))
	{
		return 0;
	}
	double temp = ((pow(side23,2) + pow(side13,2) - pow(side12,2)) / (2*side23*side13));
	if(DOUBLECOMPARE(temp, 1.0) == EQ)
	{
		angle12 = acos(1.0);
	}
	else if(DOUBLECOMPARE(temp, -1.0) == EQ)
	{
		angle12 = acos(-1.0);
	}
	else
	{
		angle12 = acos(temp);
	}
	temp = ((pow(side12,2) + pow(side13,2) - pow(side23,2)) / (2*side12*side13));
	if(DOUBLECOMPARE(temp, 1.0) == EQ)
	{
		angle23 = acos(1.0);
	}
	else if(DOUBLECOMPARE(temp, -1.0) == EQ)
	{
		angle23 = acos(-1.0);
	}
	else
	{
		angle23 = acos(temp);
	}
	angle13 = 3.1415926535 - (angle12+angle23); 
	if((DOUBLECOMPARE(angle13, 3.1415926535/2) == GT) ||(DOUBLECOMPARE(angle13, 3.1415926535/2) == EQ))
	{
		return 0;
	}
	else if((DOUBLECOMPARE(angle23, 3.1415926535/2) == GT) ||(DOUBLECOMPARE(angle23, 3.1415926535/2) == EQ))
	{
		return 0;
	}
	else if((DOUBLECOMPARE(angle12, 3.1415926535/2) == GT) ||(DOUBLECOMPARE(angle12, 3.1415926535/2) == EQ))
	{
		return 0;
	}
	else
	{
		circumRadius = (side12*side23*side13)/sqrt((side12+side23+side13)*(side13+side23-side12)*(side12+side13-side23)*(side12+side23-side13));
		if(DOUBLECOMPARE(0, Radius) == GT)
		{
			return 1;
		}
	}
	return 0;
}

/*
There exists at least one set of two data points, (X[i],Y[i]) and (X[j],Y[j]), separated by
exactly G PTS consecutive intervening points, such that X[j] - X[i] < 0. (where i < j ) The
condition is not met when NUMPOINTS < 3.
1 ≤ G PTS ≤ NUMPOINTS−2
*/
boolean LIC_11()
{
	if (NUMPOINTS < 3)
	{
		return 0;
	}
	int i;
	for (i=0; i < (NUMPOINTS-2); i++)
	{
		if (DOUBLECOMPARE((X[i+PARAMETERS.G_PTS+1]-X[i]), 0) == LT)
		{
			return 1;
		}
	}
	return 0;
}

/*
There exists at least one set of two data points, separated by exactly K PTS consecutive
intervening points, which are a distance greater than the length, LENGTH1, apart. In addition, there exists at least one set of two data points (which can be the same or different from
the two data points just mentioned), separated by exactly K PTS consecutive intervening
points, that are a distance less than the length, LENGTH2, apart. Both parts must be true
for the LIC to be true. The condition is not met when NUMPOINTS < 3.
0 ≤ LENGTH2
*/
boolean LIC_12() 
{
	double distance;
	boolean marker1 = 0;
	boolean marker2 = 0;
	if(NUMPOINTS < 3)
	{
		return 0;
	}
	int i;
	for(i=0; i < (NUMPOINTS - PARAMETERS.K_PTS - 1); i++)
	{	
		distance = sqrt(pow(X[i+PARAMETERS.K_PTS + 1] - X[i],2)+pow(Y[i+PARAMETERS.K_PTS + 1] - Y[i],2));
		if(DOUBLECOMPARE(distance, PARAMETERS.LENGTH1) == GT)
		{
			marker1 = 1;
		}
		if(DOUBLECOMPARE(distance, PARAMETERS.LENGTH2) == LT)
		{
			marker2 = 1;
		}
		if((marker1 == 1) && (marker2 == 1))
		{
			return 1;
		}
	}
	return 0;	
}

/*
There exists at least one set of three data points, separated by exactly A PTS and B PTS
consecutive intervening points, respectively, that cannot be contained within or on a circle of
radius RADIUS1. In addition, there exists at least one set of three data points (which can be
the same or different from the three data points just mentioned) separated by exactly A PTS
and B PTS consecutive intervening points, respectively, that can be contained in or on a
circle of radius RADIUS2. Both parts must be true for the LIC to be true. The condition is
not met when NUMPOINTS < 5.
0 ≤ RADIUS2
*/
boolean LIC_13() 
{
	if(NUMPOINTS < 5)
	{
		return 0;
	}
	int i;
	boolean marker1 = 0;
	boolean marker2 = 0;
	for(i = 0; i < (NUMPOINTS - (PARAMETERS.A_PTS + PARAMETERS.B_PTS) - 2); i++)
	{	
		if ((marker1 != 1) && (circle(X[i],X[i + PARAMETERS.A_PTS + 1],X[i + PARAMETERS.A_PTS + PARAMETERS.B_PTS + 2],Y[i],Y[i + PARAMETERS.A_PTS + 1],Y[i + PARAMETERS.B_PTS + PARAMETERS.A_PTS + 2],PARAMETERS.RADIUS1) == 1))
		{
			marker1 = 1;	
		}
		if ((marker2 != 1) && (circle(X[i],X[i + PARAMETERS.A_PTS + 1],X[i + PARAMETERS.A_PTS + PARAMETERS.B_PTS + 2],Y[i],Y[i + PARAMETERS.A_PTS + 1],Y[i + PARAMETERS.B_PTS + PARAMETERS.A_PTS + 2],PARAMETERS.RADIUS2) == 0))
		{
			marker2 = 1;
		}
		if((marker1 == 1) && (marker2 == 1))
		{
			return 1;
		}
	}
	return 0;
}

/*
There exists at least one set of three consecutive data points that cannot all be contained
within or on a circle of radius RADIUS1.
(0 ≤ RADIUS1)
*/
boolean LIC_1()
{ 
  	int i;
	for (i=0; i < (NUMPOINTS-2); i++) 
	{
		if(circle( X[i],X[i+1],X[i+2],Y[i],Y[i+1],Y[i+2],PARAMETERS.RADIUS1) == 1)
		{
			return 1;
		}
		
	}
	return 0;
}

/*
There exists at least one set of N PTS consecutive data points such that at least one of the
points lies a distance greater than DIST from the line joining the first and last of these N PTS
points. If the first and last points of these N PTS are identical, then the calculated distance
to compare with DIST will be the distance from the coincident point to all other points of
the N PTS consecutive points. The condition is not met when NUMPOINTS < 3.
(3 ≤ N PTS ≤ NUMPOINTS), (0 ≤ DIST)
*/
boolean LIC_6() 
{
	if(NUMPOINTS < 3)
	{
		return 0;
	}
	int i;
	for (i=0; i <= NUMPOINTS-PARAMETERS.N_PTS; i++) 
	{
		int innerpoint;
		for (innerpoint=0; innerpoint < (PARAMETERS.N_PTS-2); innerpoint++) 
		{
	    		side12 = sqrt(pow(X[i] - X[i+PARAMETERS.N_PTS-1],2)+pow(Y[i] - Y[i+PARAMETERS.N_PTS-1],2)); //distance formula
	    		side23 = sqrt(pow(X[i+PARAMETERS.N_PTS-1] - X[i+innerpoint+1],2)+pow(Y[i+PARAMETERS.N_PTS-1] - Y[i+innerpoint+1],2));
	    		side13 = sqrt(pow(X[i] - X[i+innerpoint+1],2)+pow(Y[i] - Y[i+innerpoint+1],2));
			if(DOUBLECOMPARE(side12, 0) == EQ)
			{
				if(DOUBLECOMPARE(side23, PARAMETERS.DIST) == GT)
				{
					return 1;
				}
				else
				{
					continue;
				}
			}
			if((DOUBLECOMPARE(side13, 0) == EQ) ||(DOUBLECOMPARE(side23, 0) == EQ))
			{
				continue;
			}
			double temp = ((pow(side23,2) + pow(side13,2) - pow(side12,2)) / (2*side23*side13));
			if(DOUBLECOMPARE(temp, 1.0) == EQ)
			{
				angle12 = acos(1.0);
			}
			else if(DOUBLECOMPARE(temp, -1.0) == EQ)
			{
				angle12 = acos(-1.0);
			}
			else
			{
				angle12 = acos(temp);
			}
			temp = ((pow(side12,2) + pow(side13,2) - pow(side23,2)) / (2*side12*side13));
			if(DOUBLECOMPARE(temp, 1.0) == EQ)
			{
				angle23 = acos(1.0);
			}
			else if(DOUBLECOMPARE(temp, -1.0) == EQ)
			{
				angle23 = acos(-1.0);
			}
			else
			{
				angle23 = acos(temp);
			}
			angle13 = 3.1415926535 - (angle12+angle23);
			if((DOUBLECOMPARE(angle13, 3.1415926535/2) == GT) ||(DOUBLECOMPARE(angle13, 3.1415926535/2) == EQ))
			{
				if(DOUBLECOMPARE(sin(3.1415926535 - angle13)*side23, PARAMETERS.DIST) == GT)
				{
					return 1;
				}
				else
				{
					continue;
				}
			}
			else if((DOUBLECOMPARE(angle23, 3.1415926535/2) == GT) ||(DOUBLECOMPARE(angle23, 3.1415926535/2) == EQ))
			{
				if(DOUBLECOMPARE(sin(3.1415926535 - angle23)*side13, PARAMETERS.DIST) == GT)
				{
					return 1;
				}
				else
				{
					continue;
				}
			}			
			if(DOUBLECOMPARE(side13*sin(angle23), PARAMETERS.DIST) == GT)
			{
				return 1;
			}
		}
	}
	return 0;
}

/*
Helper function to determine if 3 points have an angle not within pi +- epsilon
*/
boolean Angle(double X1,double X2,double X3,double Y1,double Y2,double Y3, double Epsilon)
{
	double side12 = sqrt(pow(X1 - X2,2)+pow(Y1 - Y2,2));
	double side23 = sqrt(pow(X2 - X3,2)+pow(Y2 - Y3,2));
	double side13 = sqrt(pow(X1 - X3,2)+pow(Y1 - Y3,2));
	if((DOUBLECOMPARE(side12, 0) == EQ)||(DOUBLECOMPARE(side23, 0) == EQ))
	{
		return 0;
	}
	double temp = ((pow(side23,2) + pow(side12,2) - pow(side13,2)) / (2*side23*side12));
	if(DOUBLECOMPARE(temp, 1.0) == EQ)
	{
		angle13 = acos(1.0);
	}
	else if(DOUBLECOMPARE(temp, -1.0) == EQ)
	{
		angle13 = acos(-1.0);
	}
	else
	{
		angle13 = acos(temp);
	}		
	if((DOUBLECOMPARE(angle13, (3.1415926535 + Epsilon)) == GT) ||(DOUBLECOMPARE(angle13, (3.1415926535 - Epsilon)) == LT))
	{
		return 1;
	}
	return 0;
}

/*
There exists at least one set of three consecutive data points which form an angle such that:
angle < (PI−EPSILON)
or
angle > (PI+EPSILON)
The second of the three consecutive points is always the vertex of the angle. If either the first
point or the last point (or both) coincides with the vertex, the angle is undefined and the LIC
is not satisfied by those three points.
(0 ≤ EPSILON < PI)
*/
boolean LIC_2() 
{
	int i;
	for (i=0; i < (NUMPOINTS-2); i++) 
	{
		if(Angle(X[i], X[i+1], X[i+2], Y[i], Y[i+1], Y[i+2], PARAMETERS.EPSILON) == 1)
		{
			return 1;
		}
	}
	return 0;
}

/*
There exists at least one set of three data points separated by exactly C PTS and D PTS
consecutive intervening points, respectively, that form an angle such that:
angle < (PI−EPSILON)
or
angle > (PI+EPSILON)
The second point of the set of three points is always the vertex of the angle. If either the first
point or the last point (or both) coincide with the vertex, the angle is undefined and the LIC
is not satisfied by those three points. When NUMPOINTS < 5, the condition is not met.
1 ≤ C PTS, 1 ≤ D PTS
C PTS+D PTS ≤ NUMPOINTS−3
*/
boolean LIC_9()
{
	if (NUMPOINTS < 5)
	{
		return 0;
	}
	int i;
	for (i=0; i < NUMPOINTS-(PARAMETERS.C_PTS + PARAMETERS.D_PTS)-2; i++)
	{
		if (Angle( X[i], X[i + PARAMETERS.C_PTS + 1],  X[i + PARAMETERS.C_PTS + PARAMETERS.D_PTS + 2], Y[i], Y[i + PARAMETERS.C_PTS + 1], Y[i + PARAMETERS.C_PTS + PARAMETERS.D_PTS + 2], PARAMETERS.EPSILON) == 1)
		{
			return 1;
		}
	}
	return 0;
}

/*
Helper function to determine if area of triangle is greater than Area
*/
boolean Area(double X1,double X2,double X3,double Y1,double Y2,double Y3,double Area)
{
	double sida12 = sqrt(pow(X1 - X2,2)+pow(Y1 - Y2,2));
	double sida23 = sqrt(pow(X2 - X3,2)+pow(Y2 - Y3,2));
	double sida13 = sqrt(pow(X1 - X3,2)+pow(Y1 - Y3,2));
	double temp = (((sida12+sida23+sida13)/2)*(((sida12+sida23+sida13)/2)-sida12)*(((sida12+sida23+sida13)/2)-sida23)*(((sida12+sida23+sida13)/2)-sida13));
	if((DOUBLECOMPARE(temp, -0) == EQ))
	{
		temp = 0;
	}
	double area = sqrt(temp);
	if((DOUBLECOMPARE(((sida12+sida23+sida13)/2), sida23) == EQ)||(DOUBLECOMPARE(((sida12+sida23+sida13)/2), sida12) == EQ)||(DOUBLECOMPARE(((sida12+sida23+sida13)/2), sida13) == EQ))//This is a flat line since have the perimeter is the same size as one side
	{
		double area2 = (X1*(Y2-Y3))+(X2*(Y3-Y1))+(X3*(Y1-Y2));
		area2 = area2*area2;
		area2 = sqrt(area2);
		area2 = .5*area2;
		if(DOUBLECOMPARE(area2, Area) == GT)
		{
			return 1;
		}
		return 0;
	}
	if(DOUBLECOMPARE(area, Area) == GT)
	{
		return 1;
	}
	return 0;
} 

/*
There exists at least one set of three consecutive data points that are the vertices of a triangle
with area greater than AREA1.
(0 ≤ AREA1)
*/
boolean LIC_3() 
{
	int i;
	for (i=0; i < (NUMPOINTS-2); i++) 
	{
		if(Area(X[i],X[i+1],X[i+2],Y[i],Y[i+1],Y[i+2],PARAMETERS.AREA1) == 1)
		{
			return 1;
		}
	}
	return 0;
}
