//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrot.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xrot.h"

// Function Definitions

//
// Arguments    : int n
//                double x[4064256]
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
void b_xrot(int n, double x[4064256], int ix0, int iy0, double c, double s)
{
  int ix;
  int iy;
  int k;
  double temp;
  if (!(n < 1)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 1; k <= n; k++) {
      temp = c * x[ix] + s * x[iy];
      x[iy] = c * x[iy] - s * x[ix];
      x[ix] = temp;
      iy++;
      ix++;
    }
  }
}

//
// Arguments    : double x[4064256]
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
void c_xrot(double x[4064256], int ix0, int iy0, double c, double s)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 2016; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

//
// Arguments    : int n
//                double x[4064256]
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
void xrot(int n, double x[4064256], int ix0, int iy0, double c, double s)
{
  int ix;
  int iy;
  int k;
  double temp;
  if (!(n < 1)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 1; k <= n; k++) {
      temp = c * x[ix] + s * x[iy];
      x[iy] = c * x[iy] - s * x[ix];
      x[ix] = temp;
      iy += 2016;
      ix += 2016;
    }
  }
}

//
// File trailer for xrot.cpp
//
// [EOF]
//
