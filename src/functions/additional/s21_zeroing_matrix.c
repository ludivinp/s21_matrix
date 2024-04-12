#include "../../s21_matrix.h"

RETURN_TYPE s21_zeroing_matrix(matrix_t* result) {
  if (!result || s21_matrix_validation(result) != MR_OK) {
    return MR_INCORRECT_MATRIX;
  }

  for (MTRX_SIZE_TYPE i = 0; i < result->rows; i++) {
    memset(result->matrix[i], 0,
           result->columns * sizeof(result->matrix[0][0]));
  }

  return MR_OK;
}