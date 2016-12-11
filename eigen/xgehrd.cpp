//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgehrd.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xgehrd.h"
#include "xzlarf.h"
#include "xzlarfg.h"

// Function Definitions

//
// Arguments    : double a[4064256]
//                double tau[2015]
// Return Type  : void
//
void xgehrd(double a[4064256], double tau[2015])
{
  double work[2016];
  int i;
  int im1n;
  int in;
  double alpha1;
  int b_i;
  double b_tau;
  memset(&work[0], 0, 2016U * sizeof(double));
  for (i = 0; i < 2015; i++) {
    im1n = i * 2016 + 2;
    in = (i + 1) * 2016;
    alpha1 = a[(i + 2016 * i) + 1];
    if (i + 3 <= 2016) {
      b_i = i + 3;
    } else {
      b_i = 2016;
    }

    b_tau = xzlarfg(2015 - i, &alpha1, a, b_i + i * 2016);
    a[(i + 2016 * i) + 1] = 1.0;
    xzlarf(2015 - i, i + im1n, b_tau, a, in + 1, work);
    b_xzlarf(2015 - i, 2015 - i, i + im1n, b_tau, a, (i + in) + 2, work);
    a[(i + 2016 * i) + 1] = alpha1;
    tau[i] = b_tau;
  }
}

//
// File trailer for xgehrd.cpp
//
// [EOF]
//
