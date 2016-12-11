//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlanhs.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xzlanhs.h"

// Function Definitions

//
// Arguments    : const creal_T A[4064256]
//                int ilo
//                int ihi
// Return Type  : double
//
double xzlanhs(const creal_T A[4064256], int ilo, int ihi)
{
  double f;
  double scale;
  double sumsq;
  boolean_T firstNonZero;
  int j;
  int i0;
  int i;
  double reAij;
  double imAij;
  double temp2;
  f = 0.0;
  if (!(ilo > ihi)) {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    for (j = ilo; j <= ihi; j++) {
      i0 = j + 1;
      if (ihi < j + 1) {
        i0 = ihi;
      }

      for (i = ilo; i <= i0; i++) {
        reAij = A[(i + 2016 * (j - 1)) - 1].re;
        imAij = A[(i + 2016 * (j - 1)) - 1].im;
        if (reAij != 0.0) {
          reAij = std::abs(reAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            temp2 = scale / reAij;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = reAij;
          } else {
            temp2 = reAij / scale;
            sumsq += temp2 * temp2;
          }
        }

        if (imAij != 0.0) {
          reAij = std::abs(imAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            temp2 = scale / reAij;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = reAij;
          } else {
            temp2 = reAij / scale;
            sumsq += temp2 * temp2;
          }
        }
      }
    }

    f = scale * std::sqrt(sumsq);
  }

  return f;
}

//
// File trailer for xzlanhs.cpp
//
// [EOF]
//
