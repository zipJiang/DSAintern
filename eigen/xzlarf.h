//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarf.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//
#ifndef XZLARF_H
#define XZLARF_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "eigen_types.h"

// Function Declarations
extern void b_xzlarf(int m, int n, int iv0, double tau, double C[4064256], int
                     ic0, double work[2016]);
extern void c_xzlarf(int m, int n, int iv0, double tau, double C[4064256], int
                     ic0, double work[2016]);
extern void xzlarf(int n, int iv0, double tau, double C[4064256], int ic0,
                   double work[2016]);

#endif

//
// File trailer for xzlarf.h
//
// [EOF]
//
