#include "s21_tests_runner.h"

int main() {
  run_all_tests();

  return 0;
}

size_t run_all_tests() {
  SRunner *runner = srunner_create(NULL);

  add_all_suites_in_runner(&runner);

  srunner_run_all(runner, CK_NORMAL);

  size_t failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count;
}

void add_all_suites_in_runner(SRunner **runner) {
  ////// Suite getters for all func
  srunner_add_suite(*runner, s21_create_matrix_suite());
  srunner_add_suite(*runner, s21_remove_matrix_suite());

  srunner_add_suite(*runner, s21_eq_matrix_suite());

  srunner_add_suite(*runner, s21_sum_matrix_suite());
  srunner_add_suite(*runner, s21_sub_matrix_suite());

  srunner_add_suite(*runner, s21_mult_number_suite());
  srunner_add_suite(*runner, s21_mult_matrix_suite());

  srunner_add_suite(*runner, s21_transpose_suite());

  srunner_add_suite(*runner, s21_determinant_suite());

  srunner_add_suite(*runner, s21_calc_complements_suite());

  srunner_add_suite(*runner, s21_inverse_matrix_suite());

  // Additional
  srunner_add_suite(*runner, s21_matrix_arithmetic_suite());

  srunner_add_suite(*runner, s21_minor_matrix_suite());

  srunner_add_suite(*runner, s21_matrix_validation_suite());
  srunner_add_suite(*runner, s21_zeroing_matrix_suite());

  /////
}