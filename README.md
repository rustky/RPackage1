# RPackage1
  <!-- badges: start -->
  [![R-CMD-check](https://github.com/rustky/RPackage1/workflows/R-CMD-check/badge.svg)](https://github.com/rustky/RPackage1/actions)
  <!-- badges: end -->

## Installation 
1. remotes::install_github(“rustky/RPackage1”)

## Examples
Update centers and find closet center to each point 
```
data.mat <- as.matrix(
  iris[, c("Petal.Length", "Petal.Width")])
K <- 3
(centers.mat <- data.mat[sample(1:nrow(data.mat), K), ])
(cluster.id.vec <-
RPackage1::find_closest_center_interface(
  data.mat, centers.mat))
new.centers.mat <- RPackage1::update_centers_interface(
  data.mat, cluster.id.vec, K)
 ```
 
Compare two matricies
 ```
x <- as.matrix(
    iris[, c("Petal.Length", "Petal.Width")])
y <- as.matrix(
    iris[, c("Petal.Length", "Petal.Width")])
N_centers <- nrow(x)
N_features <- ncol(x)
status <- 
  compare_matricies_interface(x, y, N_centers, N_features)
  ```
  
  Compute cluster vector using Kmeans algorithm
  
 ```
data_mat <- as.matrix(iris[, c("Petal.Length", "Petal.Width")])
K <- 3
centers_mat <- data_mat[sample(1:nrow(data_mat), K), ]
cluster.vec <- RPackage1::KMeans_interface(data_mat, centers_mat)
```

Compute cluster vector using EM Gaussian Mixture Models
```
data.mat <- as.matrix(iris[, c("Petal.Length", "Petal.Width")])
K <- 3
GMM.results <- RPackage1::GMM(data.mat, K)
```
