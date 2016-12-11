//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rsf2csf.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "rsf2csf.h"
#include "xdlanv2.h"
#include "eigen_rtwutil.h"

// Function Definitions

//
// Arguments    : const double Ur[4064256]
//                const double Tr[4064256]
//                creal_T U[4064256]
//                creal_T T[4064256]
// Return Type  : void
//
void rsf2csf(const double Ur[4064256], const double Tr[4064256], creal_T U
             [4064256], creal_T T[4064256])
{
  int j;
  int m;
  double r;
  double s;
  double t1_re;
  double t1_im;
  double mu1_im;
  double rt1i;
  double mu1_re;
  double rt2i;
  double cs;
  double sn;
  for (j = 0; j < 4064256; j++) {
    T[j].re = Tr[j];
    T[j].im = 0.0;
    U[j].re = Ur[j];
    U[j].im = 0.0;
  }

  for (m = 2014; m >= 0; m += -1) {
    if (Tr[(m + 2016 * m) + 1] != 0.0) {
      r = Tr[m + 2016 * m];
      s = Tr[m + 2016 * (m + 1)];
      t1_re = Tr[(m + 2016 * m) + 1];
      t1_im = Tr[(m + 2016 * (m + 1)) + 1];
      xdlanv2(&r, &s, &t1_re, &t1_im, &mu1_im, &rt1i, &mu1_re, &rt2i, &cs, &sn);
      mu1_re = mu1_im - Tr[(m + 2016 * (m + 1)) + 1];
      r = rt_hypotd_snf(rt_hypotd_snf(mu1_re, rt1i), Tr[(m + 2016 * m) + 1]);
      if (rt1i == 0.0) {
        mu1_re /= r;
        mu1_im = 0.0;
      } else if (mu1_re == 0.0) {
        mu1_re = 0.0;
        mu1_im = rt1i / r;
      } else {
        mu1_re /= r;
        mu1_im = rt1i / r;
      }

      s = Tr[(m + 2016 * m) + 1] / r;
      for (j = m; j + 1 < 2017; j++) {
        t1_re = T[m + 2016 * j].re;
        t1_im = T[m + 2016 * j].im;
        r = T[m + 2016 * j].re;
        T[m + 2016 * j].re = (mu1_re * T[m + 2016 * j].re + mu1_im * T[m + 2016 *
                              j].im) + s * T[(m + 2016 * j) + 1].re;
        T[m + 2016 * j].im = (mu1_re * T[m + 2016 * j].im - mu1_im * r) + s * T
          [(m + 2016 * j) + 1].im;
        r = mu1_re * T[(m + 2016 * j) + 1].im + mu1_im * T[(m + 2016 * j) + 1].
          re;
        T[(m + 2016 * j) + 1].re = (mu1_re * T[(m + 2016 * j) + 1].re - mu1_im *
          T[(m + 2016 * j) + 1].im) - s * t1_re;
        T[(m + 2016 * j) + 1].im = r - s * t1_im;
      }

      for (j = 0; j + 1 <= m + 2; j++) {
        t1_re = T[j + 2016 * m].re;
        t1_im = T[j + 2016 * m].im;
        r = mu1_re * T[j + 2016 * m].im + mu1_im * T[j + 2016 * m].re;
        T[j + 2016 * m].re = (mu1_re * T[j + 2016 * m].re - mu1_im * T[j + 2016 *
                              m].im) + s * T[j + 2016 * (m + 1)].re;
        T[j + 2016 * m].im = r + s * T[j + 2016 * (m + 1)].im;
        r = T[j + 2016 * (m + 1)].re;
        T[j + 2016 * (m + 1)].re = (mu1_re * T[j + 2016 * (m + 1)].re + mu1_im *
          T[j + 2016 * (m + 1)].im) - s * t1_re;
        T[j + 2016 * (m + 1)].im = (mu1_re * T[j + 2016 * (m + 1)].im - mu1_im *
          r) - s * t1_im;
      }

      for (j = 0; j < 2016; j++) {
        t1_re = U[j + 2016 * m].re;
        t1_im = U[j + 2016 * m].im;
        r = mu1_re * U[j + 2016 * m].im + mu1_im * U[j + 2016 * m].re;
        U[j + 2016 * m].re = (mu1_re * U[j + 2016 * m].re - mu1_im * U[j + 2016 *
                              m].im) + s * U[j + 2016 * (m + 1)].re;
        U[j + 2016 * m].im = r + s * U[j + 2016 * (m + 1)].im;
        r = U[j + 2016 * (m + 1)].re;
        U[j + 2016 * (m + 1)].re = (mu1_re * U[j + 2016 * (m + 1)].re + mu1_im *
          U[j + 2016 * (m + 1)].im) - s * t1_re;
        U[j + 2016 * (m + 1)].im = (mu1_re * U[j + 2016 * (m + 1)].im - mu1_im *
          r) - s * t1_im;
      }

      T[(m + 2016 * m) + 1].re = 0.0;
      T[(m + 2016 * m) + 1].im = 0.0;
    }
  }
}

//
// File trailer for rsf2csf.cpp
//
// [EOF]
//
