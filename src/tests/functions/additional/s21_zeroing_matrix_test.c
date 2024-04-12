#include "../../s21_tests_runner.h"

START_TEST(s21_zeroing_matrix_00) {
  matrix_t test_matrix;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  ck_assert_int_eq(s21_zeroing_matrix(&test_matrix), MR_OK);

  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_zeroing_matrix_01) {
  matrix_t test_matrix;
  int rows = 5;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix.matrix[i][j] = i + j;
    }
  }

  ck_assert_int_eq(s21_zeroing_matrix(&test_matrix), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(test_matrix.matrix[i][j], 0, MTRX_EPSILON);
    }
  }

  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_zeroing_matrix_02) {
  matrix_t test_matrix;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  test_matrix.matrix[0][0] = 123;

  ck_assert_int_eq(s21_zeroing_matrix(&test_matrix), MR_OK);

  ck_assert_double_eq_tol(test_matrix.matrix[0][0], 0, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_zeroing_matrix_03) {
  matrix_t test_matrix;
  int rows = 5;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix.matrix[i][j] = i + j;
    }
  }

  test_matrix.rows = 0;

  ck_assert_int_eq(s21_zeroing_matrix(&test_matrix), MR_INCORRECT_MATRIX);

  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_zeroing_matrix_04) {
  matrix_t test_matrix;
  int rows = 5;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix.matrix[i][j] = i + j;
    }
  }

  test_matrix.columns = 0;

  ck_assert_int_eq(s21_zeroing_matrix(&test_matrix), MR_INCORRECT_MATRIX);

  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_zeroing_matrix_05) {
  matrix_t test_matrix;
  int rows = 5;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix.matrix[i][j] = i + j;
    }
  }

  test_matrix.rows = -5;
  test_matrix.columns = -5;

  ck_assert_int_eq(s21_zeroing_matrix(&test_matrix), MR_INCORRECT_MATRIX);

  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_zeroing_matrix_06) {
  matrix_t test_matrix = {.matrix = NULL, .rows = 1, .columns = 1};

  ck_assert_int_eq(s21_zeroing_matrix(&test_matrix), MR_INCORRECT_MATRIX);

  s21_remove_matrix(&test_matrix);
}
END_TEST

Suite *s21_zeroing_matrix_suite() {
  TCase *tcase = tcase_create("s21_zeroing_matrix_tcase");
  Suite *suite = suite_create("s21_zeroing_matrix");

  tcase_add_test(tcase, s21_zeroing_matrix_00);
  tcase_add_test(tcase, s21_zeroing_matrix_01);
  tcase_add_test(tcase, s21_zeroing_matrix_02);
  tcase_add_test(tcase, s21_zeroing_matrix_03);
  tcase_add_test(tcase, s21_zeroing_matrix_04);
  tcase_add_test(tcase, s21_zeroing_matrix_05);
  tcase_add_test(tcase, s21_zeroing_matrix_06);

  suite_add_tcase(suite, tcase);
  return suite;
}
