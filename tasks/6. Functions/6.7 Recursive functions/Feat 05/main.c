/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191308/step/7?unit=1204296}
 *
 */

#include <stddef.h>
#include <stdio.h>

#define MAX_LENGTH 20

size_t to_flat(short *v, size_t MAX_LEN_V, short *table[], size_t len,
               size_t count_v, size_t indx_t, size_t indx);

void print_array_values(const short arr[], size_t ARR_SIZE,
                        size_t qunatity_to_print);

int main(void) {
  short ar_1[] = {-4, 2, 3, 7, 0};
  short ar_2[] = {11, 6, 10, 8, 13, 98, -5, 0};
  short ar_3[] = {-47, 0};
  short ar_4[] = {8, 11, 56, -3, -2, 0};

  short *table[] = {ar_1, ar_4, ar_3, ar_2};
  size_t table_row_length = sizeof(table) / sizeof(*table);

  short flat[MAX_LENGTH] = {0};
  size_t flat_length = sizeof(flat) / sizeof(*flat);

  size_t cnt = to_flat(flat, MAX_LENGTH, table, table_row_length, 0, 0, 0);

  // print the nums of @link{flat} array
  print_array_values(flat, flat_length, cnt);

  return 0;
}

/**
 *  @brief Flatten (recursively) the @link{table} array of pointers (pointers to
 *  another arrays of numbers with last 0 (number)) into @link{v} array. The
 *  last 0 (number) will not be copied (it's just for current iteration
 *  termination).
 *
 *  @note !Impure funtion! It mutates the given @link{v} array!
 *
 *  @param {short[]} v - array for adding values
 *  @param {const size_t} MAX_LEN_V - max length of @link{v}
 *  @param {short (*)[]} table - source array of arrays to read values
 *  @param {size_t} len - @link{table} arr first dimension (rows)
 *  @param {size_t} count_v - quantity of written values to the @link{v} array
 *    (base value is 0)
 *  @param {size_t} indx_t - index for pointers switching (to array rows of
 *    @link{table}, i.e. it's a first dimension of @link{table})
 *    (base value is 0)
 *  @param {size_t} indx - index for array elems switching (i.e. second
 *    dimension => columns of @link{table}), that
 *    the @link{table}[ @link{indx_t} ] pointer is pointing to
 *    (base value is 0).
 *    i.e. it's a current number in the current row of @link{table}
 *
 *  @return {size_t} - value of @link{count_v}
 *
 *  @example
 *    short ar_1[] = {1, 2, 3, 0};
 *    short ar_2[] = {4, 5, 6, 7, 8, 0};
 *    short ar_3[] = {-1, -2, 0};
 *    short ar_4[] = {-3, -4, -5, 0};
 *    short *table[] = {ar_1, ar_4, ar_3, ar_2};
 *    short flat[20] = {0};
 *    to_flat(flat, 20, table, sizeof(table) / sizeof(*table), 0, 0, 0) => 13;
 *      flat{1, 2, 3, -3, -4, -5, -1, -2, 4, 5, 6, 7, 8}
 */
size_t to_flat(short *v, const size_t MAX_LEN_V, short *table[], size_t len,
               size_t count_v, size_t indx_t, size_t indx) {
  // case for recursion termination: @link{v} array is full
  if (count_v > MAX_LEN_V) {
    return MAX_LEN_V;
  }

  // case for recursion termination: no more values to process
  if ((table[indx_t][indx] == 0) && (indx_t == len - 1)) {
    return count_v;
  }

  // current num is the last one (i.e. == 0) ? =>
  if (table[indx_t][indx] == 0) {
    // step to the next row ' s first elem of @link{table}
    return to_flat(v, MAX_LEN_V, table, len, count_v, indx_t + 1, 0);
  }

  // add current num to the @link{v} array
  v[count_v] = table[indx_t][indx];

  // increase @link{count_v} and go to the next elem in the row
  return to_flat(v, MAX_LEN_V, table, len, count_v + 1, indx_t, indx + 1);
}

/**
 *  @brief Print to the console (space separated) the @link{qunatity_to_print}
 *    of numbers of the @link{arr}
 *
 *  @param {const short[]} arr - array of numbers
 *  @param {size_t} arr_size - @link{arr} size
 *  @param {size_t} qunatity_to_print - quantity of numbers to print
 *    ( @link{qunatity_to_print} <= @link{arr_size})
 *
 *  @example
 *    short arr[10] = {-1, 0, 1, 2, 3};
 *    print_array_values(arr, 10, 5) =>
 *    OUTPUT:
 *    -1 0 1 2 3 => void
 *
 *    short arr[5] = {-1, 0, 1, 2, 3};
 *    print_array_values(arr, 5, 7) =>
 *    OUTPUT:
 *    -1 0 1 2 3 => void
 */
void print_array_values(const short arr[], const size_t ARR_SIZE,
                        size_t qunatity_to_print) {
  // if were produced incorrect @link{qunatity_to_print} value
  if (qunatity_to_print > ARR_SIZE) {
    qunatity_to_print = ARR_SIZE;
  }

  // print values
  for (int i = 0; i < qunatity_to_print; i += 1) {
    if (i == qunatity_to_print - 1) {
      printf("%d", arr[i]);
      break;
    }
    printf("%d ", arr[i]);
  }
}
