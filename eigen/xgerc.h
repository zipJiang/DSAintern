//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgerc.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//
#ifndef XGERC_H
#define XGERC_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "eigen_types.h"

// Function Declarations
extern void b_xgerc(int m, int n, double alpha1, int ix0, const double y[2016],
                    double A[4064256], int ia0);
extern void xgerc(int m, int n, double alpha1, const double x[2016], int iy0,
                  double A[4064256], int ia0);

#endif

//
// File trailer for xgerc.h
//
// [EOF]
//
