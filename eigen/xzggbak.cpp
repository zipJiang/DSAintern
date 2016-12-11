//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzggbak.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xzggbak.h"

// Function Definitions

//
// Arguments    : creal_T V[4064256]
//                int ilo
//                int ihi
//                const int rscale[2016]
// Return Type  : void
//
void xzggbak(creal_T V[4064256], int ilo, int ihi, const int rscale[2016])
{
  int i;
  int k;
  int j;
  double tmp_re;
  double tmp_im;
  if (ilo > 1) {
    for (i = ilo - 2; i + 1 >= 1; i--) {
      k = rscale[i] - 1;
      if (rscale[i] != i + 1) {
        for (j = 0; j < 2016; j++) {
          tmp_re = V[i + 2016 * j].re;
          tmp_im = V[i + 2016 * j].im;
          V[i + 2016 * j] = V[k + 2016 * j];
          V[k + 2016 * j].re = tmp_re;
          V[k + 2016 * j].im = tmp_im;
        }
      }
    }
  }

  if (ihi < 2016) {
    for (i = ihi; i + 1 < 2017; i++) {
      k = rscale[i] - 1;
      if (rscale[i] != i + 1) {
        for (j = 0; j < 2016; j++) {
          tmp_re = V[i + 2016 * j].re;
          tmp_im = V[i + 2016 * j].im;
          V[i + 2016 * j] = V[k + 2016 * j];
          V[k + 2016 * j].re = tmp_re;
          V[k + 2016 * j].im = tmp_im;
        }
      }
    }
  }
}

//
// File trailer for xzggbak.cpp
//
// [EOF]
//
