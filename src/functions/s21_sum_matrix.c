#include "../s21_matrix.h"

RETURN_TYPE s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  return s21_matrix_arithmetic(A, B, result, '+');
}