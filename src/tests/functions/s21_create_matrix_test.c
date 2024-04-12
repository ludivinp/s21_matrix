#include "../s21_tests_runner.h"

START_TEST(s21_create_matrix_00) {
  matrix_t test_matrix;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  ck_assert_int_eq(test_matrix.rows, rows);
  ck_assert_int_eq(test_matrix.columns, columns);

  ck_assert_ptr_nonnull(test_matrix.matrix);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(test_matrix.matrix[i][j], 0);
    }
  }
}
END_TEST

START_TEST(s21_create_matrix_01) {
  matrix_t test_matrix;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  ck_assert_int_eq(test_matrix.rows, rows);
  ck_assert_int_eq(test_matrix.columns, columns);

  ck_assert_ptr_nonnull(test_matrix.matrix);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(test_matrix.matrix[i][j], 0);
    }
  }
}
END_TEST

START_TEST(s21_create_matrix_02) {
  matrix_t test_matrix;
  int rows = 1;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  ck_assert_int_eq(test_matrix.rows, rows);
  ck_assert_int_eq(test_matrix.columns, columns);

  ck_assert_ptr_nonnull(test_matrix.matrix);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(test_matrix.matrix[i][j], 0);
    }
  }
}
END_TEST

START_TEST(s21_create_matrix_03) {
  matrix_t test_matrix;
  int rows = 10;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  ck_assert_int_eq(test_matrix.rows, rows);
  ck_assert_int_eq(test_matrix.columns, columns);

  ck_assert_ptr_nonnull(test_matrix.matrix);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(test_matrix.matrix[i][j], 0);
    }
  }
}
END_TEST

START_TEST(s21_create_matrix_04) {
  matrix_t test_matrix;
  int rows = 0;
  int columns = 0;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix),
                   MR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_05) {
  matrix_t test_matrix;
  int rows = 1;
  int columns = -1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix),
                   MR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_06) {
  matrix_t test_matrix;
  int rows = -1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix),
                   MR_INCORRECT_MATRIX);
}
END_TEST

Suite *s21_create_matrix_suite() {
  TCase *tcase = tcase_create("s21_create_matrix_tcase");
  Suite *suite = suite_create("s21_create_matrix");

  tcase_add_test(tcase, s21_create_matrix_00);
  tcase_add_test(tcase, s21_create_matrix_01);
  tcase_add_test(tcase, s21_create_matrix_02);
  tcase_add_test(tcase, s21_create_matrix_03);
  tcase_add_test(tcase, s21_create_matrix_04);
  tcase_add_test(tcase, s21_create_matrix_05);
  tcase_add_test(tcase, s21_create_matrix_06);

  suite_add_tcase(suite, tcase);
  return suite;
}
