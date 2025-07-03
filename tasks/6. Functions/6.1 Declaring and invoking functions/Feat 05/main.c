/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191302/step/7?unit=1204290}
 *
 */

#include <stdio.h>

#define MAX_SAFE_INTEGER 2147483647

/**
 *  @brief Get the volume of figure
 *
 *  @param {int} h - figure's height, integer in range (0; 2 147 483 647)
 *  @param {int} w - figure's width, integer in range (0; 2 147 483 647)
 *  @param {int} d - figure's depth, integer in range (0; 2 147 483 647)
 *
 *  @return {int} - figure's volume
 *  @throw "all of 'h', 'w' and 'd' must be integers \
 *    in range (0; 2 147 483 647)"
 *
 *  @example
 *    get_volume(2, 3, 4) => 24
 *    get_volume(-2, 4, 6) => "all of 'h', 'w' and 'd' must be integers in range
 *     (0; 2 147 483 647)"
 */
int get_volume(int h, int w, int d) {
  if ((h <= 0 || h > MAX_SAFE_INTEGER) || (w <= 0 || w > MAX_SAFE_INTEGER) ||
      (d <= 0 || d > MAX_SAFE_INTEGER)) {
    puts(
        "all of 'h', 'w' and 'd' must be integers in range (0; 2 147 483 647)");
    return 0;
  }

  return h * w * d;
}

int main(void) {
  int h = 0;
  int w = 0;
  int d = 0;

  if (scanf("%d %d %d", &h, &w, &d) != 3) {
    puts("expected three integers in range (0; 2 147 483 647)");
    return 0;
  }

  printf("%d\n", get_volume(h, w, d));
  return 0;
}
