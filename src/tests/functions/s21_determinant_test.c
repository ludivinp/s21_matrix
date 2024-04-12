#include "../s21_tests_runner.h"

START_TEST(s21_determinant_00) {
  matrix_t test_matrix_1 = {};
  double result;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result),
                   MR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_01) {
  matrix_t test_matrix_1;
  double result;
  int rows = 10;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_02) {
  matrix_t test_matrix_1;
  double result;
  int rows = 5;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_03) {
  matrix_t test_matrix_1;
  double result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 0, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_04) {
  matrix_t test_matrix_1;
  double result;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 0, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_05) {
  matrix_t test_matrix_1;
  double result;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  size_t number = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix_1.matrix[i][j] = ++number;
    }
  }

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 0, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_06) {
  matrix_t test_matrix_1;
  double result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 123;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 123, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_07) {
  matrix_t test_matrix_1;
  double result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 0.1;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 0.1, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_08) {
  matrix_t test_matrix_1;
  double result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 123.456;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 123.456, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_09) {
  matrix_t test_matrix_1;
  double result;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 0;
  test_matrix_1.matrix[0][1] = 0;
  test_matrix_1.matrix[1][0] = 0;
  test_matrix_1.matrix[1][1] = 0;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 0, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_10) {
  matrix_t test_matrix_1;
  double result;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 123;
  test_matrix_1.matrix[0][1] = 987;
  test_matrix_1.matrix[1][0] = 12;
  test_matrix_1.matrix[1][1] = 98;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 210, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_11) {
  matrix_t test_matrix_1;
  double result;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 1.2345;
  test_matrix_1.matrix[0][1] = 0.12345;
  test_matrix_1.matrix[1][0] = 123.45;
  test_matrix_1.matrix[1][1] = 12345;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 15224.6625975, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_12) {
  matrix_t test_matrix_1;
  double result;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = -1.2;
  test_matrix_1.matrix[0][1] = 34.5;
  test_matrix_1.matrix[1][0] = 987;
  test_matrix_1.matrix[1][1] = -65.4;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, -33973.02, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_13) {
  matrix_t test_matrix_1;
  double result;
  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 1;
  test_matrix_1.matrix[0][1] = 2;
  test_matrix_1.matrix[0][2] = 3;
  test_matrix_1.matrix[1][0] = 4;
  test_matrix_1.matrix[1][1] = 5;
  test_matrix_1.matrix[1][2] = 6;
  test_matrix_1.matrix[2][0] = 7;
  test_matrix_1.matrix[2][1] = 8;
  test_matrix_1.matrix[2][2] = 9;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 0, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_14) {
  matrix_t test_matrix_1;
  double result;
  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 123;
  test_matrix_1.matrix[0][1] = 456;
  test_matrix_1.matrix[0][2] = 789;
  test_matrix_1.matrix[1][0] = 987;
  test_matrix_1.matrix[1][1] = 654;
  test_matrix_1.matrix[1][2] = 321;
  test_matrix_1.matrix[2][0] = 1234;
  test_matrix_1.matrix[2][1] = 4321;
  test_matrix_1.matrix[2][2] = 1234;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 2282095620, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_15) {
  matrix_t test_matrix_1;
  double result;
  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 2.3;
  test_matrix_1.matrix[0][1] = 3;
  test_matrix_1.matrix[0][2] = -2;
  test_matrix_1.matrix[1][0] = -3;
  test_matrix_1.matrix[1][1] = 0.98;
  test_matrix_1.matrix[1][2] = 1;
  test_matrix_1.matrix[2][0] = 2;
  test_matrix_1.matrix[2][1] = -1;
  test_matrix_1.matrix[2][2] = 54;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 613.936, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_determinant_16) {
  matrix_t test_matrix_1;
  double result;
  int rows = 4;
  int columns = 4;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = -12.34;
  test_matrix_1.matrix[0][1] = 1234;
  test_matrix_1.matrix[0][2] = 12.34;
  test_matrix_1.matrix[0][3] = -123;

  test_matrix_1.matrix[1][0] = 98.7;
  test_matrix_1.matrix[1][1] = 987.8;
  test_matrix_1.matrix[1][2] = -987.65;
  test_matrix_1.matrix[1][3] = 987.6;

  test_matrix_1.matrix[2][0] = 1;
  test_matrix_1.matrix[2][1] = 2;
  test_matrix_1.matrix[2][2] = 3;
  test_matrix_1.matrix[2][3] = 4;

  test_matrix_1.matrix[3][0] = 9;
  test_matrix_1.matrix[3][1] = 8;
  test_matrix_1.matrix[3][2] = 7;
  test_matrix_1.matrix[3][3] = 6;

  ck_assert_int_eq(s21_determinant(&test_matrix_1, &result), MR_OK);

  ck_assert_double_eq_tol(result, 66385096.44, MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

Suite *s21_determinant_suite() {
  TCase *tcase = tcase_create("s21_determinant_tcase");
  Suite *suite = suite_create("s21_determinant");

  tcase_add_test(tcase, s21_determinant_00);
  tcase_add_test(tcase, s21_determinant_01);
  tcase_add_test(tcase, s21_determinant_02);
  tcase_add_test(tcase, s21_determinant_03);
  tcase_add_test(tcase, s21_determinant_04);
  tcase_add_test(tcase, s21_determinant_05);
  tcase_add_test(tcase, s21_determinant_06);
  tcase_add_test(tcase, s21_determinant_07);
  tcase_add_test(tcase, s21_determinant_08);
  tcase_add_test(tcase, s21_determinant_09);
  tcase_add_test(tcase, s21_determinant_10);
  tcase_add_test(tcase, s21_determinant_11);
  tcase_add_test(tcase, s21_determinant_12);
  tcase_add_test(tcase, s21_determinant_13);
  tcase_add_test(tcase, s21_determinant_14);
  tcase_add_test(tcase, s21_determinant_15);
  tcase_add_test(tcase, s21_determinant_16);

  suite_add_tcase(suite, tcase);
  return suite;
}
