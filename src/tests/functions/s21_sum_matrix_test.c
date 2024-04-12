#include "../s21_tests_runner.h"

START_TEST(s21_sum_matrix_00) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_sum_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_sum_matrix_01) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 1;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_sum_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_sum_matrix_02) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 10;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_sum_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_sum_matrix_03) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  test_matrix_1.matrix[0][0] = 1;
  test_matrix_2.matrix[0][0] = 1;

  ck_assert_int_eq(
      s21_sum_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  ck_assert_double_eq(test_matrix_result.matrix[0][0],
                      test_matrix_1.matrix[0][0] + test_matrix_2.matrix[0][0]);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_sum_matrix_04) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  test_matrix_1.matrix[0][0] = -1;
  test_matrix_2.matrix[0][0] = -1;

  ck_assert_int_eq(
      s21_sum_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  ck_assert_double_eq(test_matrix_result.matrix[0][0],
                      test_matrix_1.matrix[0][0] + test_matrix_2.matrix[0][0]);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_sum_matrix_05) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  test_matrix_1.matrix[0][0] = -MTRX_EPSILON;
  test_matrix_2.matrix[0][0] = MTRX_EPSILON;

  ck_assert_int_eq(
      s21_sum_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  ck_assert_double_eq(test_matrix_result.matrix[0][0],
                      test_matrix_1.matrix[0][0] + test_matrix_2.matrix[0][0]);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_sum_matrix_06) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 123;
  int columns = 123;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix_1.matrix[i][j] = test_matrix_2.matrix[i][j] = i + j;
    }
  }

  ck_assert_int_eq(
      s21_sum_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq(
          test_matrix_result.matrix[i][j],
          test_matrix_1.matrix[i][j] + test_matrix_2.matrix[i][j]);
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

Suite *s21_sum_matrix_suite() {
  TCase *tcase = tcase_create("s21_sum_matrix_tcase");
  Suite *suite = suite_create("s21_sum_matrix");

  tcase_add_test(tcase, s21_sum_matrix_00);
  tcase_add_test(tcase, s21_sum_matrix_01);
  tcase_add_test(tcase, s21_sum_matrix_02);
  tcase_add_test(tcase, s21_sum_matrix_03);
  tcase_add_test(tcase, s21_sum_matrix_04);
  tcase_add_test(tcase, s21_sum_matrix_05);
  tcase_add_test(tcase, s21_sum_matrix_06);

  suite_add_tcase(suite, tcase);
  return suite;
}
