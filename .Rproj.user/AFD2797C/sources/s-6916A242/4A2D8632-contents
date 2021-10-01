library(RPackage1)
library(testthat)
context("Kmeans")

test_that("Kmeans produces a reasonable output",{
  data.mat <- as.matrix(
    iris[, c("Petal.Length", "Petal.Width")])
  K <- 3
  centers.mat <- data.mat[sample(1:nrow(data.mat), K), ]
  mine.cluster.vec <- RPackage1::KMeans_interface(data.mat, centers.mat)
  stats.cluster.vec <- stats::kmeans(data.mat,K)
  stats.length = length(stats.cluster.vec$cluster)
  mine.length = length(mine.cluster.vec)
  expect_equal(stats.length,mine.length)
})

test_that("All clusters are present",{
  data.mat <- as.matrix(
    iris[, c("Petal.Length", "Petal.Width")])
  K <- 3
  centers.mat <- data.mat[sample(1:nrow(data.mat), K), ]
  mine.cluster.vec <- RPackage1::KMeans_interface(data.mat, centers.mat)
  flags <- 1:K %in% mine.cluster.vec
  expect_true(all(flags))
})