#include "../s21_tests_runner.h"

START_TEST(s21_calc_complements_00) {
  matrix_t test_matrix_1 = {};
  matrix_t test_matrix_result = {};

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_01) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_calc_complements_02) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 10;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_calc_complements_03) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 5;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_calc_complements_08) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  matrix_t true_matrix_result;
  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &true_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = 1;
  test_matrix_1.matrix[0][1] = 2;
  test_matrix_1.matrix[0][2] = 3;
  test_matrix_1.matrix[1][0] = 0;
  test_matrix_1.matrix[1][1] = 4;
  test_matrix_1.matrix[1][2] = 2;
  test_matrix_1.matrix[2][0] = 5;
  test_matrix_1.matrix[2][1] = 2;
  test_matrix_1.matrix[2][2] = 1;

  true_matrix_result.matrix[0][0] = 0;
  true_matrix_result.matrix[0][1] = 10;
  true_matrix_result.matrix[0][2] = -20;
  true_matrix_result.matrix[1][0] = 4;
  true_matrix_result.matrix[1][1] = -14;
  true_matrix_result.matrix[1][2] = 8;
  true_matrix_result.matrix[2][0] = -8;
  true_matrix_result.matrix[2][1] = -2;
  true_matrix_result.matrix[2][2] = 4;

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_OK);

  ck_assert_double_eq_tol(test_matrix_result.matrix[0][0],
                          true_matrix_result.matrix[0][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[0][1],
                          true_matrix_result.matrix[0][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[0][2],
                          true_matrix_result.matrix[0][2], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][0],
                          true_matrix_result.matrix[1][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][1],
                          true_matrix_result.matrix[1][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][2],
                          true_matrix_result.matrix[1][2], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[2][0],
                          true_matrix_result.matrix[2][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[2][1],
                          true_matrix_result.matrix[2][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[2][2],
                          true_matrix_result.matrix[2][2], MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
  s21_remove_matrix(&true_matrix_result);
}
END_TEST

START_TEST(s21_calc_complements_04) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 0;
  test_matrix_1.matrix[0][1] = 0;
  test_matrix_1.matrix[1][0] = 0;
  test_matrix_1.matrix[1][1] = 0;

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(test_matrix_result.matrix[i][j], 0.0,
                              MTRX_EPSILON);
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
}
END_TEST

START_TEST(s21_calc_complements_05) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  matrix_t true_matrix_result;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &true_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = 123;
  test_matrix_1.matrix[0][1] = 987;
  test_matrix_1.matrix[1][0] = 12;
  test_matrix_1.matrix[1][1] = 98;

  true_matrix_result.matrix[0][0] = 98;
  true_matrix_result.matrix[0][1] = -12;
  true_matrix_result.matrix[1][0] = -987;
  true_matrix_result.matrix[1][1] = 123;

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_OK);

  ck_assert_double_eq_tol(test_matrix_result.matrix[0][0],
                          true_matrix_result.matrix[0][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[0][1],
                          true_matrix_result.matrix[0][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][0],
                          true_matrix_result.matrix[1][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][1],
                          true_matrix_result.matrix[1][1], MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
  s21_remove_matrix(&true_matrix_result);
}
END_TEST

START_TEST(s21_calc_complements_06) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  matrix_t true_matrix_result;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &true_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = 1.2345;
  test_matrix_1.matrix[0][1] = 0.12345;
  test_matrix_1.matrix[1][0] = 123.45;
  test_matrix_1.matrix[1][1] = 12345;

  true_matrix_result.matrix[0][0] = 12345;
  true_matrix_result.matrix[0][1] = -123.45;
  true_matrix_result.matrix[1][0] = -0.12345;
  true_matrix_result.matrix[1][1] = 1.2345;

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_OK);

  ck_assert_double_eq_tol(test_matrix_result.matrix[0][0],
                          true_matrix_result.matrix[0][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[0][1],
                          true_matrix_result.matrix[0][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][0],
                          true_matrix_result.matrix[1][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][1],
                          true_matrix_result.matrix[1][1], MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
  s21_remove_matrix(&true_matrix_result);
}
END_TEST

START_TEST(s21_calc_complements_07) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  matrix_t true_matrix_result;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &true_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = -1.2;
  test_matrix_1.matrix[0][1] = 34.5;
  test_matrix_1.matrix[1][0] = 987;
  test_matrix_1.matrix[1][1] = -65.4;

  true_matrix_result.matrix[0][0] = -65.4;
  true_matrix_result.matrix[0][1] = -987;
  true_matrix_result.matrix[1][0] = -34.5;
  true_matrix_result.matrix[1][1] = -1.2;

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_OK);

  ck_assert_double_eq_tol(test_matrix_result.matrix[0][0],
                          true_matrix_result.matrix[0][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[0][1],
                          true_matrix_result.matrix[0][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][0],
                          true_matrix_result.matrix[1][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][1],
                          true_matrix_result.matrix[1][1], MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
  s21_remove_matrix(&true_matrix_result);
}
END_TEST

START_TEST(s21_calc_complements_09) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  matrix_t true_matrix_result;
  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &true_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = 123;
  test_matrix_1.matrix[0][1] = 456;
  test_matrix_1.matrix[0][2] = 789;
  test_matrix_1.matrix[1][0] = 987;
  test_matrix_1.matrix[1][1] = 654;
  test_matrix_1.matrix[1][2] = 321;
  test_matrix_1.matrix[2][0] = 1234;
  test_matrix_1.matrix[2][1] = 4321;
  test_matrix_1.matrix[2][2] = 1234;

  true_matrix_result.matrix[0][0] = -580005;
  true_matrix_result.matrix[0][1] = -821844;
  true_matrix_result.matrix[0][2] = 3457791;
  true_matrix_result.matrix[1][0] = 2846565;
  true_matrix_result.matrix[1][1] = -821844;
  true_matrix_result.matrix[1][2] = 31221;
  true_matrix_result.matrix[2][0] = -369630;
  true_matrix_result.matrix[2][1] = 739260;
  true_matrix_result.matrix[2][2] = -369630;

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_OK);

  ck_assert_double_eq_tol(test_matrix_result.matrix[0][0],
                          true_matrix_result.matrix[0][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[0][1],
                          true_matrix_result.matrix[0][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[0][2],
                          true_matrix_result.matrix[0][2], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][0],
                          true_matrix_result.matrix[1][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][1],
                          true_matrix_result.matrix[1][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][2],
                          true_matrix_result.matrix[1][2], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[2][0],
                          true_matrix_result.matrix[2][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[2][1],
                          true_matrix_result.matrix[2][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[2][2],
                          true_matrix_result.matrix[2][2], MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
  s21_remove_matrix(&true_matrix_result);
}
END_TEST
START_TEST(s21_calc_complements_10) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  matrix_t true_matrix_result;
  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &true_matrix_result),
                   MR_OK);

  test_matrix_1.matrix[0][0] = 2.3;
  test_matrix_1.matrix[0][1] = 3;
  test_matrix_1.matrix[0][2] = -2;
  test_matrix_1.matrix[1][0] = -3;
  test_matrix_1.matrix[1][1] = 0.98;
  test_matrix_1.matrix[1][2] = 1;
  test_matrix_1.matrix[2][0] = 2;
  test_matrix_1.matrix[2][1] = -1;
  test_matrix_1.matrix[2][2] = 54;

  true_matrix_result.matrix[0][0] = 53.92;
  true_matrix_result.matrix[0][1] = 164;
  true_matrix_result.matrix[0][2] = 1.04;
  true_matrix_result.matrix[1][0] = -160;
  true_matrix_result.matrix[1][1] = 128.2;
  true_matrix_result.matrix[1][2] = 8.3;
  true_matrix_result.matrix[2][0] = 4.96;
  true_matrix_result.matrix[2][1] = 3.7;
  true_matrix_result.matrix[2][2] = 11.254;

  ck_assert_int_eq(s21_calc_complements(&test_matrix_1, &test_matrix_result),
                   MR_OK);

  ck_assert_double_eq_tol(test_matrix_result.matrix[0][0],
                          true_matrix_result.matrix[0][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[0][1],
                          true_matrix_result.matrix[0][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[0][2],
                          true_matrix_result.matrix[0][2], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][0],
                          true_matrix_result.matrix[1][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][1],
                          true_matrix_result.matrix[1][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[1][2],
                          true_matrix_result.matrix[1][2], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[2][0],
                          true_matrix_result.matrix[2][0], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[2][1],
                          true_matrix_result.matrix[2][1], MTRX_EPSILON);
  ck_assert_double_eq_tol(test_matrix_result.matrix[2][2],
                          true_matrix_result.matrix[2][2], MTRX_EPSILON);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_result);
  s21_remove_matrix(&true_matrix_result);
}
END_TEST

Suite *s21_calc_complements_suite() {
  TCase *tcase = tcase_create("s21_calc_complements_tcase");
  Suite *suite = suite_create("s21_calc_complements");

  tcase_add_test(tcase, s21_calc_complements_00);
  tcase_add_test(tcase, s21_calc_complements_01);
  tcase_add_test(tcase, s21_calc_complements_02);
  tcase_add_test(tcase, s21_calc_complements_03);
  tcase_add_test(tcase, s21_calc_complements_04);
  tcase_add_test(tcase, s21_calc_complements_05);
  tcase_add_test(tcase, s21_calc_complements_06);
  tcase_add_test(tcase, s21_calc_complements_07);
  tcase_add_test(tcase, s21_calc_complements_08);
  tcase_add_test(tcase, s21_calc_complements_09);
  tcase_add_test(tcase, s21_calc_complements_10);

  suite_add_tcase(suite, tcase);
  return suite;
}
