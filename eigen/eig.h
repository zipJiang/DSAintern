//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eig.h
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//
#ifndef EIG_H
#define EIG_H

// Include Files
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "eigen_types.h"

// Function Declarations
extern void diagDiagUpperHessNoImag(creal_T D[4064256]);
extern void makeD(const creal_T alpha1[2016], const creal_T beta1[2016], creal_T
                  D[4064256]);

#endif

//
// File trailer for eig.h
//
// [EOF]
//
