#include <R.h>
#include <R_ext/Rdynload.h>
#include <stdlib.h> 
#include "find_closest_center.h"
#include "update_centers.h"
#include <Rcpp.h>
#include "compare_matricies.h"
#include "Kmeans.h"
using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector find_closest_center_interface
  (NumericMatrix data_mat, NumericMatrix centers_mat) {
  int N_data = data_mat.nrow();
  int N_centers = centers_mat.nrow();
  int N_features = centers_mat.ncol();
  if(N_features != data_mat.ncol()){
    Rcpp::stop("number of columns in data and centers should be the same");
  }
  double *data_ptr = &data_mat[0];
  double *centers_ptr = &centers_mat[0];
  IntegerVector cluster_vec(N_data);
  int *cluster_ptr = &cluster_vec[0];
  int status = find_closest_center
    (N_data,
     N_centers,
     N_features,
     data_ptr,
     centers_ptr,
     //inputs above, outputs below.
     cluster_ptr);
  if(status == ERROR_N_DATA_MUST_BE_POSITIVE){
    Rcpp::stop("N_data must be postiive");
  }
  if(status == ERROR_N_CENTERS_MUST_BE_POSITIVE){
    Rcpp::stop("N_centers must be postiive");
  }
  return cluster_vec;
}

//[[Rcpp::export]]
NumericMatrix update_centers_interface
  (NumericMatrix data_mat, IntegerVector cluster_vec, int N_centers) {
  int N_data = data_mat.nrow();
  int N_features = data_mat.ncol();
  double *data_ptr = &data_mat[0];
  int *cluster_ptr = &cluster_vec[0];
  NumericMatrix new_centers_mat(N_centers,N_features);
  IntegerVector cluster_count_vec(N_centers);
  int *cluster_count_ptr = &cluster_count_vec[0];
  double *new_centers_ptr = &new_centers_mat[0];
  int status = update_centers
    (N_data,
     N_centers,
     N_features,
     data_ptr,
     cluster_ptr,
     //inputs above, outputs below.
     cluster_count_ptr,
     new_centers_ptr);
  if(status == ERROR_N_DATA_MUST_BE_POSITIVE){
    Rcpp::stop("N_data must be postiive");
  }
  if(status == ERROR_N_CENTERS_MUST_BE_POSITIVE){
    Rcpp::stop("N_centers must be postiive");
  }
  return new_centers_mat;
}

//[[Rcpp::export]]
int compare_matricies_interface(NumericMatrix x, NumericMatrix y,
                                int N_centers, int N_features){
  double *x_ptr = &x[0];
  double *y_ptr = &y[0];
  int status = compare_matricies(x_ptr, y_ptr, N_centers, N_features);
  return status;
}

//[[Rcpp::export]]
IntegerVector KMeans_interface
  (NumericMatrix data_mat, NumericMatrix centers_mat){
  double *data_ptr = &data_mat[0];
  int N_data = data_mat.nrow();
  int N_centers = centers_mat.nrow();
  int N_features = centers_mat.ncol();
  NumericMatrix new_centers_mat(N_centers,N_features);
  double *old_centers_ptr = &centers_mat[0];
  double *new_centers_ptr = &new_centers_mat[0];
  IntegerVector cluster_count_vec(N_centers);
  int *cluster_count_ptr = &cluster_count_vec[0];
  IntegerVector cluster_vec(N_data);
  int *cluster_ptr = &cluster_vec[0];
  int status = Kmeans(
    N_data,
    N_centers,
    N_features,
    data_ptr,
    old_centers_ptr,
    new_centers_ptr,
    cluster_ptr,
    cluster_count_ptr);
  return cluster_vec;
  }

