//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xztgevc.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xztgevc.h"

// Function Definitions

//
// Arguments    : const creal_T A[4064256]
//                creal_T V[4064256]
// Return Type  : void
//
void xztgevc(const creal_T A[4064256], creal_T V[4064256])
{
  double rworka[2016];
  double anorm;
  int j;
  double xmx;
  int jc;
  double ascale;
  double d_re;
  int je;
  double temp;
  double salpha_re;
  double salpha_im;
  double acoeff;
  boolean_T lscalea;
  boolean_T lscaleb;
  double scale;
  double acoefa;
  creal_T work1[2016];
  int jr;
  double dmin;
  creal_T work2[2016];
  int b_j;
  double d_im;
  double work1_re;
  memset(&rworka[0], 0, 2016U * sizeof(double));
  anorm = std::abs(A[0].re) + std::abs(A[0].im);
  for (j = 0; j < 2015; j++) {
    for (jc = 0; jc <= j; jc++) {
      rworka[j + 1] += std::abs(A[jc + 2016 * (j + 1)].re) + std::abs(A[jc +
        2016 * (j + 1)].im);
    }

    d_re = rworka[j + 1] + (std::abs(A[(j + 2016 * (j + 1)) + 1].re) + std::abs
      (A[(j + 2016 * (j + 1)) + 1].im));
    if (d_re > anorm) {
      anorm = d_re;
    }
  }

  xmx = anorm;
  if (2.2250738585072014E-308 > anorm) {
    xmx = 2.2250738585072014E-308;
  }

  ascale = 1.0 / xmx;
  for (je = 0; je < 2016; je++) {
    xmx = (std::abs(A[(2016 * (2015 - je) - je) + 2015].re) + std::abs(A[(2016 *
             (2015 - je) - je) + 2015].im)) * ascale;
    if (1.0 > xmx) {
      xmx = 1.0;
    }

    temp = 1.0 / xmx;
    salpha_re = ascale * (temp * A[(2016 * (2015 - je) - je) + 2015].re);
    salpha_im = ascale * (temp * A[(2016 * (2015 - je) - je) + 2015].im);
    acoeff = temp * ascale;
    if ((std::abs(temp) >= 2.2250738585072014E-308) && (std::abs(acoeff) <
         2.0202017068890446E-289)) {
      lscalea = true;
    } else {
      lscalea = false;
    }

    if ((std::abs(salpha_re) + std::abs(salpha_im) >= 2.2250738585072014E-308) &&
        (std::abs(salpha_re) + std::abs(salpha_im) < 2.0202017068890446E-289)) {
      lscaleb = true;
    } else {
      lscaleb = false;
    }

    scale = 1.0;
    if (lscalea) {
      xmx = anorm;
      if (4.9500007676952374E+288 < anorm) {
        xmx = 4.9500007676952374E+288;
      }

      scale = 2.0202017068890446E-289 / std::abs(temp) * xmx;
    }

    if (lscaleb) {
      d_re = 2.0202017068890446E-289 / (std::abs(salpha_re) + std::abs(salpha_im));
      if (d_re > scale) {
        scale = d_re;
      }
    }

    if (lscalea || lscaleb) {
      xmx = std::abs(acoeff);
      d_re = std::abs(salpha_re) + std::abs(salpha_im);
      if (1.0 > xmx) {
        xmx = 1.0;
      }

      if (d_re > xmx) {
        xmx = d_re;
      }

      d_re = 1.0 / (2.2250738585072014E-308 * xmx);
      if (d_re < scale) {
        scale = d_re;
      }

      if (lscalea) {
        acoeff = ascale * (scale * temp);
      } else {
        acoeff *= scale;
      }

      salpha_re *= scale;
      salpha_im *= scale;
    }

    acoefa = std::abs(acoeff);
    for (jr = 0; jr < 2016; jr++) {
      work1[jr].re = 0.0;
      work1[jr].im = 0.0;
    }

    work1[2015 - je].re = 1.0;
    work1[2015 - je].im = 0.0;
    dmin = 2.2204460492503131E-16 * acoefa * anorm;
    d_re = 2.2204460492503131E-16 * (std::abs(salpha_re) + std::abs(salpha_im));
    if (d_re > dmin) {
      dmin = d_re;
    }

    if (2.2250738585072014E-308 > dmin) {
      dmin = 2.2250738585072014E-308;
    }

    for (jr = 0; jr <= 2014 - je; jr++) {
      work1[jr].re = acoeff * A[jr + 2016 * (2015 - je)].re;
      work1[jr].im = acoeff * A[jr + 2016 * (2015 - je)].im;
    }

    work1[2015 - je].re = 1.0;
    work1[2015 - je].im = 0.0;
    jc = (int)((1.0 + (-1.0 - ((2016.0 + -(double)je) - 1.0))) / -1.0);
    for (j = -2014; j + 2014 < jc; j++) {
      b_j = -(je + j);
      d_re = acoeff * A[b_j + 2016 * b_j].re - salpha_re;
      d_im = acoeff * A[b_j + 2016 * b_j].im - salpha_im;
      if (std::abs(d_re) + std::abs(d_im) <= dmin) {
        d_re = dmin;
        d_im = 0.0;
      }

      if ((std::abs(d_re) + std::abs(d_im) < 1.0) && (std::abs(work1[b_j].re) +
           std::abs(work1[b_j].im) >= 2.229282161287594E+304 * (std::abs(d_re) +
            std::abs(d_im)))) {
        temp = 1.0 / (std::abs(work1[b_j].re) + std::abs(work1[b_j].im));
        for (jr = 0; jr <= 2015 - je; jr++) {
          work1[jr].re *= temp;
          work1[jr].im *= temp;
        }
      }

      work1_re = -work1[b_j].re;
      if (d_im == 0.0) {
        if (-work1[b_j].im == 0.0) {
          work1[b_j].re = -work1[b_j].re / d_re;
          work1[b_j].im = 0.0;
        } else if (-work1[b_j].re == 0.0) {
          work1[b_j].re = 0.0;
          work1[b_j].im = -work1[b_j].im / d_re;
        } else {
          work1[b_j].re = -work1[b_j].re / d_re;
          work1[b_j].im = -work1[b_j].im / d_re;
        }
      } else if (d_re == 0.0) {
        if (-work1[b_j].re == 0.0) {
          work1[b_j].re = -work1[b_j].im / d_im;
          work1[b_j].im = 0.0;
        } else if (-work1[b_j].im == 0.0) {
          work1[b_j].re = 0.0;
          work1[b_j].im = -(work1_re / d_im);
        } else {
          work1[b_j].re = -work1[b_j].im / d_im;
          work1[b_j].im = -(work1_re / d_im);
        }
      } else {
        temp = std::abs(d_re);
        xmx = std::abs(d_im);
        if (temp > xmx) {
          scale = d_im / d_re;
          xmx = d_re + scale * d_im;
          work1[b_j].re = (-work1[b_j].re + scale * -work1[b_j].im) / xmx;
          work1[b_j].im = (-work1[b_j].im - scale * work1_re) / xmx;
        } else if (xmx == temp) {
          if (d_re > 0.0) {
            scale = 0.5;
          } else {
            scale = -0.5;
          }

          if (d_im > 0.0) {
            xmx = 0.5;
          } else {
            xmx = -0.5;
          }

          work1[b_j].re = (-work1[b_j].re * scale + -work1[b_j].im * xmx) / temp;
          work1[b_j].im = (-work1[b_j].im * scale - work1_re * xmx) / temp;
        } else {
          scale = d_re / d_im;
          xmx = d_im + scale * d_re;
          work1[b_j].re = (scale * -work1[b_j].re + -work1[b_j].im) / xmx;
          work1[b_j].im = (scale * -work1[b_j].im - work1_re) / xmx;
        }
      }

      if (b_j + 1 > 1) {
        if (std::abs(work1[b_j].re) + std::abs(work1[b_j].im) > 1.0) {
          temp = 1.0 / (std::abs(work1[b_j].re) + std::abs(work1[b_j].im));
          if (acoefa * rworka[b_j] >= 2.229282161287594E+304 * temp) {
            for (jr = 0; jr <= 2015 - je; jr++) {
              work1[jr].re *= temp;
              work1[jr].im *= temp;
            }
          }
        }

        d_re = acoeff * work1[b_j].re;
        d_im = acoeff * work1[b_j].im;
        for (jr = 0; jr < b_j; jr++) {
          work1[jr].re += d_re * A[jr + 2016 * b_j].re - d_im * A[jr + 2016 *
            b_j].im;
          work1[jr].im += d_re * A[jr + 2016 * b_j].im + d_im * A[jr + 2016 *
            b_j].re;
        }
      }
    }

    for (jr = 0; jr < 2016; jr++) {
      work2[jr].re = 0.0;
      work2[jr].im = 0.0;
    }

    for (jc = 0; jc <= 2015 - je; jc++) {
      for (jr = 0; jr < 2016; jr++) {
        work2[jr].re += V[jr + 2016 * jc].re * work1[jc].re - V[jr + 2016 * jc].
          im * work1[jc].im;
        work2[jr].im += V[jr + 2016 * jc].re * work1[jc].im + V[jr + 2016 * jc].
          im * work1[jc].re;
      }
    }

    xmx = std::abs(work2[0].re) + std::abs(work2[0].im);
    for (jr = 0; jr < 2015; jr++) {
      d_re = std::abs(work2[jr + 1].re) + std::abs(work2[jr + 1].im);
      if (d_re > xmx) {
        xmx = d_re;
      }
    }

    if (xmx > 2.2250738585072014E-308) {
      temp = 1.0 / xmx;
      for (jr = 0; jr < 2016; jr++) {
        V[jr + 2016 * (2015 - je)].re = temp * work2[jr].re;
        V[jr + 2016 * (2015 - je)].im = temp * work2[jr].im;
      }
    } else {
      for (jr = 0; jr < 2016; jr++) {
        V[jr + 2016 * (2015 - je)].re = 0.0;
        V[jr + 2016 * (2015 - je)].im = 0.0;
      }
    }
  }
}

//
// File trailer for xztgevc.cpp
//
// [EOF]
//
