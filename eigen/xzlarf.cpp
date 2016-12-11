//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarf.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "xzlarf.h"
#include "xgerc.h"
#include "xgemv.h"

// Function Declarations
static int ilazlc(int m, int n, const double A[4064256], int ia0, int lda);
static int ilazlr(int m, int n, const double A[4064256], int ia0);

// Function Definitions

//
// Arguments    : int m
//                int n
//                const double A[4064256]
//                int ia0
//                int lda
// Return Type  : int
//
static int ilazlc(int m, int n, const double A[4064256], int ia0, int lda)
{
  int j;
  boolean_T exitg2;
  int coltop;
  int ia;
  int exitg1;
  j = n;
  exitg2 = false;
  while ((!exitg2) && (j > 0)) {
    coltop = ia0 + (j - 1) * lda;
    ia = coltop;
    do {
      exitg1 = 0;
      if (ia <= (coltop + m) - 1) {
        if (A[ia - 1] != 0.0) {
          exitg1 = 1;
        } else {
          ia++;
        }
      } else {
        j--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  return j;
}

//
// Arguments    : int m
//                int n
//                const double A[4064256]
//                int ia0
// Return Type  : int
//
static int ilazlr(int m, int n, const double A[4064256], int ia0)
{
  int i;
  boolean_T exitg2;
  int rowleft;
  int ia;
  int exitg1;
  i = m;
  exitg2 = false;
  while ((!exitg2) && (i > 0)) {
    rowleft = (ia0 + i) - 1;
    ia = rowleft;
    do {
      exitg1 = 0;
      if (ia <= rowleft + (n - 1) * 2016) {
        if (A[ia - 1] != 0.0) {
          exitg1 = 1;
        } else {
          ia += 2016;
        }
      } else {
        i--;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  return i;
}

//
// Arguments    : int m
//                int n
//                int iv0
//                double tau
//                double C[4064256]
//                int ic0
//                double work[2016]
// Return Type  : void
//
void b_xzlarf(int m, int n, int iv0, double tau, double C[4064256], int ic0,
              double work[2016])
{
  int lastv;
  int lastc;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = ilazlc(lastv, n, C, ic0, 2016);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    b_xgemv(lastv, lastc, C, ic0, C, iv0, work);
    b_xgerc(lastv, lastc, -tau, iv0, work, C, ic0);
  }
}

//
// Arguments    : int m
//                int n
//                int iv0
//                double tau
//                double C[4064256]
//                int ic0
//                double work[2016]
// Return Type  : void
//
void c_xzlarf(int m, int n, int iv0, double tau, double C[4064256], int ic0,
              double work[2016])
{
  int lastv;
  int lastc;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = ilazlc(lastv, n, C, ic0, 2016);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    c_xgemv(lastv, lastc, C, ic0, C, iv0, work);
    b_xgerc(lastv, lastc, -tau, iv0, work, C, ic0);
  }
}

//
// Arguments    : int n
//                int iv0
//                double tau
//                double C[4064256]
//                int ic0
//                double work[2016]
// Return Type  : void
//
void xzlarf(int n, int iv0, double tau, double C[4064256], int ic0, double work
            [2016])
{
  int lastv;
  int lastc;
  if (tau != 0.0) {
    lastv = n;
    lastc = iv0 + n;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = ilazlr(2016, lastv, C, ic0);
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    xgemv(lastc, lastv, C, ic0, C, iv0, work);
    xgerc(lastc, lastv, -tau, work, iv0, C, ic0);
  }
}

//
// File trailer for xzlarf.cpp
//
// [EOF]
//
