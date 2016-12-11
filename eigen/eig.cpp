//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eig.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "eig.h"

// Function Definitions

//
// Arguments    : creal_T D[4064256]
// Return Type  : void
//
void diagDiagUpperHessNoImag(creal_T D[4064256])
{
  int j;
  int i;
  D[0].im = 0.0;
  for (j = 0; j < 2015; j++) {
    D[(j + 2016 * (j + 1)) + 1].im = 0.0;
    D[(j + 2016 * j) + 1].re = 0.0;
    D[(j + 2016 * j) + 1].im = 0.0;
    for (i = 1; i <= j + 1; i++) {
      D[(i + 2016 * (j + 1)) - 1].re = 0.0;
      D[(i + 2016 * (j + 1)) - 1].im = 0.0;
    }
  }
}

//
// Arguments    : const creal_T alpha1[2016]
//                const creal_T beta1[2016]
//                creal_T D[4064256]
// Return Type  : void
//
void makeD(const creal_T alpha1[2016], const creal_T beta1[2016], creal_T D
           [4064256])
{
  int k;
  double brm;
  double bim;
  double d;
  for (k = 0; k < 4064256; k++) {
    D[k].re = 0.0;
    D[k].im = 0.0;
  }

  for (k = 0; k < 2016; k++) {
    if (beta1[k].im == 0.0) {
      if (alpha1[k].im == 0.0) {
        D[k + 2016 * k].re = alpha1[k].re / beta1[k].re;
        D[k + 2016 * k].im = 0.0;
      } else if (alpha1[k].re == 0.0) {
        D[k + 2016 * k].re = 0.0;
        D[k + 2016 * k].im = alpha1[k].im / beta1[k].re;
      } else {
        D[k + 2016 * k].re = alpha1[k].re / beta1[k].re;
        D[k + 2016 * k].im = alpha1[k].im / beta1[k].re;
      }
    } else if (beta1[k].re == 0.0) {
      if (alpha1[k].re == 0.0) {
        D[k + 2016 * k].re = alpha1[k].im / beta1[k].im;
        D[k + 2016 * k].im = 0.0;
      } else if (alpha1[k].im == 0.0) {
        D[k + 2016 * k].re = 0.0;
        D[k + 2016 * k].im = -(alpha1[k].re / beta1[k].im);
      } else {
        D[k + 2016 * k].re = alpha1[k].im / beta1[k].im;
        D[k + 2016 * k].im = -(alpha1[k].re / beta1[k].im);
      }
    } else {
      brm = std::abs(beta1[k].re);
      bim = std::abs(beta1[k].im);
      if (brm > bim) {
        bim = beta1[k].im / beta1[k].re;
        d = beta1[k].re + bim * beta1[k].im;
        D[k + 2016 * k].re = (alpha1[k].re + bim * alpha1[k].im) / d;
        D[k + 2016 * k].im = (alpha1[k].im - bim * alpha1[k].re) / d;
      } else if (bim == brm) {
        if (beta1[k].re > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        if (beta1[k].im > 0.0) {
          d = 0.5;
        } else {
          d = -0.5;
        }

        D[k + 2016 * k].re = (alpha1[k].re * bim + alpha1[k].im * d) / brm;
        D[k + 2016 * k].im = (alpha1[k].im * bim - alpha1[k].re * d) / brm;
      } else {
        bim = beta1[k].re / beta1[k].im;
        d = beta1[k].im + bim * beta1[k].re;
        D[k + 2016 * k].re = (bim * alpha1[k].re + alpha1[k].im) / d;
        D[k + 2016 * k].im = (bim * alpha1[k].im - alpha1[k].re) / d;
      }
    }
  }
}

//
// File trailer for eig.cpp
//
// [EOF]
//
