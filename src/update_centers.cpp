#include "update_centers.h"
#include <stdio.h>

int update_centers(
    const int N_data,
    const int N_centers,
    const int N_features,
    const double *data_ptr,
    const int *cluster_ptr,
    //inputs above, outputs below.
    int *cluster_count_ptr,
    double *new_centers_ptr
){

  if(N_data < 1){
    return ERROR_N_DATA_MUST_BE_POSITIVE;
  }
  if(N_centers < 1){
    return ERROR_N_CENTERS_MUST_BE_POSITIVE;
  }
  
  for(int feature_i=0;feature_i<N_features; feature_i++){
    for(int center_i=0;center_i<N_centers; center_i++){
      for(int data_i=0; data_i<N_data; data_i++){
        double data_value = data_ptr[feature_i*N_data + data_i];
        if(center_i + 1 == cluster_ptr[data_i]){
          new_centers_ptr[feature_i*N_centers + center_i] += data_value;
        }
      }
    }
  }
  for(int cluster_i = 0; cluster_i < N_centers; cluster_i++){
    for(int data_i = 0; data_i < N_data; data_i++){
      if(cluster_ptr[data_i] == cluster_i + 1){
        cluster_count_ptr[cluster_i] += 1;
      }
    }
  }
  for(int feature_i = 0; feature_i < N_features; feature_i++){
    for(int center_i=0;center_i<N_centers; center_i++){
      new_centers_ptr[feature_i*N_centers + center_i] = 
        new_centers_ptr[feature_i*N_centers + center_i]/
          cluster_count_ptr[center_i];
    }
  }
  return 0;
}
  

