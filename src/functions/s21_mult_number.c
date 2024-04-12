#include "../s21_matrix.h"

RETURN_TYPE s21_mult_number(matrix_t* A, MTRX_TYPE number, matrix_t* result) {
  if (!A || s21_matrix_validation(A) != MR_OK || !result) {
    return MR_INCORRECT_MATRIX;
  }

  RETURN_TYPE return_result = s21_create_matrix(A->rows, A->columns, result);
  if (return_result == MR_OK) {
    s21_zeroing_matrix(result);

    for (MTRX_SIZE_TYPE i = 0; i < A->rows; i++) {
      for (MTRX_SIZE_TYPE j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return return_result;
}