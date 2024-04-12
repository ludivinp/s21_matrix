#ifndef S21_TESTS_RUNNER_H
#define S21_TESTS_RUNNER_H

#include <check.h>
#include <stdint.h>
#include <stdio.h>

#include "../s21_matrix.h"

#define MTRX_EPSILON_10 7  // For tests

////// Suite getters for all func
Suite *s21_create_matrix_suite();
Suite *s21_remove_matrix_suite();

Suite *s21_eq_matrix_suite();

Suite *s21_sum_matrix_suite();
Suite *s21_sub_matrix_suite();

Suite *s21_mult_number_suite();
Suite *s21_mult_matrix_suite();

Suite *s21_transpose_suite();

Suite *s21_determinant_suite();

Suite *s21_calc_complements_suite();

Suite *s21_inverse_matrix_suite();

// Additional
Suite *s21_matrix_arithmetic_suite();

Suite *s21_minor_matrix_suite();

Suite *s21_matrix_validation_suite();
Suite *s21_zeroing_matrix_suite();

/////

// Run tests
size_t run_all_tests();
void add_all_suites_in_runner(SRunner **runner);
//

#endif