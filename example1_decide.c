#include <stdio.h>
#include "decide.h"

int main(void){
    // Set up a the problem in example 1 in the document
     CONNECTORS aLCM[15][15];
    int i,j;
    for (i=0; i<numberLICs; i++) 
	{
        for (j=0; j<numberLICs; j++) 
	    {
            aLCM[i][j]=NOTUSED;
        }
    }
    aLCM[0][0]=ANDD;
    aLCM[0][1]=ANDD;
    aLCM[0][2]=ORR;
    aLCM[0][3]=ANDD;

    aLCM[1][0]=ANDD;
    aLCM[1][1]=ANDD;
    aLCM[1][2]=ORR;
    aLCM[1][3]=ORR;

    aLCM[2][0]=ORR;
    aLCM[2][1]=ORR;
    aLCM[2][2]=ANDD;
    aLCM[2][3]=ANDD;

    aLCM[3][0]=ANDD;
    aLCM[3][1]=ORR;
    aLCM[3][2]=ANDD;
    aLCM[3][3]=ANDD;

    CONNECTORS *aux[numberLICs];
    LCM = (CONNECTORS **) aux;
    for(i=0;i<numberLICs;i++) aux[i] = (CONNECTORS *) aLCM + i*numberLICs;

    printf("--- LCM ---\n");
     for (i=0; i<numberLICs; i++) 
	{
		for (j=0; j<numberLICs; j++) 
		{
			printf("%i", LCM[i][j]);
		}
        printf("\n");
	}

    PARAMETERS.LENGTH1=1;   // Length in LICs 0, 7, 12 // DOESNT LAUNCH WHEN 2
    PARAMETERS.RADIUS1=1;   // Radius in LICs 1, 8, 13
    PARAMETERS.EPSILON=1;   // Deviation from PI in LICs 2, 9
    PARAMETERS.AREA1=1;     // Area in LICs 3, 10, 14 // DOESNT LAUNCH WHEN 1
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

     NUMPOINTS = 10;
    double X[NUMPOINTS];
    X[0]=1;
    X[1]=1;
    X[2]=2;
    X[3]=3;
    X[4]=3;
    X[5]=3;
    X[6]=3;
    X[7]=2;
    X[8]=2;
    X[9]=2;
    POINTS.X = X;

    double Y[NUMPOINTS];
    Y[0]=3;
    Y[1]=2;
    Y[2]=1;
    Y[3]=1;
    Y[4]=1;
    Y[5]=2;
    Y[6]=1;
    Y[7]=2;
    Y[8]=1;
    Y[9]=1;
    POINTS.Y = Y;

    boolean aCMV[numberLICs];
    CMV = aCMV;

    boolean aPUM[numberLICs][numberLICs];
    boolean *aux2[numberLICs];
    PUM = (boolean **) aux2;
    for(i=0;i<numberLICs;i++) aux2[i] = (boolean *) aPUM + i*numberLICs;

    boolean aPUV[numberLICs];
    aPUV[0]=1;
    aPUV[1]=0;
    aPUV[2]=1;
    aPUV[2]=0;
    aPUV[3]=0;
    aPUV[4]=0;
    aPUV[5]=0;
    aPUV[6]=0;
    aPUV[7]=0;
    aPUV[8]=0;
    aPUV[9]=0;
    aPUV[10]=0;
    aPUV[11]=0;
    aPUV[12]=0;
    aPUV[13]=0;
    aPUV[14]=0;
    PUV = aPUV;

    DECIDE();

    printf("test");
    return 0;
}