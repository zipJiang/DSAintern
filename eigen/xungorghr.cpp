//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xungorghr.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xungorghr.h"
#include "xzungqr.h"

// Function Definitions

//
// Arguments    : int n
//                int ilo
//                int ihi
//                double A[4064256]
//                int ia0
//                const double tau[2015]
//                int itau0
// Return Type  : void
//
void xungorghr(int n, int ilo, int ihi, double A[4064256], int ia0, const double
               tau[2015], int itau0)
{
  int nh;
  int j;
  int ia;
  int i;
  if (n != 0) {
    nh = ihi - ilo;
    for (j = ihi; j >= ilo + 1; j--) {
      ia = (ia0 + (j - 1) * 2016) - 1;
      for (i = 1; i < j; i++) {
        A[(ia + i) - 1] = 0.0;
      }

      for (i = j; i + 1 <= ihi; i++) {
        A[ia + i] = A[(ia + i) - 2016];
      }

      for (i = ihi; i + 1 <= n; i++) {
        A[ia + i] = 0.0;
      }
    }

    for (j = 0; j + 1 <= ilo; j++) {
      ia = (ia0 + j * 2016) - 1;
      for (i = 1; i <= n; i++) {
        A[(ia + i) - 1] = 0.0;
      }

      A[ia + j] = 1.0;
    }

    for (j = ihi; j + 1 <= n; j++) {
      ia = (ia0 + j * 2016) - 1;
      for (i = 1; i <= n; i++) {
        A[(ia + i) - 1] = 0.0;
      }

      A[ia + j] = 1.0;
    }

    xzungqr(nh, nh, nh, A, (ia0 + ilo) + ilo * 2016, tau, (itau0 + ilo) - 1);
  }
}

//
// File trailer for xungorghr.cpp
//
// [EOF]
//
