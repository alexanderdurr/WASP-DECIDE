#include <stdio.h>
#include "decide.h"

int numberLICs = 15;

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
boolean LIC_14();

boolean Area(double X1, double X2, double X3, double Y1, double Y2, double Y3, double Area);
boolean Circle(double X1, double X2, double X3, double Y1, double Y2, double Y3, double Radius);
boolean Angle(double X1, double X2, double X3, double Y1, double Y2, double Y3, double Epsilon);
double euclideanDistance(double deltaX, double deltaY);

int main(void){

    PARAMETERS.LENGTH1=1;   // Length in LICs 0, 7, 12 // DOESNT LAUNCH WHEN 2, LAUNCHES WHEN 1 <-----------------------------------EXPERIMENT HERE-----------------------------------
    PARAMETERS.RADIUS1=1;   // Radius in LICs 1, 8, 13
    PARAMETERS.EPSILON=1;   // Deviation from PI in LICs 2, 9
    PARAMETERS.AREA1=1;     // Area in LICs 3, 10, 14 // DOESNT LAUNCH WHEN 1, LAUNCHES WHEN 0.1 <------------------------------------EXPERIMENT HERE-----------------------------------
    PARAMETERS.Q_PTS=1;        // No. of consecutive points in LIC 4
    PARAMETERS.QUADS=1;        // No. of quadrants in LIC 4
    PARAMETERS.DIST=1;      // Distance in LIC 6 
    PARAMETERS.N_PTS=1;        // No. of consecutive pts. in LIC 6
    PARAMETERS.K_PTS=1;        // No. of int. pts. in LICs 7, 12
    PARAMETERS.A_PTS=1;        // No. of int. pts. in LICs 8, 13
    PARAMETERS.B_PTS=1;        // No. of int. pts. in LICs 8, 13
    PARAMETERS.C_PTS=1;        // No. of int. pts. in LIC 9
    PARAMETERS.D_PTS=1;        // No. of int. pts. in LIC 9
    PARAMETERS.E_PTS=1;        // No. of int. pts. in LICs 10, 14
    PARAMETERS.F_PTS=1;        // No. of int. pts. in LICs 10, 14
    PARAMETERS.G_PTS=1;        // No. of int. pts. in LIC 11
    PARAMETERS.LENGTH2=1;   // Maximum length in LIC 12
    PARAMETERS.RADIUS2=1;   // Maximum radius in LIC 13
    PARAMETERS.AREA2=1;     // Maximum area in LIC 14

    NUMPOINTS = 5;
    double X[NUMPOINTS];
    double Y[NUMPOINTS];
    boolean temp;
    boolean oracle;

    //LIC_0
    printf("--- LIC_0 ---\n");
    // Test Case 1
    // Distance between every consecutive pair is equal to 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.LENGTH1=2; // Allowed distance is in (0,2)
    temp = LIC_0();
    oracle = 0; // false
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    // Distance between every consecutive pair is equal to 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.LENGTH1=0.1; // Allowed distance is in (0,0.1)
    temp = LIC_0();
    oracle = 1; // true
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_1
    printf("--- LIC_1 ---\n");
    // Test Case 1
    // Points in a line
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.RADIUS1=1; // Points must be in circle with radius 1
    temp = LIC_1();
    oracle = 0; // false, because the first and last point in the set of three are 2 apart = diameter
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    // Points in a line
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.RADIUS1=0.5; // Points must be in circle with radius 0.5
    temp = LIC_1();
    oracle = 1;  // true, because the first and last point in the set of three are 2 apart, which is bigger than the diameter
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

     //LIC_2
    printf("--- LIC_2 ---\n");
    // Test Case 1
    // Points in a line
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.EPSILON=1;
    temp = LIC_2();
    oracle = 0; // false, because the angle is zero
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    // Points in a unit square
    X[0]=0;
    X[1]=1;
    X[2]=1;
    X[3]=0;
    X[4]=0;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=1;
    Y[3]=1;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.EPSILON=1;
    temp = LIC_2();
    oracle = 1;  // true, because the angle between 3 points in a unit circle is 90 degrees which is less than pi-1
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

     //LIC_3
    printf("--- LIC_3 ---\n");
    // Test Case 1
    // Points in a line
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.AREA1=0.1; 
    temp = LIC_3();
    oracle = 0; // false, because the area is zero
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    // Points in a unit square
    X[0]=0;
    X[1]=1;
    X[2]=1;
    X[3]=0;
    X[4]=0;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=1;
    Y[3]=1;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.AREA1=0.1; 
    temp = LIC_3();
    oracle = 1;  // true, because the area is 0.5 
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_4
    printf("--- LIC_4 ---\n");
    // Test Case 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.Q_PTS=2;
    PARAMETERS.QUADS=1; 
    temp = LIC_4();
    oracle = 0; // false, because all are in quadrant I
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    X[0]=0; // quadrant 1
    X[1]=-1; // quadrant 2
    X[2]=0; // quadrant 3
    X[3]=0;
    X[4]=0;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=-1;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.Q_PTS=2;
    PARAMETERS.QUADS=1; 
    temp = LIC_4();
    oracle = 1;  // true, because 2 consecutive points lie in more than 1 quadrant
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_5
    printf("--- LIC_5 ---\n");
    // Test Case 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    temp = LIC_5();
    oracle = 0; // false, because X[j] - X[j-1] > 0
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    X[0]=0;
    X[1]=1;
    X[2]=0; // one step back
    X[3]=0;
    X[4]=0;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    temp = LIC_5();
    oracle = 1;  // true, because X[j] - X[j-1] < 0
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_6
    printf("--- LIC_6 ---\n");
    // Test Case 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.DIST=1;
    PARAMETERS.N_PTS=3; 
    temp = LIC_6();
    oracle = 0; // false, all points have a distance of 1 to the first and the last point in the set
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=10; // distance to first an last point of set is larger than 1
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.DIST=1;
    PARAMETERS.N_PTS=3; 
    temp = LIC_6();
    oracle = 1;  // true, because POINT(1)-POINT(0) > 1
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_7
    printf("--- LIC_7 ---\n");
    // Test Case 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.LENGTH1=2;
     PARAMETERS.K_PTS=1;
    temp = LIC_7();
    oracle = 0; // false, because in a set of three the first and last point on this line are 2 apart
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.LENGTH1=1;
     PARAMETERS.K_PTS=1;
    temp = LIC_7();
    oracle = 1;  // true, because the first and last point are 2 apart > 1
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

     //LIC_8
    printf("--- LIC_8 ---\n");
    // Test Case 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.RADIUS1=2;
    PARAMETERS.A_PTS=1;   
    PARAMETERS.B_PTS=1;
    temp = LIC_8();
    oracle = 0; // false, because the first and last point are 4 apart, which is the diameter of a circle with radius1=2
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.RADIUS1=1;
    PARAMETERS.A_PTS=1;   
    PARAMETERS.B_PTS=1;
    temp = LIC_8();
    oracle = 1;  // true, because first and last point are 4 apart which is greater than diameter of a circle of radius1 =1 
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_9
    printf("--- LIC_9 ---\n");
    // Test Case 1
    // Points in a line
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.EPSILON=1;
    PARAMETERS.C_PTS=1;       
    PARAMETERS.D_PTS=1;
    temp = LIC_9();
    oracle = 0; // false, because the angle is zero
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    // Points in a 90 degree angle at the middle point
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=1;
    X[4]=1;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=1;
    Y[4]=2;
    POINTS.Y = Y;
    PARAMETERS.EPSILON=1;
    PARAMETERS.C_PTS=1;       
    PARAMETERS.D_PTS=1;
    temp = LIC_9();
    oracle = 1;  // true, because the angle between first middle and last point is 90 degrees which is less than pi-1
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_10
    printf("--- LIC_10 ---\n");
    // Test Case 1
    // Points in a line
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.AREA1=1;
    PARAMETERS.E_PTS=1;   
    PARAMETERS.F_PTS=1;
    temp = LIC_10();
    oracle = 0; // false, because the angle is zero
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    // Points in a 90 degree angle at the middle point
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=1;
    X[4]=1;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=1;
    Y[4]=2;
    POINTS.Y = Y;
    PARAMETERS.AREA1=1;
    PARAMETERS.E_PTS=1;       
    PARAMETERS.F_PTS=1;
    temp = LIC_10();
    oracle = 1;  // true, because the area of the triangle is 2 which is bigger than AREA1
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_11
    printf("--- LIC_11 ---\n");
    // Test Case 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.G_PTS=1;
    temp = LIC_11();
    oracle = 0; // false, because X[j] - X[i] > 0 for all i < j
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    X[0]=0;
    X[1]=0;
    X[2]=1; 
    X[3]=1;
    X[4]=0; // one step back compared to middle
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.G_PTS=1;
    temp = LIC_11();
    oracle = 1;  // true, because X[4] - X[2] < 0
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_12
    printf("--- LIC_12 ---\n");
    // Test Case 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.LENGTH1=2;
    PARAMETERS.LENGTH2=10;
     PARAMETERS.K_PTS=1;
    temp = LIC_12();
    oracle = 0; // false, because in a set of three the first and last point on this line are 2 apart (false for length1), but also they are smaller thatn length2
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=2.1;
    X[4]=2.2;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.LENGTH1=1;
    PARAMETERS.LENGTH2=0.5;
     PARAMETERS.K_PTS=1;
    temp = LIC_12();
    oracle = 1;  // true, because the first and last point in a set of three (POINT(0), POINT(3)) are 2 apart > LENGTH1 and the first and the last in a set of three are 0.2 apart < LENGTH2
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_13
    printf("--- LIC_13 ---\n");
    // Test Case 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.RADIUS1=2;
    PARAMETERS.RADIUS2=1; 
    PARAMETERS.A_PTS=1;   
    PARAMETERS.B_PTS=1;
    temp = LIC_13();
    oracle = 0; // false, because the first and last point are 4 apart, which is the diameter of a circle with radius1=2, the second condition for Radius2 is true, but both must be true
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.RADIUS1=1;
    PARAMETERS.RADIUS2=10; 
    PARAMETERS.A_PTS=1;   
    PARAMETERS.B_PTS=1;
    temp = LIC_13();
    oracle = 1;  // true, because first and last point are 4 apart which is greater than diameter of a circle of radius1 =1 and the second condition is fulfilled since they are also contained in a circle of radius2=10
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //LIC_14
    printf("--- LIC_14 ---\n");
    // Test Case 1
    // Points in a line
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.AREA1=1;
    PARAMETERS.AREA2=2;
    PARAMETERS.E_PTS=1;   
    PARAMETERS.F_PTS=1;
    temp = LIC_14();
    oracle = 0; // false, because the angle is zero
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    // Points in a 90 degree angle at the middle point
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=1;
    X[4]=1;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=1;
    Y[4]=2;
    POINTS.Y = Y;
    PARAMETERS.AREA1=1;
    PARAMETERS.AREA2=2;
    PARAMETERS.E_PTS=1;       
    PARAMETERS.F_PTS=1;
    temp = LIC_14();
    oracle = 1;  // true, because the area of the triangle is 2 which is bigger than AREA1
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

     //Area
    printf("--- Area ---\n");
    // Test Case 1
    // Points in a line
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.AREA1=1;
    temp = Area( X[0],  X[2],  X[4],  Y[0],  Y[2],  Y[4],  PARAMETERS.AREA1);
    oracle = 0; // false, because the area is zero
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    // Points in a 90 degree angle at the middle point
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=1;
    X[4]=1;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=1;
    Y[4]=2;
    POINTS.Y = Y;
    PARAMETERS.AREA1=1;
    temp = Area( X[0],  X[2],  X[4],  Y[0],  Y[2],  Y[4],  PARAMETERS.AREA1);
    oracle = 1;  // true, because the area of the triangle is 2 which is bigger than AREA1
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //Circle
    printf("--- Circle ---\n");
    // Test Case 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.RADIUS1=2;
    temp = Circle( X[0],  X[2],  X[4],  Y[0],  Y[2],  Y[4],  PARAMETERS.RADIUS1);
    oracle = 0; // false, because the first and last point are 4 apart, which is the diameter of a circle with radius1=2
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.RADIUS1=1;
    temp = Circle( X[0],  X[2],  X[4],  Y[0],  Y[2],  Y[4],  PARAMETERS.RADIUS1);
    oracle = 1;  // true, because first and last point are 4 apart which is greater than diameter of a circle of radius1 =1
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    //Angle
    printf("--- Angle ---\n");
    // Test Case 1
    // Points in a line
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    PARAMETERS.EPSILON=1;
    temp = Angle( X[0],  X[2],  X[4],  Y[0],  Y[2],  Y[4],  PARAMETERS.EPSILON);
    oracle = 0; // false, because the angle is zero
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    // Points in a 90 degree angle at the middle point
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=1;
    X[4]=1;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=1;
    Y[4]=2;
    POINTS.Y = Y;
    PARAMETERS.EPSILON=1;
    temp = Angle( X[0],  X[2],  X[4],  Y[0],  Y[2],  Y[4],  PARAMETERS.EPSILON);
    oracle = 1;  // true, because the angle between first middle and last point is 90 degrees which is less than pi-1
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

     //euclideanDistance
    printf("--- euclideanDistance ---\n");
    // Test Case 1
    // Distance between every consecutive pair is equal to 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    temp = euclideanDistance(X[1]-X[0],Y[1]-Y[0]);
    oracle = 1; //distance = 1
    if(temp==oracle)
    {
        printf("Test 1: passed\n");
    }
    else
    {
        printf("Test 1: failed\n");
    }
    // Test Case 2
    // Distance between every consecutive pair is equal to 1
    X[0]=0;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=4;
    POINTS.X = X;
    Y[0]=0;
    Y[1]=0;
    Y[2]=0;
    Y[3]=0;
    Y[4]=0;
    POINTS.Y = Y;
    temp = euclideanDistance(X[2]-X[0],Y[2]-Y[0]);
    oracle = 2; //2, because distance =2
    if(temp==oracle)
    {
        printf("Test 2: passed\n");
    }
    else
    {
        printf("Test 2: failed\n");
    }

    return 0;
}