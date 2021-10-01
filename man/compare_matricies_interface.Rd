\name{compare_matricies_interface}
\alias{compare_matricies_interface}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Check if two matricies are the same
}
\description{
Check by entry if two matricies of the same size are equal. 
}
\usage{
compare_matricies_interface(x, y, N_centers, N_features)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{x}{
numeric matrix [n x p]
}
  \item{y}{
numeric matrix [n x p]
}
  \item{N_centers}{
int number of clusters [n]
}
  \item{N_features}{
int number of features [p]
}
}

\examples{
x <- as.matrix(
    iris[, c("Petal.Length", "Petal.Width")])
y <- as.matrix(
    iris[, c("Petal.Length", "Petal.Width")])
N_centers <- nrow(x)
N_features <- ncol(x)
status <- 
  compare_matricies_interface(x, y, N_centers, N_features)
}

