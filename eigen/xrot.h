//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrot.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//
#ifndef XROT_H
#define XROT_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "eigen_types.h"

// Function Declarations
extern void b_xrot(int n, double x[4064256], int ix0, int iy0, double c, double
                   s);
extern void c_xrot(double x[4064256], int ix0, int iy0, double c, double s);
extern void xrot(int n, double x[4064256], int ix0, int iy0, double c, double s);

#endif

//
// File trailer for xrot.h
//
// [EOF]
//
