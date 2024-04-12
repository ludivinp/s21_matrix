#include "../s21_matrix.h"

RETURN_TYPE s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (!A || s21_matrix_validation(A) != MR_OK || !B ||
      s21_matrix_validation(B) != MR_OK || !result) {
    return MR_INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    return MR_CALC_ERROR;
  }

  RETURN_TYPE return_result = s21_create_matrix(A->rows, B->columns, result);
  if (return_result == MR_OK) {
    s21_zeroing_matrix(result);

    for (MTRX_SIZE_TYPE i = 0; i < result->rows; i++) {
      for (MTRX_SIZE_TYPE j = 0; j < result->columns; j++) {
        for (MTRX_SIZE_TYPE o = 0; o < A->columns; o++) {
          result->matrix[i][j] += A->matrix[i][o] * B->matrix[o][j];
        }
      }
    }
  }

  return return_result;
}