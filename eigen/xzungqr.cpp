//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzungqr.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xzungqr.h"
#include "xscal.h"
#include "xzlarf.h"

// Function Definitions

//
// Arguments    : int m
//                int n
//                int k
//                double A[4064256]
//                int ia0
//                const double tau[2015]
//                int itau0
// Return Type  : void
//
void xzungqr(int m, int n, int k, double A[4064256], int ia0, const double tau
             [2015], int itau0)
{
  int j;
  int itau;
  double work[2016];
  int i;
  int iaii;
  if (!(n < 1)) {
    for (j = k; j < n; j++) {
      itau = ia0 + j * 2016;
      for (i = 0; i < m; i++) {
        A[(itau + i) - 1] = 0.0;
      }

      A[(itau + j) - 1] = 1.0;
    }

    itau = (itau0 + k) - 2;
    memset(&work[0], 0, 2016U * sizeof(double));
    for (i = k; i >= 1; i--) {
      iaii = ((ia0 + i) + (i - 1) * 2016) - 2;
      if (i < n) {
        A[iaii] = 1.0;
        c_xzlarf((m - i) + 1, n - i, iaii + 1, tau[itau], A, iaii + 2017, work);
      }

      if (i < m) {
        xscal(m - i, -tau[itau], A, iaii + 2);
      }

      A[iaii] = 1.0 - tau[itau];
      for (j = 1; j < i; j++) {
        A[iaii - j] = 0.0;
      }

      itau--;
    }
  }
}

//
// File trailer for xzungqr.cpp
//
// [EOF]
//
