#include "compare_matricies.h"
#include <stdio.h>

int compare_matricies(double *x, double *y, int N_centers, int N_features){
  if(N_features < 1){
    return ERROR_N_DATA_MUST_BE_POSITIVE;
  }
  if(N_centers < 1){
    return ERROR_N_CENTERS_MUST_BE_POSITIVE;
  }
  for(int feature_i = 0; feature_i < N_features; feature_i++){
    for(int center_i=0;center_i<N_centers; center_i++){
      double center_dif = 
        x[feature_i*N_centers + center_i] -
        y[feature_i*N_centers + center_i];
      if(center_dif !=0){
        return 1;
      }
    }
  }
  return 0;
}

