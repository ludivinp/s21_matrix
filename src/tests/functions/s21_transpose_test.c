#include "../s21_tests_runner.h"

START_TEST(s21_transpose_00) {
  matrix_t test_matrix_1 = {};
  matrix_t test_matrix_result = {};

  ck_assert_int_eq(s21_transpose(&test_matrix_1, &test_matrix_result),
                   MR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_transpose_01) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_transpose(&test_matrix_1, &test_matrix_result), MR_OK);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_transpose_02) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 10;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_transpose(&test_matrix_1, &test_matrix_result), MR_OK);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_transpose_03) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 5;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_transpose(&test_matrix_1, &test_matrix_result), MR_OK);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_transpose_04) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 5;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix_1.matrix[i][j] = i + j;
    }
  }

  ck_assert_int_eq(s21_transpose(&test_matrix_1, &test_matrix_result), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(test_matrix_1.matrix[i][j],
                              test_matrix_result.matrix[j][i], MTRX_EPSILON);
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_transpose_05) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix_1.matrix[i][j] = i + j;
    }
  }

  ck_assert_int_eq(s21_transpose(&test_matrix_1, &test_matrix_result), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(test_matrix_1.matrix[i][j],
                              test_matrix_result.matrix[j][i], MTRX_EPSILON);
      ;
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_transpose_06) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 100;
  int columns = 100;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix_1.matrix[i][j] = i + j;
    }
  }

  ck_assert_int_eq(s21_transpose(&test_matrix_1, &test_matrix_result), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(test_matrix_1.matrix[i][j],
                              test_matrix_result.matrix[j][i], MTRX_EPSILON);
      ;
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

Suite *s21_transpose_suite() {
  TCase *tcase = tcase_create("s21_transpose_tcase");
  Suite *suite = suite_create("s21_transpose");

  tcase_add_test(tcase, s21_transpose_00);
  tcase_add_test(tcase, s21_transpose_01);
  tcase_add_test(tcase, s21_transpose_02);
  tcase_add_test(tcase, s21_transpose_03);
  tcase_add_test(tcase, s21_transpose_04);
  tcase_add_test(tcase, s21_transpose_05);
  tcase_add_test(tcase, s21_transpose_06);

  suite_add_tcase(suite, tcase);
  return suite;
}
