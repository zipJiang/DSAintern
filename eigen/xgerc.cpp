//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgerc.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xgerc.h"

// Function Definitions

//
// Arguments    : int m
//                int n
//                double alpha1
//                int ix0
//                const double y[2016]
//                double A[4064256]
//                int ia0
// Return Type  : void
//
void b_xgerc(int m, int n, double alpha1, int ix0, const double y[2016], double
             A[4064256], int ia0)
{
  int jA;
  int jy;
  int j;
  double temp;
  int ix;
  int i8;
  int ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 1; j <= n; j++) {
      if (y[jy] != 0.0) {
        temp = y[jy] * alpha1;
        ix = ix0;
        i8 = m + jA;
        for (ijA = jA; ijA + 1 <= i8; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 2016;
    }
  }
}

//
// Arguments    : int m
//                int n
//                double alpha1
//                const double x[2016]
//                int iy0
//                double A[4064256]
//                int ia0
// Return Type  : void
//
void xgerc(int m, int n, double alpha1, const double x[2016], int iy0, double A
           [4064256], int ia0)
{
  int jA;
  int jy;
  int j;
  double temp;
  int ix;
  int i5;
  int ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = iy0 - 1;
    for (j = 1; j <= n; j++) {
      if (A[jy] != 0.0) {
        temp = A[jy] * alpha1;
        ix = 0;
        i5 = m + jA;
        for (ijA = jA; ijA + 1 <= i5; ijA++) {
          A[ijA] += x[ix] * temp;
          ix++;
        }
      }

      jy++;
      jA += 2016;
    }
  }
}

//
// File trailer for xgerc.cpp
//
// [EOF]
//
