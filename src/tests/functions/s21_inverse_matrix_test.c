#include "../s21_tests_runner.h"

START_TEST(s21_inverse_matrix_00) {
  matrix_t test_matrix_1 = {};
  matrix_t test_matrix_result = {};

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
                   MR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_01) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
                   MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_inverse_matrix_02) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 10;
  int columns = 5;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
                   MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_inverse_matrix_03) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 5;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
                   MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_inverse_matrix_04) {
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
  true_matrix_result.matrix[0][1] = -0.1;
  true_matrix_result.matrix[0][2] = 0.2;
  true_matrix_result.matrix[1][0] = -0.25;
  true_matrix_result.matrix[1][1] = 0.35;
  true_matrix_result.matrix[1][2] = 0.05;
  true_matrix_result.matrix[2][0] = 0.5;
  true_matrix_result.matrix[2][1] = -0.2;
  true_matrix_result.matrix[2][2] = -0.1;

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
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

START_TEST(s21_inverse_matrix_05) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_result;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);

  test_matrix_1.matrix[0][0] = 0;
  test_matrix_1.matrix[0][1] = 0;
  test_matrix_1.matrix[1][0] = 0;
  test_matrix_1.matrix[1][1] = 0;

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
                   MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_inverse_matrix_06) {
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

  true_matrix_result.matrix[0][0] = 0.466666667;
  true_matrix_result.matrix[0][1] = -4.7;
  true_matrix_result.matrix[1][0] = -0.057142857;
  true_matrix_result.matrix[1][1] = 0.585714286;

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
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

START_TEST(s21_inverse_matrix_07) {
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

  true_matrix_result.matrix[0][0] = 0.810855408;
  true_matrix_result.matrix[0][1] = -0.000008109;
  true_matrix_result.matrix[1][0] = -0.008108554;
  true_matrix_result.matrix[1][1] = 0.000081086;

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
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

START_TEST(s21_inverse_matrix_08) {
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

  true_matrix_result.matrix[0][0] = 0.001925057;
  true_matrix_result.matrix[0][1] = 0.001015512;
  true_matrix_result.matrix[1][0] = 0.029052466;
  true_matrix_result.matrix[1][1] = 0.000035322;

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
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

START_TEST(s21_inverse_matrix_09) {
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

  true_matrix_result.matrix[0][0] = -0.000254155;
  true_matrix_result.matrix[0][1] = 0.001247347;
  true_matrix_result.matrix[0][2] = -0.00016197;
  true_matrix_result.matrix[1][0] = -0.000360127;
  true_matrix_result.matrix[1][1] = -0.000360127;
  true_matrix_result.matrix[1][2] = 0.000323939;
  true_matrix_result.matrix[2][0] = 0.001515182;
  true_matrix_result.matrix[2][1] = 0.000013681;
  true_matrix_result.matrix[2][2] = -0.00016197;

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
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

START_TEST(s21_inverse_matrix_10) {
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

  true_matrix_result.matrix[0][0] = 0.087826744;
  true_matrix_result.matrix[0][1] = -0.260613484;
  true_matrix_result.matrix[0][2] = 0.008079018;
  true_matrix_result.matrix[1][0] = 0.267128821;
  true_matrix_result.matrix[1][1] = 0.208816554;
  true_matrix_result.matrix[1][2] = 0.006026687;
  true_matrix_result.matrix[2][0] = 0.001693988;
  true_matrix_result.matrix[2][1] = 0.013519324;
  true_matrix_result.matrix[2][2] = 0.018330901;

  ck_assert_int_eq(s21_inverse_matrix(&test_matrix_1, &test_matrix_result),
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

Suite *s21_inverse_matrix_suite() {
  TCase *tcase = tcase_create("s21_inverse_matrix_tcase");
  Suite *suite = suite_create("s21_inverse_matrix");

  tcase_add_test(tcase, s21_inverse_matrix_00);
  tcase_add_test(tcase, s21_inverse_matrix_01);
  tcase_add_test(tcase, s21_inverse_matrix_02);
  tcase_add_test(tcase, s21_inverse_matrix_03);
  tcase_add_test(tcase, s21_inverse_matrix_04);
  tcase_add_test(tcase, s21_inverse_matrix_05);
  tcase_add_test(tcase, s21_inverse_matrix_06);
  tcase_add_test(tcase, s21_inverse_matrix_07);
  tcase_add_test(tcase, s21_inverse_matrix_08);
  tcase_add_test(tcase, s21_inverse_matrix_09);
  tcase_add_test(tcase, s21_inverse_matrix_10);

  suite_add_tcase(suite, tcase);
  return suite;
}
