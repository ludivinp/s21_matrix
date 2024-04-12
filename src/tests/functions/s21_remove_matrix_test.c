#include "../s21_tests_runner.h"

START_TEST(s21_remove_matrix_00) {
  matrix_t test_matrix;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  s21_remove_matrix(&test_matrix);

  ck_assert_int_eq(test_matrix.rows, 0);
  ck_assert_int_eq(test_matrix.columns, 0);

  ck_assert_ptr_null(test_matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_01) {
  matrix_t test_matrix = {.matrix = NULL};

  s21_remove_matrix(&test_matrix);

  ck_assert_int_eq(test_matrix.rows, 0);
  ck_assert_int_eq(test_matrix.columns, 0);

  ck_assert_ptr_null(test_matrix.matrix);
}
END_TEST

Suite *s21_remove_matrix_suite() {
  TCase *tcase = tcase_create("s21_remove_matrix_tcase");
  Suite *suite = suite_create("s21_remove_matrix");

  tcase_add_test(tcase, s21_remove_matrix_00);

  tcase_add_test(tcase, s21_remove_matrix_01);

  suite_add_tcase(suite, tcase);
  return suite;
}
