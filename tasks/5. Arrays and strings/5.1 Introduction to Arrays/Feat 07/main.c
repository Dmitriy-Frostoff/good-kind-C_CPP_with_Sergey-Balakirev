/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191291/step/9?unit=1204279}
 *
 * Decalre array with name 'func' of 28 elements length of type double. Read
 * from the INPUT: real number and assign it to 'x' variable and than assign 'x'
 * value to the 'func'[6] element
 *
 */

#include <stdio.h>

int main(void) {
  double func[28];
  double x;

  if (scanf("%lf", &x) != 1) {
    printf("expected one real number");
    return 0;
  }

  func[6] = x;

  /**
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
