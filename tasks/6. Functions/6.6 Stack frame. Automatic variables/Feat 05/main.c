/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191307/step/7?unit=1204295}
 *
 */

#include <stddef.h>
#include <stdio.h>

#define MAX_SIZE 20

int fill_arr(short arr[], size_t arr_size);
void reverse(short arr[], int elems_quantity);
void print_first_N_nums(short arr[], int elems_quantity);

int main(void) {
  short digs[MAX_SIZE];
  size_t digs_length = sizeof(digs) / sizeof(*digs);
  int count = 0;

  // fill the @link{digs} from the INPUT
  count = fill_arr(digs, digs_length);

  // revert the @link{count} elems of @link{digs}
  reverse(digs, count);

  // print first @link{count} nums of @link{arr}
  print_first_N_nums(digs, count);

  return 0;
}

/**
 *  @brief Fill the @link{arr} from the INPUT:
 *
 *  @param {short (*)[]} arr - array to fill
 *  @param {size_t} arr_size - size of @link{arr}
 *
 *  @return {int} - quantity of added to the link{arr} nums
 *
 *  @example
 *    short arr[5] = {0};
 *    size_t arr_size = 5;
 *      fill_arr(arr, arr_size) =>
 *      INPUT:
 *      -1 0 1 2 3 => 5
 *      arr{-1, 0, 1, 2, 3}
 */
int fill_arr(short arr[], size_t arr_size) {
  int count = 0;
  while (count < arr_size && scanf("%hd", &arr[count]) == 1) {
    count += 1;
  }

  return count;
}

/**
 *  @brief Revert the @link{elems_quantity} of the @link{arr}
 *
 *  @note !Impure function! Mutates the original @link{arr} !
 *
 *  @param {short (*)[]} arr - array of numbers to be reverted
 *  @param {int} elems_quantity - qunatity of @link{arr} nums to revert
 *
 *  @return {void} - nothing
 *  @throw - if elems_quantity <= 0
 *
 *  @example
 *    short arr[10] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
 *      reverse(arr, 3) => void
 *      arr{8, 7, 6, -1, 0, 1, 2, 3, 4, 5}
 */
void reverse(short arr[], int elems_quantity) {
  if (elems_quantity <= 0) {
    puts("Error: elems_quantity must be > 0");
    return;
  }

  // elems_quantity - 1 ?? => e.g. arr[6] => last num is at arr[6 - 1]
  // @note elems_quantity even or odd ?
  // e.g. arr[6] => middle num is at arr[2] (len / 2),
  //  arr[7] => middle num is at arr[3] ((len - 1) / 2)
  // @note but in C division is always integer division...)
  //  => 7 / 2 = 3 and 6 / 2 = 3
  for (int i = elems_quantity - 1, j = 0; j < elems_quantity / 2;
       i -= 1, j += 1) {
    short temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
  }
}

/**
 *  @brief Print to the terminal space separated @link{elems_quantity} of
 *    @link{arr}
 *
 *  @param {short (*)[]} arr - array of numbers to be printed
 *  @param {type} elems_quantity - qunatity of @link{arr} nums to be printed
 *
 *  @return {void} - nothing
 *  @throw - if elems_quantity <= 0
 *
 *  @example
 *     short arr[10] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
 *      print_first_N_nums(arr, 3) => void
 *      OUTPUT:
 *      8 7 6
 */
void print_first_N_nums(short arr[], int elems_quantity) {
  if (elems_quantity <= 0) {
    puts("Error: elems_quantity must be > 0");
    return;
  }

  for (int i = 0; i < elems_quantity; i += 1) {
    if (i == elems_quantity - 1) {
      printf("%d", arr[i]);
      break;
    }
    printf("%d ", arr[i]);
  }
}
