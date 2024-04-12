#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MTRX_TYPE double
#define MTRX_SIZE_TYPE int
typedef struct matrix_struct {
  MTRX_TYPE** matrix;
  MTRX_SIZE_TYPE rows;
  MTRX_SIZE_TYPE columns;
} matrix_t;

// Enums
#define RETURN_TYPE int
typedef enum {
  MR_OK = 0,
  MR_INCORRECT_MATRIX = 1,
  MR_CALC_ERROR = 2,
  MR_MEMORY_ERROR = 3,
} matrix_return;

typedef enum {
  MCR_FAILURE = 0,
  MCR_SUCCESS = 1,
} matrix_comparison_return;
//

#define MTRX_EPSILON 10e-7

RETURN_TYPE s21_create_matrix(MTRX_SIZE_TYPE rows, MTRX_SIZE_TYPE columns,
                              matrix_t* result);
void s21_remove_matrix(matrix_t* A);

RETURN_TYPE s21_eq_matrix(matrix_t* A, matrix_t* B);

RETURN_TYPE s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
RETURN_TYPE s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);

RETURN_TYPE s21_mult_number(matrix_t* A, MTRX_TYPE number, matrix_t* result);
RETURN_TYPE s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);

RETURN_TYPE s21_transpose(matrix_t* A, matrix_t* result);

RETURN_TYPE s21_determinant(matrix_t* src, MTRX_TYPE* determinant);

RETURN_TYPE s21_calc_complements(matrix_t* A, matrix_t* result);

RETURN_TYPE s21_inverse_matrix(matrix_t* A, matrix_t* result);

// Additional funcs
RETURN_TYPE s21_zeroing_matrix(matrix_t* result);

RETURN_TYPE s21_matrix_validation(matrix_t* matrix);

RETURN_TYPE s21_matrix_arithmetic(matrix_t* A, matrix_t* B, matrix_t* result,
                                  char operation);

RETURN_TYPE s21_minor_matrix(matrix_t* src, MTRX_SIZE_TYPE excluded_row,
                             MTRX_SIZE_TYPE excluded_column, matrix_t* result);

//

#endif