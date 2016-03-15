/* 
        Description: The ANSI C code of the PRVNS approach
        Programmer:  Wesklei Migliorini
        E-mail:      wesklei.m@gmail.com
        Date:	     04/11/2014
        Lisence:     Free
        Note:        The system was developed using Linux.
        To compile:  Type: make
        To run: ./algorithm input.in
 */

#ifndef max
#define	max(x, y)	((x) > (y) ? (x) : (y))
#endif

#ifndef abss
#define abss(a)     (a<0 ? (-a) : a)
#endif

typedef int bool;
#define true 1
#define false 0
#define FAIL 0

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mersenne.h"
#include "functions.c"
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <unistd.h> /* sleep() */
#include <string.h>


typedef struct _AG
{
	int P; /*The metric used, l1,l2,l_inf */
	int FUNCTION;
	//Problem definitions
	int DIM;    //number of problem variables
	int RUN;  /*Algorithm can run many times in order to see its robustness*/
	double *best; //[DIM];           //best solution found
	double bestfo;         //best fo value
	double LB; //lower bound of the variables
	double UB; //upper bound of the variables
	int KMAX,TMAX,AVAL_MAX;
	int RADII_T_FLAG;
	int know;
	double Q,RADII,RHO,EPSILON;
	double *r;
	int METHOD;
	int ECO_STEP;
	int EVO_STEP;
	int VNS_POP;
	int POP_INDEX;
	double DELTA_MUTATION;
	int G_MAX;
	double PC; //probabilidade de crossover
}pAG;


int getParametersAG(FILE *file, pAG *ag)
{
	int *P,*ECO_STEP,*EVO_STEP,*VNS_POP,*G_MAX,*FUNCTION,*DIM,*RUN;
	int *KMAX,*TMAX,*AVAL_MAX,*METHOD;
	int *RADII_T_FLAG;
	double *Q,*RADII,*RHO,*EPSILON,*PC;

	FUNCTION = (int*) malloc(sizeof(int));
	DIM = (int*) malloc(sizeof(int));
	RUN = (int*) malloc(sizeof(int));
	ECO_STEP = (int*) malloc(sizeof(int));
	EVO_STEP = (int*) malloc(sizeof(int));
	VNS_POP = (int*) malloc(sizeof(int));
	KMAX = (int*) malloc(sizeof(int));
	TMAX = (int*) malloc(sizeof(int));
	METHOD = (int*) malloc(sizeof(int));
	AVAL_MAX = (int*) malloc(sizeof(int));
	RADII_T_FLAG = (int*) malloc(sizeof(int));
	Q = (double*) malloc(sizeof(double));
	RADII = (double*) malloc(sizeof(double));
	RHO = (double*) malloc(sizeof(double));
	EPSILON = (double*) malloc(sizeof(double));
	P = (int*) malloc(sizeof(int));
	G_MAX = (int*) malloc(sizeof(int));
	PC = (double*) malloc(sizeof(double));

	if (file == 0)
	{
		printf( "Could not open ini file! Usage ./<exec> <file.in>\n" );
		return -1;
	}
	else 
	{
		ffscanf("RUN", file, "%d", &RUN);
		ffscanf("DIM", file, "%d", &DIM); 
		ffscanf("FUNCTION",file, "%d", &FUNCTION);
		ffscanf("KMAX", file, "%d", &KMAX);
		ffscanf("TMAX", file, "%d", &TMAX);
		ffscanf("Q", file, "%lf", &Q);
		ffscanf("RADII", file, "%lf", &RADII); 
		ffscanf("RADII_T_FLAG", file, "%d", &RADII_T_FLAG); 
		ffscanf("AVAL_MAX", file, "%d", &AVAL_MAX); 
		ffscanf("RHO", file, "%lf", &RHO); 
		ffscanf("EPSILON", file, "%lf", &EPSILON); 
		ffscanf("METHOD", file, "%d", &METHOD); 
		ffscanf("P", file, "%d", &P); 
		ffscanf("VNS_POP", file, "%d", &VNS_POP); 
		ffscanf("ECO_STEP", file, "%d", &ECO_STEP); 
		ffscanf("EVO_STEP", file, "%d", &EVO_STEP); 
		ffscanf("G_MAX", file, "%d", &G_MAX); 
		ffscanf("PC", file, "%lf", &PC); 

		vns->RUN = *RUN;
		vns->DIM = *DIM;
		vns->FUNCTION = *FUNCTION;
		vns->KMAX = *KMAX;
		vns->TMAX = *TMAX;
		vns->Q = *Q;
		vns->RADII = *RADII;
		vns->RADII_T_FLAG = *RADII_T_FLAG;
		vns->AVAL_MAX = *AVAL_MAX;
		vns->RHO = *RHO;
		vns->EPSILON = *EPSILON;
		vns->METHOD = *METHOD;
		vns->P = *P;
		vns->VNS_POP = *VNS_POP;
		vns->ECO_STEP = *ECO_STEP;
		vns->EVO_STEP = *EVO_STEP;
		vns->G_MAX = *G_MAX;
		vns->PC = *PC;

		return 1;
	}
}


/*Main program of the search algorithm*/
int main(int argc, char **argv)
{
	srand(time(NULL));
	MT_seed();
	
	
	
	
	

}
