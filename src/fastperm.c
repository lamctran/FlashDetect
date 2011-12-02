#include <stdio.h>
#include <math.h>
/*#include <Rmath.h>*/
#include <R.h>

void fastperm3(double *X0,double *X1,double *X2,double *XtildePerm,int *B,int *N,double *max_array, double *min_array){
  int i=0,m1=0,m2=0,BB=*B,NN=*N;
  double tmax=0,tmin=0;
  for (m1=0;m1<BB;m1++){
    for (i=0;i<NN;i++) {
      XtildePerm[i]=X0[i]+X1[i+m1];
    }
    for (m2=0;m2<BB;m2++){
      for (i=0;i<NN;i++){
        XtildePerm[i]+=X2[i+m2];
        tmin=((XtildePerm[i] < tmin) ? XtildePerm[i]:tmin);
        tmax=((XtildePerm[i] > tmax) ? XtildePerm[i]:tmax);
      }
      max_array[(m1-1)*BB+m2]=tmax;
      min_array[(m1-1)*BB+m2]=tmin;
    }
  }
}
