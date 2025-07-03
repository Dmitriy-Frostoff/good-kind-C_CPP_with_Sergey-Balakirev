/**
 * The task description is at
 * @link{}
 *
 * @note RU
 * Скорее всего, ожидался другой алгоритм)) Но так получилось короче и меньше
 * заморочек)
 * По хорошему, если бы предоставлялся уже готовый массив для преобразования,
 * сделал бы так:
 *  - создал массив индексов совпадений search_num_indexes[TOTAL] = {-1} размера
 * TOTAL на случай, если весь массив состоит из 5... {5 x TOTAL}
 * инициализированный -1 (-1 == нет совпадений)
 * - через цикл (а лучше создать для этого отдельную функцию) прогнал бы все
 * элементы digs и занёс бы индексы совпадений
 * - через цикл проверить массив совпадений, что есть значения != -1, иначе
 * => вывести все элементы массива digs
 * - через цикл (начиная с первого индекса совпадения) сдвигал бы содержимое
 * массива digs на 1 и вставлял на совпадение insert_num (в последствии делая
 * insert_num -= 1) и проверяя условие, что не вышел за длину массива digs
 * - вывести все обновлённые элементы массива digs
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
