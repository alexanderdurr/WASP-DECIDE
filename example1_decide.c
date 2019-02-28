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

    DECIDE();

    printf("test");
    return 0;
}