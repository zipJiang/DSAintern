//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xhseqr.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xhseqr.h"
#include "xdhseqr.h"

// Function Definitions

//
// Arguments    : double h[4064256]
//                double z[4064256]
// Return Type  : int
//
int xhseqr(double h[4064256], double z[4064256])
{
  int info;
  int istart;
  int j;
  int i;
  info = eml_dlahqr(h, z);
  istart = 4;
  for (j = 0; j < 2013; j++) {
    for (i = istart; i < 2017; i++) {
      h[(i + 2016 * j) - 1] = 0.0;
    }

    istart++;
  }

  return info;
}

//
// File trailer for xhseqr.cpp
//
// [EOF]
//
