//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzggev.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xzggev.h"
#include "xzlascl.h"
#include "xzggbak.h"
#include "xztgevc.h"
#include "xzhgeqz.h"
#include "xzgghrd.h"
#include "xzggbal.h"
#include "isfinite.h"
#include "xzlangeM.h"

// Function Definitions

//
// Arguments    : creal_T A[4064256]
//                int *info
//                creal_T alpha1[2016]
//                creal_T beta1[2016]
//                creal_T V[4064256]
// Return Type  : void
//
void xzggev(creal_T A[4064256], int *info, creal_T alpha1[2016], creal_T beta1
            [2016], creal_T V[4064256])
{
  double anrm;
  boolean_T ilascl;
  double anrmto;
  int i;
  int ihi;
  int rscale[2016];
  double vtemp;
  double y;
  *info = 0;
  anrm = xzlangeM(A);
  if (!b_isfinite(anrm)) {
    for (i = 0; i < 2016; i++) {
      alpha1[i].re = rtNaN;
      alpha1[i].im = 0.0;
      beta1[i].re = rtNaN;
      beta1[i].im = 0.0;
    }

    for (i = 0; i < 4064256; i++) {
      V[i].re = rtNaN;
      V[i].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      xzlascl(anrm, anrmto, A);
    }

    xzggbal(A, &i, &ihi, rscale);
    xzgghrd(i, ihi, A, V);
    xzhgeqz(A, i, ihi, V, info, alpha1, beta1);
    if (*info == 0) {
      xztgevc(A, V);
      xzggbak(V, i, ihi, rscale);
      for (i = 0; i < 2016; i++) {
        vtemp = std::abs(V[2016 * i].re) + std::abs(V[2016 * i].im);
        for (ihi = 0; ihi < 2015; ihi++) {
          y = std::abs(V[(ihi + 2016 * i) + 1].re) + std::abs(V[(ihi + 2016 * i)
            + 1].im);
          if (y > vtemp) {
            vtemp = y;
          }
        }

        if (vtemp >= 6.7178761075670888E-139) {
          vtemp = 1.0 / vtemp;
          for (ihi = 0; ihi < 2016; ihi++) {
            V[ihi + 2016 * i].re *= vtemp;
            V[ihi + 2016 * i].im *= vtemp;
          }
        }
      }

      if (ilascl) {
        b_xzlascl(anrmto, anrm, alpha1);
      }
    }
  }
}

//
// File trailer for xzggev.cpp
//
// [EOF]
//
