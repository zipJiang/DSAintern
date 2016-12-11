//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xscal.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xscal.h"

// Function Definitions

//
// Arguments    : int n
//                double a
//                double x[4064256]
//                int ix0
// Return Type  : void
//
void xscal(int n, double a, double x[4064256], int ix0)
{
  int i2;
  int k;
  i2 = (ix0 + n) - 1;
  for (k = ix0; k <= i2; k++) {
    x[k - 1] *= a;
  }
}

//
// File trailer for xscal.cpp
//
// [EOF]
//
