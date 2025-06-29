/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191255/step/9?unit=1204226}
 *
 */

#include <stdio.h>

int main(void) {
  /**
   * formula is:
   * speed (km / h) = speed (m/sec) * 3600sec / 1000m
   * or speed (km / h) = speed * 3.6
   */

  int speedKmPerHour;
  double speedMPerSec;

  scanf("%d", &speedKmPerHour);

  speedMPerSec = 3.6 * speedKmPerHour;

  printf("%.1f", speedMPerSec);

  return 0;
}
