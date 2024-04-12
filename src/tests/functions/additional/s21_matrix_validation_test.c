#include "../../s21_tests_runner.h"

START_TEST(s21_matrix_validation_00) {
  matrix_t test_matrix;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  ck_assert_int_eq(s21_matrix_validation(&test_matrix), MR_OK);

  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_matrix_validation_01) {
  matrix_t test_matrix;
  int rows = 5;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix.matrix[i][j] = i + j;
    }
  }

  ck_assert_int_eq(s21_matrix_validation(&test_matrix), MR_OK);
  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_matrix_validation_02) {
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

  ck_assert_int_eq(s21_matrix_validation(&test_matrix), MR_INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_matrix_validation_03) {
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

  ck_assert_int_eq(s21_matrix_validation(&test_matrix), MR_INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_matrix_validation_04) {
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

  ck_assert_int_eq(s21_matrix_validation(&test_matrix), MR_INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix);
}
END_TEST

START_TEST(s21_matrix_validation_05) {
  matrix_t test_matrix = {.matrix = NULL, .rows = 1, .columns = 1};

  ck_assert_int_eq(s21_matrix_validation(&test_matrix), MR_INCORRECT_MATRIX);
  s21_remove_matrix(&test_matrix);
}
END_TEST

Suite *s21_matrix_validation_suite() {
  TCase *tcase = tcase_create("s21_matrix_validation_tcase");
  Suite *suite = suite_create("s21_matrix_validation");

  tcase_add_test(tcase, s21_matrix_validation_00);
  tcase_add_test(tcase, s21_matrix_validation_01);
  tcase_add_test(tcase, s21_matrix_validation_02);
  tcase_add_test(tcase, s21_matrix_validation_03);
  tcase_add_test(tcase, s21_matrix_validation_04);
  tcase_add_test(tcase, s21_matrix_validation_05);

  suite_add_tcase(suite, tcase);
  return suite;
}
