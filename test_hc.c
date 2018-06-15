#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "cubature.h"

// 2-d MVN pdf with sigma = eye(2) and mean = [1, 0]^T
double mvn_pdf(const double *x){
  double x2 = pow(x[0] - 1.0, 2) + pow(x[1] - 0, 2);
  double num = exp(-0.5 * x2);
  double den = 2.0 * M_PI;
  return(num / den);
}

int count = 0;

int mvn_wrapper(unsigned ndim, const double *x, void *fdata,
		unsigned fdim, double *fval) {

  double dens = mvn_pdf(x);
  // Compute x * mvn_pdf(x)
  for (int i = 0; i < fdim; i++) {
    fval[i] = x[i] * dens;
  }
  count++;
  return 0;
}

int main() {
  double xmin[] = {-5.0, -5.0};
  double xmax[] = {5.0, 5.0};
  int dim = 2;
  int maxEval = 0;
  double tol = .001;
  int integrand_fdim = 2;
  double val[integrand_fdim], err[integrand_fdim];
  
  int retcode = CUBATURE(integrand_fdim, mvn_wrapper, NULL, 
			 dim, xmin, xmax, 
			 maxEval, 0, tol, ERROR_INDIVIDUAL, val, err);

  printf("Return code : %d\n", retcode);

  if (retcode == 0) {
    printf("Fun calls: %d,  Integral value: [%f, %f]\n", count, val[0], val[1]);
  }

  return retcode;
}
