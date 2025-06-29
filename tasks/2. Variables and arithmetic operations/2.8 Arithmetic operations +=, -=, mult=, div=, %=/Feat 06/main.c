/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191255/step/8?unit=1204226}
 *
 */

#include <stdio.h>

int main(void) {
  int price;
  int discount;
  float total;

  scanf("%d %d", &price, &discount);

  total = price * (1 - discount / 100.0);
  total *= 2;

  printf("%.02f", total);

  return 0;
}
