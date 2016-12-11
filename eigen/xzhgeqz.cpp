//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzhgeqz.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "rsf2csf.h"
#include "sqrt.h"
#include "mod.h"
#include "xzlanhs.h"
#include "eigen_rtwutil.h"

// Function Definitions

//
// Arguments    : creal_T A[4064256]
//                int ilo
//                int ihi
//                creal_T Z[4064256]
//                int *info
//                creal_T alpha1[2016]
//                creal_T beta1[2016]
// Return Type  : void
//
void xzhgeqz(creal_T A[4064256], int ilo, int ihi, creal_T Z[4064256], int *info,
             creal_T alpha1[2016], creal_T beta1[2016])
{
  int i;
  double eshift_re;
  double eshift_im;
  double ctemp_re;
  double ctemp_im;
  double anorm;
  double temp2;
  double b_atol;
  double d;
  double ascale;
  boolean_T failed;
  int j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int ifirst;
  int istart;
  int ilast;
  int ilastm1;
  int iiter;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int jiter;
  int exitg1;
  boolean_T exitg3;
  boolean_T ilazro;
  boolean_T b_guard1 = false;
  double ad22_re;
  double ad22_im;
  creal_T shift;
  double c;
  double t1_re;
  boolean_T exitg2;
  double t1_im;
  boolean_T guard3 = false;
  double tempr;
  int x;
  *info = 0;
  for (i = 0; i < 2016; i++) {
    alpha1[i].re = 0.0;
    alpha1[i].im = 0.0;
    beta1[i].re = 1.0;
    beta1[i].im = 0.0;
  }

  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp_re = 0.0;
  ctemp_im = 0.0;
  anorm = xzlanhs(A, ilo, ihi);
  temp2 = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (temp2 > 2.2250738585072014E-308) {
    b_atol = temp2;
  }

  d = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    d = anorm;
  }

  ascale = 1.0 / d;
  failed = true;
  for (j = ihi; j + 1 < 2017; j++) {
    alpha1[j] = A[j + 2016 * j];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 1;
    do {
      exitg1 = 0;
      if (jiter <= 30 * ((ihi - ilo) + 1)) {
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else if (std::abs(A[ilast + 2016 * ilastm1].re) + std::abs(A[ilast +
                    2016 * ilastm1].im) <= b_atol) {
          A[ilast + 2016 * ilastm1].re = 0.0;
          A[ilast + 2016 * ilastm1].im = 0.0;
          goto60 = true;
        } else {
          j = ilastm1;
          exitg3 = false;
          while ((!exitg3) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              ilazro = true;
            } else if (std::abs(A[j + 2016 * (j - 1)].re) + std::abs(A[j + 2016 *
                        (j - 1)].im) <= b_atol) {
              A[j + 2016 * (j - 1)].re = 0.0;
              A[j + 2016 * (j - 1)].im = 0.0;
              ilazro = true;
            } else {
              ilazro = false;
            }

            if (ilazro) {
              ifirst = j + 1;
              goto70 = true;
              exitg3 = true;
            } else {
              j--;
            }
          }
        }

        if (goto60 || goto70) {
          ilazro = true;
        } else {
          ilazro = false;
        }

        if (!ilazro) {
          for (i = 0; i < 2016; i++) {
            alpha1[i].re = rtNaN;
            alpha1[i].im = 0.0;
            beta1[i].re = rtNaN;
            beta1[i].im = 0.0;
          }

          for (i = 0; i < 4064256; i++) {
            Z[i].re = rtNaN;
            Z[i].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else {
          b_guard1 = false;
          if (goto60) {
            goto60 = false;
            alpha1[ilast] = A[ilast + 2016 * ilast];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              b_guard1 = true;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              if (b_mod(iiter) != 0) {
                anorm = ascale * A[ilastm1 + 2016 * ilastm1].re;
                temp2 = ascale * A[ilastm1 + 2016 * ilastm1].im;
                if (temp2 == 0.0) {
                  shift.re = anorm / 0.0222717701593687;
                  shift.im = 0.0;
                } else if (anorm == 0.0) {
                  shift.re = 0.0;
                  shift.im = temp2 / 0.0222717701593687;
                } else {
                  shift.re = anorm / 0.0222717701593687;
                  shift.im = temp2 / 0.0222717701593687;
                }

                anorm = ascale * A[ilast + 2016 * ilast].re;
                temp2 = ascale * A[ilast + 2016 * ilast].im;
                if (temp2 == 0.0) {
                  ad22_re = anorm / 0.0222717701593687;
                  ad22_im = 0.0;
                } else if (anorm == 0.0) {
                  ad22_re = 0.0;
                  ad22_im = temp2 / 0.0222717701593687;
                } else {
                  ad22_re = anorm / 0.0222717701593687;
                  ad22_im = temp2 / 0.0222717701593687;
                }

                t1_re = 0.5 * (shift.re + ad22_re);
                t1_im = 0.5 * (shift.im + ad22_im);
                anorm = ascale * A[ilastm1 + 2016 * ilast].re;
                temp2 = ascale * A[ilastm1 + 2016 * ilast].im;
                if (temp2 == 0.0) {
                  d = anorm / 0.0222717701593687;
                  c = 0.0;
                } else if (anorm == 0.0) {
                  d = 0.0;
                  c = temp2 / 0.0222717701593687;
                } else {
                  d = anorm / 0.0222717701593687;
                  c = temp2 / 0.0222717701593687;
                }

                anorm = ascale * A[ilast + 2016 * ilastm1].re;
                temp2 = ascale * A[ilast + 2016 * ilastm1].im;
                if (temp2 == 0.0) {
                  tempr = anorm / 0.0222717701593687;
                  anorm = 0.0;
                } else if (anorm == 0.0) {
                  tempr = 0.0;
                  anorm = temp2 / 0.0222717701593687;
                } else {
                  tempr = anorm / 0.0222717701593687;
                  anorm = temp2 / 0.0222717701593687;
                }

                temp2 = shift.re * ad22_im + shift.im * ad22_re;
                shift.re = ((t1_re * t1_re - t1_im * t1_im) + (d * tempr - c *
                  anorm)) - (shift.re * ad22_re - shift.im * ad22_im);
                shift.im = ((t1_re * t1_im + t1_im * t1_re) + (d * anorm + c *
                  tempr)) - temp2;
                b_sqrt(&shift);
                if ((t1_re - ad22_re) * shift.re + (t1_im - ad22_im) * shift.im <=
                    0.0) {
                  shift.re += t1_re;
                  shift.im += t1_im;
                } else {
                  shift.re = t1_re - shift.re;
                  shift.im = t1_im - shift.im;
                }
              } else {
                anorm = ascale * A[ilast + 2016 * ilastm1].re;
                temp2 = ascale * A[ilast + 2016 * ilastm1].im;
                if (temp2 == 0.0) {
                  d = anorm / 0.0222717701593687;
                  c = 0.0;
                } else if (anorm == 0.0) {
                  d = 0.0;
                  c = temp2 / 0.0222717701593687;
                } else {
                  d = anorm / 0.0222717701593687;
                  c = temp2 / 0.0222717701593687;
                }

                eshift_re += d;
                eshift_im += c;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }

              j = ilastm1;
              i = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp_re = ascale * A[j + 2016 * j].re - shift.re *
                  0.0222717701593687;
                ctemp_im = ascale * A[j + 2016 * j].im - shift.im *
                  0.0222717701593687;
                anorm = std::abs(ctemp_re) + std::abs(ctemp_im);
                temp2 = ascale * (std::abs(A[i + 2016 * j].re) + std::abs(A[i +
                  2016 * j].im));
                tempr = anorm;
                if (temp2 > anorm) {
                  tempr = temp2;
                }

                if ((tempr < 1.0) && (tempr != 0.0)) {
                  anorm /= tempr;
                  temp2 /= tempr;
                }

                if ((std::abs(A[j + 2016 * (j - 1)].re) + std::abs(A[j + 2016 *
                      (j - 1)].im)) * temp2 <= anorm * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  i = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst;
                ctemp_re = ascale * A[(ifirst + 2016 * (ifirst - 1)) - 1].re -
                  shift.re * 0.0222717701593687;
                ctemp_im = ascale * A[(ifirst + 2016 * (ifirst - 1)) - 1].im -
                  shift.im * 0.0222717701593687;
                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              ad22_re = ascale * A[istart + 2016 * (istart - 1)].re;
              ad22_im = ascale * A[istart + 2016 * (istart - 1)].im;
              anorm = std::abs(ctemp_re);
              temp2 = std::abs(ctemp_im);
              if (temp2 > anorm) {
                anorm = temp2;
              }

              d = std::abs(ad22_re);
              temp2 = std::abs(ad22_im);
              if (temp2 > d) {
                d = temp2;
              }

              if (d > anorm) {
                anorm = d;
              }

              shift.re = ctemp_re;
              shift.im = ctemp_im;
              guard3 = false;
              if (anorm >= 7.4428285367870146E+137) {
                do {
                  shift.re *= 1.3435752215134178E-138;
                  shift.im *= 1.3435752215134178E-138;
                  ad22_re *= 1.3435752215134178E-138;
                  ad22_im *= 1.3435752215134178E-138;
                  anorm *= 1.3435752215134178E-138;
                } while (!(anorm < 7.4428285367870146E+137));

                guard3 = true;
              } else if (anorm <= 1.3435752215134178E-138) {
                if ((ad22_re == 0.0) && (ad22_im == 0.0)) {
                  c = 1.0;
                  shift.re = 0.0;
                  shift.im = 0.0;
                } else {
                  do {
                    shift.re *= 7.4428285367870146E+137;
                    shift.im *= 7.4428285367870146E+137;
                    ad22_re *= 7.4428285367870146E+137;
                    ad22_im *= 7.4428285367870146E+137;
                    anorm *= 7.4428285367870146E+137;
                  } while (!(anorm > 1.3435752215134178E-138));

                  guard3 = true;
                }
              } else {
                guard3 = true;
              }

              if (guard3) {
                anorm = shift.re * shift.re + shift.im * shift.im;
                temp2 = ad22_re * ad22_re + ad22_im * ad22_im;
                d = temp2;
                if (1.0 > temp2) {
                  d = 1.0;
                }

                if (anorm <= d * 2.0041683600089728E-292) {
                  if ((ctemp_re == 0.0) && (ctemp_im == 0.0)) {
                    c = 0.0;
                    d = rt_hypotd_snf(ad22_re, ad22_im);
                    shift.re = ad22_re / d;
                    shift.im = -ad22_im / d;
                  } else {
                    tempr = std::sqrt(temp2);
                    c = rt_hypotd_snf(shift.re, shift.im) / tempr;
                    d = std::abs(ctemp_re);
                    temp2 = std::abs(ctemp_im);
                    if (temp2 > d) {
                      d = temp2;
                    }

                    if (d > 1.0) {
                      d = rt_hypotd_snf(ctemp_re, ctemp_im);
                      shift.re = ctemp_re / d;
                      shift.im = ctemp_im / d;
                    } else {
                      anorm = 7.4428285367870146E+137 * ctemp_re;
                      temp2 = 7.4428285367870146E+137 * ctemp_im;
                      d = rt_hypotd_snf(anorm, temp2);
                      shift.re = anorm / d;
                      shift.im = temp2 / d;
                    }

                    ad22_re /= tempr;
                    ad22_im = -ad22_im / tempr;
                    anorm = shift.re;
                    shift.re = shift.re * ad22_re - shift.im * ad22_im;
                    shift.im = anorm * ad22_im + shift.im * ad22_re;
                  }
                } else {
                  tempr = std::sqrt(1.0 + temp2 / anorm);
                  c = 1.0 / tempr;
                  d = anorm + temp2;
                  anorm = tempr * shift.re / d;
                  temp2 = tempr * shift.im / d;
                  shift.re = anorm * ad22_re - temp2 * -ad22_im;
                  shift.im = anorm * -ad22_im + temp2 * ad22_re;
                }
              }

              j = istart;
              i = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  xzlartg(A[(j + 2016 * i) - 1], A[j + 2016 * i], &c, &shift,
                          &A[(j + 2016 * i) - 1]);
                  A[j + 2016 * i].re = 0.0;
                  A[j + 2016 * i].im = 0.0;
                }

                for (i = j - 1; i + 1 < 2017; i++) {
                  ad22_re = c * A[(j + 2016 * i) - 1].re + (shift.re * A[j +
                    2016 * i].re - shift.im * A[j + 2016 * i].im);
                  ad22_im = c * A[(j + 2016 * i) - 1].im + (shift.re * A[j +
                    2016 * i].im + shift.im * A[j + 2016 * i].re);
                  anorm = A[(j + 2016 * i) - 1].im;
                  temp2 = A[(j + 2016 * i) - 1].re;
                  A[j + 2016 * i].re = c * A[j + 2016 * i].re - (shift.re * A[(j
                    + 2016 * i) - 1].re + shift.im * A[(j + 2016 * i) - 1].im);
                  A[j + 2016 * i].im = c * A[j + 2016 * i].im - (shift.re *
                    anorm - shift.im * temp2);
                  A[(j + 2016 * i) - 1].re = ad22_re;
                  A[(j + 2016 * i) - 1].im = ad22_im;
                }

                shift.re = -shift.re;
                shift.im = -shift.im;
                x = j;
                if (ilast + 1 < j + 2) {
                  x = ilast - 1;
                }

                for (i = 0; i + 1 <= x + 2; i++) {
                  ad22_re = c * A[i + 2016 * j].re + (shift.re * A[i + 2016 * (j
                    - 1)].re - shift.im * A[i + 2016 * (j - 1)].im);
                  ad22_im = c * A[i + 2016 * j].im + (shift.re * A[i + 2016 * (j
                    - 1)].im + shift.im * A[i + 2016 * (j - 1)].re);
                  anorm = A[i + 2016 * j].im;
                  temp2 = A[i + 2016 * j].re;
                  A[i + 2016 * (j - 1)].re = c * A[i + 2016 * (j - 1)].re -
                    (shift.re * A[i + 2016 * j].re + shift.im * A[i + 2016 * j].
                     im);
                  A[i + 2016 * (j - 1)].im = c * A[i + 2016 * (j - 1)].im -
                    (shift.re * anorm - shift.im * temp2);
                  A[i + 2016 * j].re = ad22_re;
                  A[i + 2016 * j].im = ad22_im;
                }

                for (i = 0; i < 2016; i++) {
                  ad22_re = c * Z[i + 2016 * j].re + (shift.re * Z[i + 2016 * (j
                    - 1)].re - shift.im * Z[i + 2016 * (j - 1)].im);
                  ad22_im = c * Z[i + 2016 * j].im + (shift.re * Z[i + 2016 * (j
                    - 1)].im + shift.im * Z[i + 2016 * (j - 1)].re);
                  anorm = Z[i + 2016 * j].im;
                  temp2 = Z[i + 2016 * j].re;
                  Z[i + 2016 * (j - 1)].re = c * Z[i + 2016 * (j - 1)].re -
                    (shift.re * Z[i + 2016 * j].re + shift.im * Z[i + 2016 * j].
                     im);
                  Z[i + 2016 * (j - 1)].im = c * Z[i + 2016 * (j - 1)].im -
                    (shift.re * anorm - shift.im * temp2);
                  Z[i + 2016 * j].re = ad22_re;
                  Z[i + 2016 * j].im = ad22_im;
                }

                i = j - 1;
                j++;
              }
            }

            b_guard1 = true;
          }

          if (b_guard1) {
            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (i = 0; i + 1 <= ilast + 1; i++) {
        alpha1[i].re = rtNaN;
        alpha1[i].im = 0.0;
        beta1[i].re = rtNaN;
        beta1[i].im = 0.0;
      }

      for (i = 0; i < 4064256; i++) {
        Z[i].re = rtNaN;
        Z[i].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    for (j = 0; j + 1 < ilo; j++) {
      alpha1[j] = A[j + 2016 * j];
    }
  }
}

//
// File trailer for xzhgeqz.cpp
//
// [EOF]
//
