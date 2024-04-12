#include "../s21_matrix.h"

RETURN_TYPE s21_eq_matrix(matrix_t* A, matrix_t* B) {
  if ((s21_matrix_validation(A) != MR_OK ||
       s21_matrix_validation(B) != MR_OK) ||               // Valid
      (A->rows != B->rows || A->columns != B->columns)) {  // Size
    return MCR_FAILURE;
  }

  RETURN_TYPE return_result = MCR_SUCCESS;
  for (MTRX_SIZE_TYPE i = 0; return_result == MCR_SUCCESS && i < A->rows; i++) {
    for (MTRX_SIZE_TYPE j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > MTRX_EPSILON) {
        return_result = MCR_FAILURE;
        break;
      }
    }
  }

  return return_result;
}