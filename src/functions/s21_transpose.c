#include "../s21_matrix.h"

RETURN_TYPE s21_transpose(matrix_t* A, matrix_t* result) {
  if (!A || s21_matrix_validation(A) != MR_OK || !result) {
    return MR_INCORRECT_MATRIX;
  }

  RETURN_TYPE return_result = s21_create_matrix(A->columns, A->rows, result);
  if (return_result == MR_OK) {
    s21_zeroing_matrix(result);

    for (MTRX_SIZE_TYPE i = 0; i < result->rows; i++) {
      for (MTRX_SIZE_TYPE j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }

  return return_result;
}