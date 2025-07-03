/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191295/step/6?unit=1204283}
 *
 */

#include <stdio.h>

#define TOTAL 10

int main(void) {
  int digs[TOTAL] = {0};
  int count = 0;
  int insert_num = -1;
  int digs_length = sizeof(digs) / sizeof(*digs);

  while (count < digs_length && scanf("%d", &digs[count]) == 1) {
    /**
     *  @example
     *    1 2 5 3 5 4 5 6 =>
     *      1 => 2 => 5 => insert_num (=-1) => 3 =>
     *      5 => insert_num (= -1 - 1) => 4 =>
     *      5 => insert_num (= -2 - 1) => 6 =>
     *      {1, 2, 5, -1, 3, 5, -2, 4, 5, -3}
     */

    // e.g. digs[count] = digs[0]
    count += 1;
    // e.g. digs[count] = digs[1]

    // digs[count - 1] because of count + 1 above
    // e.g. digs[count - 1] = digs[0]
    if (digs[count - 1] == 5) {
      if (digs[count] < digs_length) {
        digs[count] = insert_num;
        insert_num -= 1;
        // nested one insert_num => count += 1
        count += 1;
      } else {
        // last index of digs arr ? break
        break;
      }
    }
  }

  for (int i = 0; i < count; i += 1) {
    printf("%d ", digs[i]);
  }

  return 0;
}
