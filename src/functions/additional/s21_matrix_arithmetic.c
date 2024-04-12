#include "../../s21_matrix.h"

// operation = '+', '-',
RETURN_TYPE s21_matrix_arithmetic(matrix_t* A, matrix_t* B, matrix_t* result,
                                  char operation) {
  if (!A || s21_matrix_validation(A) != MR_OK || !B ||
      s21_matrix_validation(B) != MR_OK || !result) {  // Valid
    return MR_INCORRECT_MATRIX;
  } else if ((A->rows != B->rows || A->columns != B->columns)) {  // Size
    return MR_CALC_ERROR;
  }

  RETURN_TYPE return_result = s21_create_matrix(A->rows, A->columns, result);
  if (return_result == MR_OK) {
    s21_zeroing_matrix(result);
  }

  for (MTRX_SIZE_TYPE i = 0; return_result == MR_OK && i < A->rows; i++) {
    for (MTRX_SIZE_TYPE j = 0; j < A->columns; j++) {
      if (operation == '+') {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      } else if (operation == '-') {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      } else {
        return_result = MR_CALC_ERROR;
      }
    }
  }

  return return_result;
}