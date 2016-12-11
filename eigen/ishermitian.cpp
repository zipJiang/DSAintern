//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ishermitian.cpp
//
// MATLAB Coder version            : 3.2
// C/C++ source code generated on  : 11-Dec-2016 11:00:27
//

// Include Files
#include "rt_nonfinite.h"
#include "eigen.h"
#include "ishermitian.h"

// Function Definitions

//
// Arguments    : const double A[4064256]
// Return Type  : boolean_T
//
boolean_T ishermitian(const double A[4064256])
{
  boolean_T p;
  int j;
  boolean_T exitg2;
  int i;
  int exitg1;
  p = true;
  j = 0;
  exitg2 = false;
  while ((!exitg2) && (j < 2016)) {
    i = 0;
    do {
      exitg1 = 0;
      if (i <= j) {
        if (!(A[i + 2016 * j] == A[j + 2016 * i])) {
          p = false;
          exitg1 = 1;
        } else {
          i++;
        }
      } else {
        j++;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  return p;
}

//
// File trailer for ishermitian.cpp
//
// [EOF]
//
