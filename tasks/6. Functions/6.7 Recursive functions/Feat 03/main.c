/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191308/step/5?unit=1204296}
 *
 */

#include <stddef.h>
#include <stdio.h>

#define MAX_LENGTH 20

size_t range_to_ar(int *ptr_a, size_t MAX_LEN, int from, int TO, size_t count);

int get_max_range_value();
void print_arr_nums(const int arr[], size_t SIZEOF_ARR,
                    size_t quantity_to_print);

int main(void) {
  int max_rec;
  int arr[MAX_LENGTH];
  size_t arr_size = sizeof(arr) / sizeof(*arr);

  // get from the input max range value
  max_rec = get_max_range_value();

  // fill the @link{arr} with integers [ 1 : @link{max_rec} ]
  size_t cnt = range_to_ar(arr, MAX_LENGTH, 1, max_rec, 0);

  // print to the terminal first @link{cnt} nums
  print_arr_nums(arr, arr_size, cnt);

  return 0;
}

/**
 *  @brief Get the max range value from the input
 *
 *  @return {int} - max range value
 *  @throw if input is empty
 *
 *  @example
 *    get_max_range_value() =>
 *    INPUT:
 *    8 => 8
 */
int get_max_range_value() {
  int max_range_value;

  if (scanf("%d", &max_range_value) != 1) {
    puts("Error: empty input data");
    return -1;
  }

  return max_range_value;
}

/**
 *  @brief Fill (recursively) @link{ptr_a} with integers [ @link{from} :
 *    @link{TO} ]
 *
 *  @note !Impure function! Mutates the @link{ptr_a} array
 *
 *  @param {int (*)[]} ptr_a - pointer to the array
 *  @param {const size_t} MAX_LEN - @link{ptr_a} arr size
 *  @param {int} from - start integer of range to fill @link{ptr_a} with
 *  @param {const int} TO - last integer
 *  @param {size_t} count - quantity of added integers to the @link{ptr_a}
 *
 *  @return {size_t} - @link{count} value
 *
 *  @example
 *    int arr[20] = {0};
 *    range_to_ar(arr, 20, 1, 8, 0) => 8
 *      arr{1, 2, 3, 4, 5, 6, 7, 8, {0 x 12}}
 *    range_to_ar(arr, 10, 1, 12, 0) => 10
 *      arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, {0 x 10}}
 */
size_t range_to_ar(int *ptr_a, const size_t MAX_LEN, int from, const int TO,
                   size_t count) {
  ptr_a[count] = from;
  count += 1;

  if (from == TO || count == MAX_LEN) {
    return count;
  }

  // increase values
  from += 1;

  return range_to_ar(ptr_a, MAX_LEN, from, TO, count);
}

/**
 *  @brief Print to the termnal first @link{quantity_to_print} nums
 *  (space separated)
 *
 *  @note if @link{quantity_to_print} is greater than @link{sizeof_arr} will be
 *  printed only @link{sizeof_arr} nums
 *
 *  @param {const int (*)[]} arr - pointer to the array of integers
 *  @param {size_t} sizeof_arr - size of @link{arr}
 *  @param {size_t} quantity_to_print - quantity of nums to print
 *
 *  @throw if @link{sizeof_arr} or @link{quantity_to_print} are == 0
 *
 *  @example
 *    int arr[10] = {-1, 0, 1, 2, 3};
 *    size_t quantity_to_print = 4
 *    print_arr_nums(arr, 10, quantity_to_print) => void
 *    OUTPUT:
 *    -1 0 1 2
 */
void print_arr_nums(const int arr[], const size_t SIZEOF_ARR,
                    size_t quantity_to_print) {
  if (SIZEOF_ARR == 0) {
    puts("Error: array size is 0");
    return;
  }

  if (quantity_to_print == 0) {
    puts("Error: nums quantity for printing is 0");
    return;
  }

  // protection from step over the @link{arr}
  if (quantity_to_print > SIZEOF_ARR) {
    quantity_to_print = SIZEOF_ARR;
  }

  for (size_t i = 0; i < quantity_to_print; i += 1) {
    if (i == quantity_to_print - 1) {
      printf("%d", arr[i]);
      break;
    }
    printf("%d ", arr[i]);
  }
}
