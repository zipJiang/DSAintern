//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgeev.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xzgeev.h"
#include "xnrm2.h"
#include "xzggev.h"

// Function Definitions

//
// Arguments    : const double A[4064256]
//                int *info
//                creal_T alpha1[2016]
//                creal_T beta1[2016]
//                creal_T V[4064256]
// Return Type  : void
//
void xzgeev(const double A[4064256], int *info, creal_T alpha1[2016], creal_T
            beta1[2016], creal_T V[4064256])
{
  static creal_T At[4064256];
  int coltop;
  double colnorm;
  int j;
  for (coltop = 0; coltop < 4064256; coltop++) {
    At[coltop].re = A[coltop];
    At[coltop].im = 0.0;
  }

  xzggev(At, info, alpha1, beta1, V);
  for (coltop = 0; coltop <= 4062241; coltop += 2016) {
    colnorm = c_xnrm2(V, coltop + 1);
    for (j = coltop; j + 1 <= coltop + 2016; j++) {
      if (V[j].im == 0.0) {
        V[j].re /= colnorm;
        V[j].im = 0.0;
      } else if (V[j].re == 0.0) {
        V[j].re = 0.0;
        V[j].im /= colnorm;
      } else {
        V[j].re /= colnorm;
        V[j].im /= colnorm;
      }
    }
  }
}

//
// File trailer for xzgeev.cpp
//
// [EOF]
//
