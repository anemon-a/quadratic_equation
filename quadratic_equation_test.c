#include "quadratic_equation.h"

#include <check.h>

START_TEST(discriminant_positive1) {
  Roots origin = {1.0, -3.0};
  Roots check = solve_equation(1, 2, -3);
  ck_assert_double_eq(check.x1, origin.x1);
  ck_assert_double_eq(check.x2, origin.x2);
}
END_TEST

START_TEST(discriminant_positive2) {
  Roots origin = {3.0, 2.0};
  Roots check = solve_equation(1, -5, 6);
  ck_assert_double_eq(check.x1, origin.x1);
  ck_assert_double_eq(check.x2, origin.x2);
}
END_TEST

START_TEST(discriminant_positive3) {
  Roots origin = {-0.12917130661302934, -3.8708286933869704};
  Roots check = solve_equation(2, 8, 1);
  ck_assert_double_eq(check.x1, origin.x1);
  ck_assert_double_eq(check.x2, origin.x2);
}
END_TEST

START_TEST(discriminant_positive4) {
  Roots origin = {0.5, -3};
  Roots check = solve_equation(2, 5, -3);
  ck_assert_double_eq(check.x1, origin.x1);
  ck_assert_double_eq(check.x2, origin.x2);
}
END_TEST

START_TEST(discriminant_zero) {
  Roots origin = {2, 2};
  Roots check = solve_equation(1, -4, 4);
  ck_assert_double_eq(check.x1, origin.x1);
  ck_assert_double_eq(check.x2, origin.x2);
}
END_TEST

START_TEST(discriminant_zero1) {
  Roots origin = {3, 3};
  Roots check = solve_equation(1, -6, 9);
  ck_assert_double_eq(check.x1, origin.x1);
  ck_assert_double_eq(check.x2, origin.x2);
}
END_TEST

START_TEST(discriminant_negative) {
  Roots check = solve_equation(5, -2, 3);
  ck_assert_double_nan(check.x1);
  ck_assert_double_nan(check.x2);
}
END_TEST
START_TEST(discriminant_negative1) {
  Roots check = solve_equation(3, -4, 2);
  ck_assert_double_nan(check.x1);
  ck_assert_double_nan(check.x2);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, discriminant_positive1);
  tcase_add_test(tc1_1, discriminant_positive2);
  tcase_add_test(tc1_1, discriminant_positive3);
  tcase_add_test(tc1_1, discriminant_positive4);
  tcase_add_test(tc1_1, discriminant_zero);
  tcase_add_test(tc1_1, discriminant_zero1);
  tcase_add_test(tc1_1, discriminant_negative);
  tcase_add_test(tc1_1, discriminant_negative1);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
