\name{update_centers_interface}
\alias{update_centers_interface}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Update the locations of each cluster center
}
\description{
After computing the cluster assignments, update the cluster center locations based of the average the data assigned to that cluster.
}
\usage{
update_centers_interface(data_mat, cluster_vec, N_centers)
}
\arguments{
  \item{data_mat}{
Numeric input data matrix [n x p]
}
  \item{cluster_vec}{
Vector of cluster assignments [1 x n]
}
  \item{N_centers}{
int number of clusters to compute
}
}
\examples{
  data.mat <- as.matrix(
    iris[, c("Petal.Length", "Petal.Width")])
  K <- 3
  (centers.mat <- data.mat[sample(1:nrow(data.mat), K), ])
  (cluster.id.vec <-
    RPackage1::find_closest_center_interface(
      data.mat, centers.mat))
  new.centers.mat <- RPackage1::update_centers_interface(
      data.mat, cluster.id.vec, K)
}

