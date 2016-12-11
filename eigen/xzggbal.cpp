//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzggbal.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xzggbal.h"

// Function Definitions

//
// Arguments    : creal_T A[4064256]
//                int *ilo
//                int *ihi
//                int rscale[2016]
// Return Type  : void
//
void xzggbal(creal_T A[4064256], int *ilo, int *ihi, int rscale[2016])
{
  int i;
  int exitg2;
  int j;
  boolean_T found;
  int ii;
  boolean_T exitg5;
  int nzcount;
  int jj;
  double atmp_re;
  boolean_T exitg6;
  double atmp_im;
  int exitg1;
  boolean_T guard2 = false;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T guard1 = false;
  for (i = 0; i < 2016; i++) {
    rscale[i] = 1;
  }

  *ilo = 1;
  *ihi = 2016;
  do {
    exitg2 = 0;
    i = 0;
    j = 0;
    found = false;
    ii = *ihi;
    exitg5 = false;
    while ((!exitg5) && (ii > 0)) {
      nzcount = 0;
      i = ii;
      j = *ihi;
      jj = 1;
      exitg6 = false;
      while ((!exitg6) && (jj <= *ihi)) {
        guard2 = false;
        if ((A[(ii + 2016 * (jj - 1)) - 1].re != 0.0) || (A[(ii + 2016 * (jj - 1))
             - 1].im != 0.0) || (ii == jj)) {
          if (nzcount == 0) {
            j = jj;
            nzcount = 1;
            guard2 = true;
          } else {
            nzcount = 2;
            exitg6 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          jj++;
        }
      }

      if (nzcount < 2) {
        found = true;
        exitg5 = true;
      } else {
        ii--;
      }
    }

    if (!found) {
      exitg2 = 2;
    } else {
      if (i != *ihi) {
        for (ii = 0; ii < 2016; ii++) {
          atmp_re = A[(i + 2016 * ii) - 1].re;
          atmp_im = A[(i + 2016 * ii) - 1].im;
          A[(i + 2016 * ii) - 1] = A[(*ihi + 2016 * ii) - 1];
          A[(*ihi + 2016 * ii) - 1].re = atmp_re;
          A[(*ihi + 2016 * ii) - 1].im = atmp_im;
        }
      }

      if (j != *ihi) {
        for (ii = 0; ii + 1 <= *ihi; ii++) {
          atmp_re = A[ii + 2016 * (j - 1)].re;
          atmp_im = A[ii + 2016 * (j - 1)].im;
          A[ii + 2016 * (j - 1)] = A[ii + 2016 * (*ihi - 1)];
          A[ii + 2016 * (*ihi - 1)].re = atmp_re;
          A[ii + 2016 * (*ihi - 1)].im = atmp_im;
        }
      }

      rscale[*ihi - 1] = j;
      (*ihi)--;
      if (*ihi == 1) {
        rscale[0] = 1;
        exitg2 = 1;
      }
    }
  } while (exitg2 == 0);

  if (exitg2 == 1) {
  } else {
    do {
      exitg1 = 0;
      i = 0;
      j = 0;
      found = false;
      jj = *ilo;
      exitg3 = false;
      while ((!exitg3) && (jj <= *ihi)) {
        nzcount = 0;
        i = *ihi;
        j = jj;
        ii = *ilo;
        exitg4 = false;
        while ((!exitg4) && (ii <= *ihi)) {
          guard1 = false;
          if ((A[(ii + 2016 * (jj - 1)) - 1].re != 0.0) || (A[(ii + 2016 * (jj -
                 1)) - 1].im != 0.0) || (ii == jj)) {
            if (nzcount == 0) {
              i = ii;
              nzcount = 1;
              guard1 = true;
            } else {
              nzcount = 2;
              exitg4 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            ii++;
          }
        }

        if (nzcount < 2) {
          found = true;
          exitg3 = true;
        } else {
          jj++;
        }
      }

      if (!found) {
        exitg1 = 1;
      } else {
        if (i != *ilo) {
          for (ii = *ilo - 1; ii + 1 < 2017; ii++) {
            atmp_re = A[(i + 2016 * ii) - 1].re;
            atmp_im = A[(i + 2016 * ii) - 1].im;
            A[(i + 2016 * ii) - 1] = A[(*ilo + 2016 * ii) - 1];
            A[(*ilo + 2016 * ii) - 1].re = atmp_re;
            A[(*ilo + 2016 * ii) - 1].im = atmp_im;
          }
        }

        if (j != *ilo) {
          for (ii = 0; ii + 1 <= *ihi; ii++) {
            atmp_re = A[ii + 2016 * (j - 1)].re;
            atmp_im = A[ii + 2016 * (j - 1)].im;
            A[ii + 2016 * (j - 1)] = A[ii + 2016 * (*ilo - 1)];
            A[ii + 2016 * (*ilo - 1)].re = atmp_re;
            A[ii + 2016 * (*ilo - 1)].im = atmp_im;
          }
        }

        rscale[*ilo - 1] = j;
        (*ilo)++;
        if (*ilo == *ihi) {
          rscale[*ilo - 1] = *ilo;
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

//
// File trailer for xzggbal.cpp
//
// [EOF]
//
