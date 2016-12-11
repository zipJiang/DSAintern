//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eigen.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "eig.h"
#include "schur.h"
#include "xzgeev.h"
#include "ishermitian.h"

// Function Definitions

//
// Arguments    : const double A[4064256]
//                creal_T V[4064256]
//                creal_T D[4064256]
// Return Type  : void
//
void eigen(const double A[4064256], creal_T V[4064256], creal_T D[4064256])
{
  int info;
  creal_T alpha1[2016];
  creal_T beta1[2016];
  if (ishermitian(A)) {
    schur(A, V, D);
    diagDiagUpperHessNoImag(D);
  } else {
    xzgeev(A, &info, alpha1, beta1, V);
    makeD(alpha1, beta1, D);
  }
}

//
// File trailer for eigen.cpp
//
// [EOF]
//
