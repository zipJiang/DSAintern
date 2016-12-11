/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_eigen_api.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 11-Dec-2016 11:00:27
 */

#ifndef _CODER_EIGEN_API_H
#define _CODER_EIGEN_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_eigen_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void eigen(real_T A[4064256], creal_T V[4064256], creal_T D[4064256]);
extern void eigen_api(const mxArray *prhs[1], const mxArray *plhs[2]);
extern void eigen_atexit(void);
extern void eigen_initialize(void);
extern void eigen_terminate(void);
extern void eigen_xil_terminate(void);

#endif

/*
 * File trailer for _coder_eigen_api.h
 *
 * [EOF]
 */
