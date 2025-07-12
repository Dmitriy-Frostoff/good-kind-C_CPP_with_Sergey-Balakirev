/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191309/step/5?unit=1204297}
 *
 *  Write function @callback{mean} that count mean of the arbitary got integers
 *  and where first param is the quantity of integers to count.
 *  Print the counted value to the console with precision to hundredths.
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  double res = 0;

  // count mean of the integers
  res = mean(7, 5, -10, 11, 0, 12, 4, 2);

  printf("%.2f\n", res);

  return 0;
}
