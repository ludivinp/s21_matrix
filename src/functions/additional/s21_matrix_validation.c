#include "../../s21_matrix.h"

// need_to_check_size: 0 = false | 1 = true
RETURN_TYPE s21_matrix_validation(matrix_t* matrix) {
  RETURN_TYPE return_result = MR_OK;

  if ((!matrix || !matrix->matrix) ||               // Valid
      (matrix->rows < 1 || matrix->columns < 1)) {  // Size
    return_result = MR_INCORRECT_MATRIX;
  }

  return return_result;
}