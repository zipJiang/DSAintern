//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgghrd.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xzgghrd.h"
#include "xzlartg.h"

// Function Definitions

//
// Arguments    : int ilo
//                int ihi
//                creal_T A[4064256]
//                creal_T Z[4064256]
// Return Type  : void
//
void xzgghrd(int ilo, int ihi, creal_T A[4064256], creal_T Z[4064256])
{
  static signed char I[4064256];
  int k;
  int jcol;
  int jrow;
  double c;
  creal_T s;
  double stemp_re;
  double stemp_im;
  double Z_re;
  double A_re;
  memset(&I[0], 0, 4064256U * sizeof(signed char));
  for (k = 0; k < 2016; k++) {
    I[k + 2016 * k] = 1;
  }

  for (k = 0; k < 4064256; k++) {
    Z[k].re = I[k];
    Z[k].im = 0.0;
  }

  if (!(ihi < ilo + 2)) {
    for (jcol = ilo - 1; jcol + 1 < ihi - 1; jcol++) {
      for (jrow = ihi - 1; jrow + 1 > jcol + 2; jrow--) {
        xzlartg(A[(jrow + 2016 * jcol) - 1], A[jrow + 2016 * jcol], &c, &s, &A
                [(jrow + 2016 * jcol) - 1]);
        A[jrow + 2016 * jcol].re = 0.0;
        A[jrow + 2016 * jcol].im = 0.0;
        for (k = jcol + 1; k + 1 < 2017; k++) {
          stemp_re = c * A[(jrow + 2016 * k) - 1].re + (s.re * A[jrow + 2016 * k]
            .re - s.im * A[jrow + 2016 * k].im);
          stemp_im = c * A[(jrow + 2016 * k) - 1].im + (s.re * A[jrow + 2016 * k]
            .im + s.im * A[jrow + 2016 * k].re);
          Z_re = A[(jrow + 2016 * k) - 1].im;
          A_re = A[(jrow + 2016 * k) - 1].re;
          A[jrow + 2016 * k].re = c * A[jrow + 2016 * k].re - (s.re * A[(jrow +
            2016 * k) - 1].re + s.im * A[(jrow + 2016 * k) - 1].im);
          A[jrow + 2016 * k].im = c * A[jrow + 2016 * k].im - (s.re * Z_re -
            s.im * A_re);
          A[(jrow + 2016 * k) - 1].re = stemp_re;
          A[(jrow + 2016 * k) - 1].im = stemp_im;
        }

        s.re = -s.re;
        s.im = -s.im;
        for (k = 0; k + 1 <= ihi; k++) {
          stemp_re = c * A[k + 2016 * jrow].re + (s.re * A[k + 2016 * (jrow - 1)]
            .re - s.im * A[k + 2016 * (jrow - 1)].im);
          stemp_im = c * A[k + 2016 * jrow].im + (s.re * A[k + 2016 * (jrow - 1)]
            .im + s.im * A[k + 2016 * (jrow - 1)].re);
          Z_re = A[k + 2016 * jrow].im;
          A_re = A[k + 2016 * jrow].re;
          A[k + 2016 * (jrow - 1)].re = c * A[k + 2016 * (jrow - 1)].re - (s.re *
            A[k + 2016 * jrow].re + s.im * A[k + 2016 * jrow].im);
          A[k + 2016 * (jrow - 1)].im = c * A[k + 2016 * (jrow - 1)].im - (s.re *
            Z_re - s.im * A_re);
          A[k + 2016 * jrow].re = stemp_re;
          A[k + 2016 * jrow].im = stemp_im;
        }

        for (k = 0; k < 2016; k++) {
          stemp_re = c * Z[k + 2016 * jrow].re + (s.re * Z[k + 2016 * (jrow - 1)]
            .re - s.im * Z[k + 2016 * (jrow - 1)].im);
          stemp_im = c * Z[k + 2016 * jrow].im + (s.re * Z[k + 2016 * (jrow - 1)]
            .im + s.im * Z[k + 2016 * (jrow - 1)].re);
          Z_re = Z[k + 2016 * jrow].re;
          Z[k + 2016 * (jrow - 1)].re = c * Z[k + 2016 * (jrow - 1)].re - (s.re *
            Z[k + 2016 * jrow].re + s.im * Z[k + 2016 * jrow].im);
          Z[k + 2016 * (jrow - 1)].im = c * Z[k + 2016 * (jrow - 1)].im - (s.re *
            Z[k + 2016 * jrow].im - s.im * Z_re);
          Z[k + 2016 * jrow].re = stemp_re;
          Z[k + 2016 * jrow].im = stemp_im;
        }
      }
    }
  }
}

//
// File trailer for xzgghrd.cpp
//
// [EOF]
//
