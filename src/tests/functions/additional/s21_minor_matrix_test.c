#include "../../s21_tests_runner.h"

START_TEST(s21_minor_matrix_00) {
  matrix_t test_matrix_1 = {};
  matrix_t test_matrix_2 = {};

  ck_assert_int_eq(s21_minor_matrix(&test_matrix_1, 0, 0, &test_matrix_2),
                   MR_INCORRECT_MATRIX);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_minor_matrix_01) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 1;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_minor_matrix(&test_matrix_1, rows / 2, columns / 2, &test_matrix_2),
      MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_minor_matrix_02) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 10;
  int columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_minor_matrix(&test_matrix_1, rows / 2, columns / 2, &test_matrix_2),
      MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_minor_matrix_03) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 1;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_minor_matrix(&test_matrix_1, rows / 2, columns / 2, &test_matrix_2),
      MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_minor_matrix_04) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_minor_matrix(&test_matrix_1, -1, columns / 2, &test_matrix_2),
      MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_minor_matrix_05) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_minor_matrix(&test_matrix_1, rows / 2, -1, &test_matrix_2),
      MR_CALC_ERROR);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_minor_matrix_06) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  ck_assert_int_eq(
      s21_minor_matrix(&test_matrix_1, rows / 2, columns / 2, &test_matrix_2),
      MR_OK);

  for (int i = 0; i < test_matrix_2.rows - 1; i++) {
    for (int j = 0; j < test_matrix_2.columns - 1; j++) {
      ck_assert_double_eq(test_matrix_2.matrix[i][j], 0);
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_minor_matrix_07) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  size_t number = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix_1.matrix[i][j] = ++number;
    }
  }

  ck_assert_int_eq(s21_minor_matrix(&test_matrix_1, _i, 0, &test_matrix_2),
                   MR_OK);

  for (int i = 0, add_i = 0; i < test_matrix_1.rows; i++) {
    if (i != _i) {
      for (int j = 0, add_j = 0; j < test_matrix_1.columns; j++) {
        if (j != _i) {
          ck_assert_double_eq_tol(test_matrix_2.matrix[i - add_i][j - add_j],
                                  test_matrix_1.matrix[i][j], MTRX_EPSILON);
        } else {
          add_j = 1;
        }
      }

    } else {
      add_i = 1;
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_minor_matrix_08) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 10;
  int columns = 10;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  size_t number = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      test_matrix_1.matrix[i][j] = ++number;
    }
  }

  ck_assert_int_eq(s21_minor_matrix(&test_matrix_1, 0, _i, &test_matrix_2),
                   MR_OK);

  for (int i = 0, add_i = 0; i < test_matrix_1.rows; i++) {
    if (i != _i) {
      for (int j = 0, add_j = 0; j < test_matrix_1.columns; j++) {
        if (j != _i) {
          ck_assert_double_eq_tol(test_matrix_2.matrix[i - add_i][j - add_j],
                                  test_matrix_1.matrix[i][j], MTRX_EPSILON);
        } else {
          add_j = 1;
        }
      }

    } else {
      add_i = 1;
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_minor_matrix_09) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  test_matrix_1.matrix[0][0] = 1;
  test_matrix_1.matrix[0][1] = 2;
  test_matrix_1.matrix[1][0] = 3;
  test_matrix_1.matrix[1][1] = 4;

  ck_assert_int_eq(s21_minor_matrix(&test_matrix_1, 0, 0, &test_matrix_2),
                   MR_OK);

  ck_assert_double_eq(test_matrix_2.matrix[0][0], 4);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_minor_matrix_10) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  test_matrix_1.matrix[0][0] = 1;
  test_matrix_1.matrix[0][1] = 2;
  test_matrix_1.matrix[1][0] = 3;
  test_matrix_1.matrix[1][1] = 4;

  ck_assert_int_eq(s21_minor_matrix(&test_matrix_1, 1, 0, &test_matrix_2),
                   MR_OK);

  ck_assert_double_eq(test_matrix_2.matrix[0][0], 2);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_minor_matrix_11) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  test_matrix_1.matrix[0][0] = 1;
  test_matrix_1.matrix[0][1] = 2;
  test_matrix_1.matrix[1][0] = 3;
  test_matrix_1.matrix[1][1] = 4;

  ck_assert_int_eq(s21_minor_matrix(&test_matrix_1, 0, 1, &test_matrix_2),
                   MR_OK);

  ck_assert_double_eq(test_matrix_2.matrix[0][0], 3);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_minor_matrix_12) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  int rows = 2;
  int columns = 2;

  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_1), MR_OK);
  ck_assert_int_eq(s21_create_matrix(rows, columns, &test_matrix_2), MR_OK);

  test_matrix_1.matrix[0][0] = 1;
  test_matrix_1.matrix[0][1] = 2;
  test_matrix_1.matrix[1][0] = 3;
  test_matrix_1.matrix[1][1] = 4;

  ck_assert_int_eq(s21_minor_matrix(&test_matrix_1, 1, 1, &test_matrix_2),
                   MR_OK);

  ck_assert_double_eq(test_matrix_2.matrix[0][0], 1);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

Suite *s21_minor_matrix_suite() {
  TCase *tcase = tcase_create("s21_minor_matrix_tcase");
  Suite *suite = suite_create("s21_minor_matrix");

  tcase_add_test(tcase, s21_minor_matrix_00);
  tcase_add_test(tcase, s21_minor_matrix_01);
  tcase_add_test(tcase, s21_minor_matrix_02);
  tcase_add_test(tcase, s21_minor_matrix_03);
  tcase_add_test(tcase, s21_minor_matrix_04);
  tcase_add_test(tcase, s21_minor_matrix_05);
  tcase_add_test(tcase, s21_minor_matrix_06);
  tcase_add_test(tcase, s21_minor_matrix_07);
  tcase_add_test(tcase, s21_minor_matrix_08);
  tcase_add_test(tcase, s21_minor_matrix_09);
  tcase_add_test(tcase, s21_minor_matrix_10);
  tcase_add_test(tcase, s21_minor_matrix_11);
  tcase_add_test(tcase, s21_minor_matrix_12);

  suite_add_tcase(suite, tcase);
  return suite;
}
