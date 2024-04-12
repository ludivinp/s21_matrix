#include "../s21_matrix.h"

RETURN_TYPE s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!A || s21_matrix_validation(A) != MR_OK || !result) {
    return MR_INCORRECT_MATRIX;
  } else if (A->columns != A->rows || (A->columns < 2 || A->rows < 2)) {
    return MR_CALC_ERROR;
  }

  RETURN_TYPE return_result = s21_create_matrix(A->rows, A->columns, result);
  if (return_result == MR_OK) {
    s21_zeroing_matrix(result);
  }

  matrix_t temp_minor = {};
  return_result = s21_create_matrix(A->rows - 1, A->columns - 1, &temp_minor);
  if (return_result == MR_OK) {
    for (MTRX_SIZE_TYPE i = 0; i < A->rows; i++) {
      for (MTRX_SIZE_TYPE j = 0; j < A->columns; j++) {
        s21_zeroing_matrix(&temp_minor);

        if ((return_result = s21_minor_matrix(A, i, j, &temp_minor)) == MR_OK &&
            (return_result = s21_determinant(&temp_minor,
                                             &result->matrix[i][j])) == MR_OK) {
          result->matrix[i][j] *= pow(-1, i + j);
        }
      }
    }

    s21_remove_matrix(&temp_minor);
  }

  return return_result;
}