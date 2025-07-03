/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191293/step/8?unit=1204281}
 *
 */

#include <stdio.h>

int main(void) {
  // arr_of_nums[10] => {NULL x 10} as array of empty values
  short arr_of_nums[10] = {NULL};
  short *ptr_arr_of_nums = &*arr_of_nums;
  unsigned char arr_of_nums_length = sizeof(arr_of_nums) / sizeof(*arr_of_nums);

  // ptr_arr_of_nums < &*arr_of_nums + 10 i.e. =>
  // current pointer address less then arr pointer address + 10 elements
  /**
   * @example
   *    3 5 7 11 13 15 17 19 23 25 43 36 and arr_of_nums{NULL x 10} =>
   *        arr_of_nums{3, 5, 7, 11, 13, 15, 17, 19, 23, 25}
   */

  while (scanf("%hd ", ptr_arr_of_nums) != EOF &&
         ptr_arr_of_nums < &*arr_of_nums + 10) {
    ptr_arr_of_nums += 1;
  }

  // reset pointer
  ptr_arr_of_nums = &*arr_of_nums;

  for (unsigned char i = 0; i < arr_of_nums_length; i += 1) {
    /**
     * @example
     *    arr{3, 5, 7, NULL x 7, 9}
     *        => contine till the end of NULL values
     */
    if (*ptr_arr_of_nums == NULL) {
      continue;
    }

    if (*ptr_arr_of_nums < 0 || *ptr_arr_of_nums % 2 != 1) {
      printf("0");
      return 0;
    }

    ptr_arr_of_nums += 1;
  }

  // reset pointer
  ptr_arr_of_nums = &*arr_of_nums;

  printf("1");

  return 0;
}
