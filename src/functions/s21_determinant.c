#include "../s21_matrix.h"

RETURN_TYPE s21_determinant(matrix_t* src, MTRX_TYPE* determinant) {
  if (!src || s21_matrix_validation(src) != MR_OK || !determinant) {
    return MR_INCORRECT_MATRIX;
  } else if (src->columns != src->rows) {
    return MR_CALC_ERROR;
  }
  RETURN_TYPE return_result = MR_OK;

  *determinant = 0;

  if (src->rows == 1)
    *determinant = src->matrix[0][0];

  else if (src->rows == 2) {
    *determinant = src->matrix[0][0] * src->matrix[1][1] -
                   src->matrix[0][1] * src->matrix[1][0];
  } else {
    matrix_t temp_minor = {};
    return_result =
        s21_create_matrix(src->rows - 1, src->columns - 1, &temp_minor);
    if (return_result == MR_OK) {
      // (−1)^i+j = Чётное положительное / Нечётное = отрицательное
      int sign = 1;

      MTRX_TYPE temp_determinant = 0;
      for (int i = 0; i < src->rows; i++) {
        if (src->matrix[0][i] &&
            (return_result = s21_minor_matrix(src, 0, i, &temp_minor)) ==
                MR_OK &&
            (return_result = s21_determinant(&temp_minor, &temp_determinant)) ==
                MR_OK) {
          *determinant +=
              (MTRX_TYPE)sign * src->matrix[0][i] * temp_determinant;

          sign = -sign;  // (i + j) % 2 ? -1 : 1;
        }
      }

      s21_remove_matrix(&temp_minor);
    }
  }
  return return_result;
}