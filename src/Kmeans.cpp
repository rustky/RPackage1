#include "update_centers.h"
#include "find_closest_center.h"
#include "compare_matricies.h"
#include <stdio.h>

int Kmeans(
    const int N_data,
    const int N_centers,
    const int N_features,
    const double *data_ptr,
    double *old_centers_ptr,
    double *new_centers_ptr,
    int *cluster_ptr,
    int *cluster_count_ptr){
    if(N_data < 1){
      return ERROR_N_DATA_MUST_BE_POSITIVE;
    }
    if(N_centers < 1){
      return ERROR_N_CENTERS_MUST_BE_POSITIVE;
    }
  while(1){
    int cluster_status = find_closest_center(N_data,
                                            N_centers,
                                            N_features, 
                                            data_ptr,
                                            old_centers_ptr,
                                            cluster_ptr);
    int centers_status = update_centers(N_data,
                                        N_centers,
                                        N_features,
                                        data_ptr,
                                        cluster_ptr,
                                        cluster_count_ptr,
                                        new_centers_ptr);
    if(compare_matricies(old_centers_ptr,
                         new_centers_ptr,
                         N_centers,
                         N_features) == 0){
      return 0;
    }
    else{
      old_centers_ptr = new_centers_ptr;
    }
  }
  return 1;
}