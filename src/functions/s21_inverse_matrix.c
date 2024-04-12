#include "../s21_matrix.h"

RETURN_TYPE s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  if (!A || s21_matrix_validation(A) != MR_OK || !result) {
    return MR_INCORRECT_MATRIX;
  } else if (A->columns != A->rows || (A->columns < 2 || A->rows < 2)) {
    return MR_CALC_ERROR;
  }

  MTRX_TYPE determinant = 0;
  RETURN_TYPE return_result = s21_determinant(A, &determinant);
  if (return_result == MR_OK && fabs(determinant) < MTRX_EPSILON) {
    return_result = MR_CALC_ERROR;
  }

  matrix_t temp_result_1 = {};
  matrix_t temp_result_2 = {};
  if (return_result == MR_OK &&
      (return_result = s21_calc_complements(A, &temp_result_1)) == MR_OK &&
      (return_result = s21_transpose(&temp_result_1, &temp_result_2)) ==
          MR_OK) {
    return_result =
        s21_mult_number(&temp_result_2, (1.0 / determinant), result);
  }

  s21_remove_matrix(&temp_result_1);
  s21_remove_matrix(&temp_result_2);

  return return_result;
}