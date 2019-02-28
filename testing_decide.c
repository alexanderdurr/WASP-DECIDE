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
    X[2]=0;
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

    return 0;
}