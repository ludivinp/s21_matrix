#include "../../s21_matrix.h"

RETURN_TYPE s21_minor_matrix(matrix_t* src, MTRX_SIZE_TYPE excluded_row_index,
                             MTRX_SIZE_TYPE excluded_column_index,
                             matrix_t* result) {
  if (!src || s21_matrix_validation(src) != MR_OK || !result) {
    return MR_INCORRECT_MATRIX;
  } else if ((src->columns == 1 || src->rows == 1) ||
             (excluded_column_index < 0 || excluded_row_index < 0)) {
    return MR_CALC_ERROR;
  }  // else if (src->columns != src->rows) {
     //   return MR_CALC_ERROR;
     // }

  s21_zeroing_matrix(result);

  for (MTRX_SIZE_TYPE i = 0, add_i = 0; i < src->rows; i++) {
    if (i != excluded_row_index) {
      for (MTRX_SIZE_TYPE j = 0, add_j = 0; j < src->columns; j++) {
        if (j != excluded_column_index) {
          result->matrix[i - add_i][j - add_j] = src->matrix[i][j];
        } else {
          add_j = 1;
        }
      }

    } else {
      add_i = 1;
    }
  }

  return MR_OK;
}