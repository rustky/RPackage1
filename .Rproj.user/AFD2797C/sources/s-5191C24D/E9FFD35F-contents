#' EM Gaussian Mixture Model 
#'
#' @param data.mat numeric input data matrix [1 x n]
#' @param K int desired number of clusters
#'
#' @return Output list including the log likelihood and the cluster assignment vector [1 x n]
#' @export 
#'
#' @examples
#' data.mat <- as.matrix(iris[, c("Petal.Length", "Petal.Width")])
#' K <- 3
#' GMM.results <- RPackage1::GMM(data.mat, K)
GMM <- function(data.mat, K){
  rand.mat <- matrix(
    runif(nrow(data.mat)*K),
    nrow=nrow(data.mat),
    ncol=K)
  prob.mat <- rand.mat/rowSums(rand.mat)
  cluster.param.list <- list()
  log.lik.old <- 0
  flag <- 1
  while(flag == 1){
    for(cluster in 1:K){
      prob.vec <- prob.mat[, cluster]
      mean.vec <- colSums(data.mat * prob.vec)/sum(prob.vec)
      mean.mat <- matrix(
        mean.vec, nrow(data.mat), ncol(data.mat), byrow=TRUE)
      diff.mat <- data.mat - mean.mat
      tolerance <- 1e-6
      this.cluster.params <- list(
        prior.weight=mean(prob.vec),
        mean.vec=mean.vec,
        cov.vec=colSums(diff.mat^2 * prob.vec)/sum(prob.vec)+tolerance)
      cluster.param.list[[cluster]] <- this.cluster.params
    }
    log.density.mat <- matrix(NA, nrow(data.mat), K)
    prior.weight.mat <- matrix(NA, nrow(data.mat), K)
    for(cluster in 1:K){
      params <- cluster.param.list[[cluster]]
      mean.mat <- matrix(
        params$mean.vec, nrow(data.mat), ncol(data.mat),
        byrow=TRUE)
      sd.vec <- sqrt(params$cov.vec)
      sd.mat <- matrix(
        sd.vec, nrow(data.mat), ncol(data.mat),
        byrow=TRUE)
      dnorm.mat <- dnorm(data.mat, mean.mat, sd.mat, log=TRUE)
      sd.vec[which(colMeans(!is.finite(dnorm.mat))==1)]
      log.density.mat[,cluster] <- rowSums(dnorm.mat)
      prior.weight.mat[,cluster] <- params$prior.weight
    }
    max.vec <- apply(log.density.mat, 1, max)
    log.sum.vec <- log(
      rowSums(prior.weight.mat*exp(log.density.mat - max.vec))
    )
    log.total.density.vec <- max.vec + log.sum.vec
    which(!is.finite(log.total.density.vec))
    in.exp <- log(prior.weight.mat)+log.density.mat-log.total.density.vec
    prob.mat <- exp(in.exp)
    log.lik.new <- sum(log.total.density.vec)
    # browser()
    which(!is.finite(prob.mat))
    if(log.lik.old == log.lik.new){
      flag <- 0
      output.list <- list(
        loglik = log.lik.new,
        clusters = ramify::argmax(prob.mat, rows = TRUE)
      )
    }
    else{
      log.lik.old <- log.lik.new
    }
  }
  return(output.list)
}
