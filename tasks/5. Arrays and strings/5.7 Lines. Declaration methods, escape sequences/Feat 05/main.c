/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191297/step/7?unit=1204285}
 *
 * Decalre array 'text' of three pointers that are initialized to the stroke
 * literals:
 * 1st pointer: "language C"
 * 2nd pointer: "language C++"
 * 3rd pointer: "language Python"
 *
 */

#include <stdio.h>

int main(void) {
  char *ptr_str1 = "language C";
  char *ptr_str2 = "language C++";
  char *ptr_str3 = "language Python";
  char *text[] = {ptr_str1, ptr_str2, ptr_str3};

  /**
   *  макроопределение для тестирования
   *  (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
