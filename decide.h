#include <math.h>

static const double PI = 3.1415926535;

typedef int boolean;
typedef enum { LT=1111,EQ,GT} COMPTYPE;
typedef enum { NOTUSED =777, ORR, ANDD} CONNECTORS;
typedef double *COORDINATE;
typedef CONNECTORS **CMATRIX;
typedef boolean **BMATRIX;
typedef boolean *VECTOR;

// inputs
typedef struct {
  double LENGTH1;   // Length in LICs 0, 7, 12
  double RADIUS1;   // Radius in LICs 1, 8, 13
  double EPSILON;   // Deviation from PI in LICs 2, 9
  double AREA1;     // Area in LICs 3, 10, 14
  int Q_PTS;        // No. of consecutive points in LIC 4
  int QUADS;        // No. of quadrants in LIC 4
  double DIST;      // Distance in LIC 6 
  int N_PTS;        // No. of consecutive pts. in LIC 6
  int K_PTS;        // No. of int. pts. in LICs 7, 12
  int A_PTS;        // No. of int. pts. in LICs 8, 13
  int B_PTS;        // No. of int. pts. in LICs 8, 13
  int C_PTS;        // No. of int. pts. in LIC 9
  int D_PTS;        // No. of int. pts. in LIC 9
  int E_PTS;        // No. of int. pts. in LICs 10, 14
  int F_PTS;        // No. of int. pts. in LICs 10, 14
  int G_PTS;        // No. of int. pts. in LIC 11
  double LENGTH2;   // Maximum length in LIC 12
  double RADIUS2;   // Maximum radius in LIC 13
  double AREA2;     // Maximum area in LIC 14
} PARAMETERS_T;

typedef struct {
  COORDINATE X;
  COORDINATE Y;
}POINTS_T;

// declare global variables
PARAMETERS_T PARAMETERS;
POINTS_T POINTS;
int NUMPOINTS;
VECTOR CMV;
CMATRIX LCM;
BMATRIX PUM;
VECTOR PUV;
VECTOR FUV;
boolean LAUNCH;

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