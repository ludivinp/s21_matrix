#include "../s21_matrix.h"

RETURN_TYPE s21_create_matrix(MTRX_SIZE_TYPE rows, MTRX_SIZE_TYPE columns,
                              matrix_t* result) {
  if (!result || rows < 1 || columns < 1) {
    return MR_INCORRECT_MATRIX;
  }

  RETURN_TYPE return_result = MR_OK;
  {
    result->matrix = (MTRX_TYPE**)calloc(
        (rows * sizeof(MTRX_TYPE*)) + (columns * rows * sizeof(MTRX_TYPE)), 1);

    if (result->matrix) {
      result->matrix[0] = (double*)(result->matrix + rows);
      for (MTRX_SIZE_TYPE i = 1; i < rows; i++) {
        result->matrix[i] = result->matrix[0] + i * columns;
      }

    } else {
      return_result = MR_MEMORY_ERROR;
    }
  }

  result->rows = rows;
  result->columns = columns;

  return return_result;
}