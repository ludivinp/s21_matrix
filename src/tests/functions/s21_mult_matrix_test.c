#include "../s21_tests_runner.h"

START_TEST(s21_mult_matrix_00) {
  matrix_t test_matrix_1 = {};
  matrix_t test_matrix_2 = {};
  matrix_t test_matrix_result = {};

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix_01) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_mult_matrix_02) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 5;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, rows, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_mult_matrix_03) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 10;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, rows, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_mult_matrix_04) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 5;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_mult_matrix_05) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  int rows = 10;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_mult_matrix_06) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  matrix_t real_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(columns, rows, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, columns, &test_matrix_result),
                   MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, columns, &real_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = 123.456;

  test_matrix_2.matrix[0][0] = 123.456;

  real_matrix_result.matrix[0][0] = 15241.383936;

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  ck_assert_double_eq_tol(test_matrix_result.matrix[0][0],
                          real_matrix_result.matrix[0][0], MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_mult_matrix_07) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  matrix_t real_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(columns, rows, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, columns, &test_matrix_result),
                   MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, columns, &real_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = -123.456;

  test_matrix_2.matrix[0][0] = 123.456;

  real_matrix_result.matrix[0][0] = -15241.383936;

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  ck_assert_double_eq_tol(test_matrix_result.matrix[0][0],
                          real_matrix_result.matrix[0][0], MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_mult_matrix_08) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  matrix_t real_matrix_result;
  int rows = 2;
  int columns = 3;

  ck_assert_int_eq(s21_create_matrix(columns, rows, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, columns, &test_matrix_result),
                   MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, columns, &real_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = 1;
  test_matrix_1.matrix[0][1] = 4;
  test_matrix_1.matrix[1][0] = 2;
  test_matrix_1.matrix[1][1] = 5;
  test_matrix_1.matrix[2][0] = 3;
  test_matrix_1.matrix[2][1] = 6;

  test_matrix_2.matrix[0][0] = 1;
  test_matrix_2.matrix[0][1] = -1;
  test_matrix_2.matrix[0][2] = 1;
  test_matrix_2.matrix[1][0] = 2;
  test_matrix_2.matrix[1][1] = 3;
  test_matrix_2.matrix[1][2] = 4;

  real_matrix_result.matrix[0][0] = 9;
  real_matrix_result.matrix[0][1] = 11;
  real_matrix_result.matrix[0][2] = 17;
  real_matrix_result.matrix[1][0] = 12;
  real_matrix_result.matrix[1][1] = 13;
  real_matrix_result.matrix[1][2] = 22;
  real_matrix_result.matrix[2][0] = 15;
  real_matrix_result.matrix[2][1] = 15;
  real_matrix_result.matrix[2][2] = 27;

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(test_matrix_result.matrix[i][j],
                              real_matrix_result.matrix[i][j], MTRX_EPSILON);
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_mult_matrix_09) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  matrix_t real_matrix_result;
  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(s21_create_matrix(columns, rows, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, columns, &test_matrix_result),
                   MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, columns, &real_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = 1;
  test_matrix_1.matrix[0][1] = 2;
  test_matrix_1.matrix[0][2] = 3;
  test_matrix_1.matrix[1][0] = 4;
  test_matrix_1.matrix[1][1] = 5;
  test_matrix_1.matrix[1][2] = 6;
  test_matrix_1.matrix[2][0] = 7;
  test_matrix_1.matrix[2][1] = 8;
  test_matrix_1.matrix[2][2] = 9;

  test_matrix_2.matrix[0][0] = 9;
  test_matrix_2.matrix[0][1] = 8;
  test_matrix_2.matrix[0][2] = 7;
  test_matrix_2.matrix[1][0] = 6;
  test_matrix_2.matrix[1][1] = 5;
  test_matrix_2.matrix[1][2] = 4;
  test_matrix_2.matrix[2][0] = 3;
  test_matrix_2.matrix[2][1] = 2;
  test_matrix_2.matrix[2][2] = 1;

  real_matrix_result.matrix[0][0] = 30;
  real_matrix_result.matrix[0][1] = 24;
  real_matrix_result.matrix[0][2] = 18;
  real_matrix_result.matrix[1][0] = 84;
  real_matrix_result.matrix[1][1] = 69;
  real_matrix_result.matrix[1][2] = 54;
  real_matrix_result.matrix[2][0] = 138;
  real_matrix_result.matrix[2][1] = 114;
  real_matrix_result.matrix[2][2] = 90;

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(test_matrix_result.matrix[i][j],
                              real_matrix_result.matrix[i][j], MTRX_EPSILON);
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_mult_matrix_10) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_result;
  matrix_t real_matrix_result;
  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(s21_create_matrix(columns, rows, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, columns, &test_matrix_result),
                   MR_OK);
  ck_assert_int_eq(s21_create_matrix(columns, columns, &real_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = 123.456;
  test_matrix_1.matrix[0][1] = 0.287;
  test_matrix_1.matrix[0][2] = -1298;
  test_matrix_1.matrix[1][0] = 11;
  test_matrix_1.matrix[1][1] = -9;
  test_matrix_1.matrix[1][2] = 555;
  test_matrix_1.matrix[2][0] = 0.192;
  test_matrix_1.matrix[2][1] = -812;
  test_matrix_1.matrix[2][2] = 0;

  test_matrix_2.matrix[0][0] = 0;
  test_matrix_2.matrix[0][1] = 878;
  test_matrix_2.matrix[0][2] = 9.999;
  test_matrix_2.matrix[1][0] = 321;
  test_matrix_2.matrix[1][1] = 21;
  test_matrix_2.matrix[1][2] = 12.1;
  test_matrix_2.matrix[2][0] = 222;
  test_matrix_2.matrix[2][1] = 0;
  test_matrix_2.matrix[2][2] = 9;

  real_matrix_result.matrix[0][0] = -288063.873;
  real_matrix_result.matrix[0][1] = 108400.395;
  real_matrix_result.matrix[0][2] = -10444.090756;
  real_matrix_result.matrix[1][0] = 120321;
  real_matrix_result.matrix[1][1] = 9469;
  real_matrix_result.matrix[1][2] = 4996.089;
  real_matrix_result.matrix[2][0] = -260652;
  real_matrix_result.matrix[2][1] = -16883.424;
  real_matrix_result.matrix[2][2] = -9823.280192;

  ck_assert_int_eq(
      s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_result),
      MR_OK);

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(test_matrix_result.matrix[i][j],
                              real_matrix_result.matrix[i][j], MTRX_EPSILON);
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

Suite *s21_mult_matrix_suite() {
  TCase *tcase = tcase_create("s21_mult_matrix_tcase");
  Suite *suite = suite_create("s21_mult_matrix");

  tcase_add_test(tcase, s21_mult_matrix_00);
  tcase_add_test(tcase, s21_mult_matrix_01);
  tcase_add_test(tcase, s21_mult_matrix_02);
  tcase_add_test(tcase, s21_mult_matrix_03);
  tcase_add_test(tcase, s21_mult_matrix_04);
  tcase_add_test(tcase, s21_mult_matrix_05);
  tcase_add_test(tcase, s21_mult_matrix_06);
  tcase_add_test(tcase, s21_mult_matrix_07);
  tcase_add_test(tcase, s21_mult_matrix_08);
  tcase_add_test(tcase, s21_mult_matrix_09);
  tcase_add_test(tcase, s21_mult_matrix_10);

  suite_add_tcase(suite, tcase);
  return suite;
}
