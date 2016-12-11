//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xgemv.h"

// Function Definitions

//
// Arguments    : int m
//                int n
//                const double A[4064256]
//                int ia0
//                const double x[4064256]
//                int ix0
//                double y[2016]
// Return Type  : void
//
void b_xgemv(int m, int n, const double A[4064256], int ia0, const double x
             [4064256], int ix0, double y[2016])
{
  int iy;
  int i6;
  int iac;
  int ix;
  double c;
  int i7;
  int ia;
  if ((m == 0) || (n == 0)) {
  } else {
    for (iy = 1; iy <= n; iy++) {
      y[iy - 1] = 0.0;
    }

    iy = 0;
    i6 = ia0 + 2016 * (n - 1);
    for (iac = ia0; iac <= i6; iac += 2016) {
      ix = ix0;
      c = 0.0;
      i7 = (iac + m) - 1;
      for (ia = iac; ia <= i7; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[iy] += c;
      iy++;
    }
  }
}

//
// Arguments    : int m
//                int n
//                const double A[4064256]
//                int ia0
//                const double x[4064256]
//                int ix0
//                double y[2016]
// Return Type  : void
//
void c_xgemv(int m, int n, const double A[4064256], int ia0, const double x
             [4064256], int ix0, double y[2016])
{
  int iy;
  int i9;
  int iac;
  int ix;
  double c;
  int i10;
  int ia;
  if ((m == 0) || (n == 0)) {
  } else {
    for (iy = 1; iy <= n; iy++) {
      y[iy - 1] = 0.0;
    }

    iy = 0;
    i9 = ia0 + 2016 * (n - 1);
    for (iac = ia0; iac <= i9; iac += 2016) {
      ix = ix0;
      c = 0.0;
      i10 = (iac + m) - 1;
      for (ia = iac; ia <= i10; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[iy] += c;
      iy++;
    }
  }
}

//
// Arguments    : int m
//                int n
//                const double A[4064256]
//                int ia0
//                const double x[4064256]
//                int ix0
//                double y[2016]
// Return Type  : void
//
void xgemv(int m, int n, const double A[4064256], int ia0, const double x
           [4064256], int ix0, double y[2016])
{
  int iy;
  int ix;
  int i3;
  int iac;
  int i4;
  int ia;
  if ((m == 0) || (n == 0)) {
  } else {
    for (iy = 1; iy <= m; iy++) {
      y[iy - 1] = 0.0;
    }

    ix = ix0;
    i3 = ia0 + 2016 * (n - 1);
    for (iac = ia0; iac <= i3; iac += 2016) {
      iy = 0;
      i4 = (iac + m) - 1;
      for (ia = iac; ia <= i4; ia++) {
        y[iy] += A[ia - 1] * x[ix - 1];
        iy++;
      }

      ix++;
    }
  }
}

//
// File trailer for xgemv.cpp
//
// [EOF]
//
