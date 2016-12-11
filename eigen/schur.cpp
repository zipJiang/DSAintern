//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: schur.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "schur.h"
#include "rsf2csf.h"
#include "xhseqr.h"
#include "xungorghr.h"
#include "xgehrd.h"

// Function Definitions

//
// Arguments    : const double A[4064256]
//                creal_T V[4064256]
//                creal_T T[4064256]
// Return Type  : void
//
void schur(const double A[4064256], creal_T V[4064256], creal_T T[4064256])
{
  static double b_A[4064256];
  double tau[2015];
  static double Vr[4064256];
  memcpy(&b_A[0], &A[0], 4064256U * sizeof(double));
  xgehrd(b_A, tau);
  memcpy(&Vr[0], &b_A[0], 4064256U * sizeof(double));
  xungorghr(2016, 1, 2016, Vr, 1, tau, 1);
  xhseqr(b_A, Vr);
  rsf2csf(Vr, b_A, V, T);
}

//
// File trailer for schur.cpp
//
// [EOF]
//
