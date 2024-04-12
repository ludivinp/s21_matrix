#include "../s21_tests_runner.h"

START_TEST(s21_eq_matrix_00) {
  matrix_t test_matrix_1 = {};
  matrix_t test_matrix_2 = {};

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_01) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_SUCCESS);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_02) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 10;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_SUCCESS);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_03) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 1;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_SUCCESS);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_04) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix_1.matrix[i][j] = test_matrix_2.matrix[i][j] = i + j;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_SUCCESS);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_05) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      for (int o = 0; o < MTRX_EPSILON_10; o++) {
        test_matrix_1.matrix[i][j] =
            test_matrix_1.matrix[i][j] / 10 + (((i + j) * o) % 10);
      }

      test_matrix_2.matrix[i][j] = test_matrix_1.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_SUCCESS);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_06) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;

  ck_assert_int_eq(s21_create_matrix(1, 2, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(2, 1, &test_matrix_2), MR_OK);

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_FAILURE);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_07) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;

  ck_assert_int_eq(s21_create_matrix(1, 1, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(1, 2, &test_matrix_2), MR_OK);

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_FAILURE);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_08) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;

  ck_assert_int_eq(s21_create_matrix(2, 1, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(1, 1, &test_matrix_2), MR_OK);

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_FAILURE);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_09) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;

  ck_assert_int_eq(s21_create_matrix(100, 100, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(100, 100, &test_matrix_2), MR_OK);

  test_matrix_1.matrix[0][0] = 1;

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_FAILURE);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_10) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;

  ck_assert_int_eq(s21_create_matrix(100, 100, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(100, 100, &test_matrix_2), MR_OK);

  test_matrix_2.matrix[0][0] = 1;

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_FAILURE);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_11) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;

  ck_assert_int_eq(s21_create_matrix(100, 100, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(100, 100, &test_matrix_2), MR_OK);

  test_matrix_1.matrix[0][0] = MTRX_EPSILON * 10;

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_FAILURE);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_12) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;

  ck_assert_int_eq(s21_create_matrix(100, 100, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(100, 100, &test_matrix_2), MR_OK);

  test_matrix_2.matrix[0][0] = MTRX_EPSILON * 10;

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_FAILURE);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_eq_matrix_13) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      for (int o = 0; o < MTRX_EPSILON_10; o++) {
        test_matrix_1.matrix[i][j] =
            test_matrix_1.matrix[i][j] / 10 + (((i + j) * o) % 10);
      }

      test_matrix_2.matrix[i][j] =
          test_matrix_1.matrix[i][j] + (MTRX_EPSILON * 10);
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&test_matrix_1, &test_matrix_2), MCR_FAILURE);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

Suite *s21_eq_matrix_suite() {
  TCase *tcase = tcase_create("s21_eq_matrix_tcase");
  Suite *suite = suite_create("s21_eq_matrix");

  tcase_add_test(tcase, s21_eq_matrix_00);
  tcase_add_test(tcase, s21_eq_matrix_01);
  tcase_add_test(tcase, s21_eq_matrix_02);
  tcase_add_test(tcase, s21_eq_matrix_03);
  tcase_add_test(tcase, s21_eq_matrix_04);
  tcase_add_test(tcase, s21_eq_matrix_05);
  tcase_add_test(tcase, s21_eq_matrix_06);
  tcase_add_test(tcase, s21_eq_matrix_07);
  tcase_add_test(tcase, s21_eq_matrix_08);
  tcase_add_test(tcase, s21_eq_matrix_09);
  tcase_add_test(tcase, s21_eq_matrix_10);
  tcase_add_test(tcase, s21_eq_matrix_11);
  tcase_add_test(tcase, s21_eq_matrix_12);
  tcase_add_test(tcase, s21_eq_matrix_13);

  suite_add_tcase(suite, tcase);
  return suite;
}
