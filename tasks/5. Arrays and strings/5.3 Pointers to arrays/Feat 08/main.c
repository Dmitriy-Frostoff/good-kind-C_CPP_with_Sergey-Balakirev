/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191293/step/10?unit=1204281}
 *
 */

#include <stdio.h>

int main(void) {
  short var_1;
  int var_2;
  long long var_3;

  unsigned char *ptr_byte_at_var_1 = &var_1;
  unsigned char *ptr_byte_at_var_2 = &var_2;
  unsigned char *ptr_byte_at_var_3 = &var_3;

  short arr_of_bytes_values[sizeof(var_1) + sizeof(var_2) + sizeof(var_3)];
  char arr_of_bytes_values_length =
      sizeof(arr_of_bytes_values) / sizeof(*arr_of_bytes_values);

  if (scanf("%hd, %d, %lld", &var_1, &var_2, &var_3) != 3) {
    printf("expected three integers");
    return 0;
  }

  /**
   * @example
   *    {} and short 7356(256based: 188 * 256 ** 0 + 28 * 256 ** 1 = 7356) =>
   *        7356(256based: 188 28) => {188, 28}
   */
  for (unsigned char i = 0; i < sizeof(var_1); i += 1) {
    arr_of_bytes_values[i] = *(ptr_byte_at_var_1 + i);
  }

  /**
   * @example
   *    {188, 28} and int 6575729(256based: 113 86 100 0) =>
   *    {188, 28, 113, 86, 100, 0}
   */
  for (unsigned char i = 0; i < sizeof(var_2); i += 1) {
    // i + sizeof(var_1) => to nest values
    // after copied one of the var_1
    arr_of_bytes_values[i + sizeof(var_1)] = *(ptr_byte_at_var_2 + i);
  }

  /**
   * @example
   *    {188, 28, 113, 86, 100, 0} and
   *        long long 100433564(256based: 156 126 252 5 0 0 0 0) =>
   *            {188, 28, 113, 86, 100, 0, 156, 126, 252, 5, 0, 0, 0, 0}
   */
  for (unsigned char i = 0; i < sizeof(var_3); i += 1) {
    // i + sizeof(var_1) + sizeof(var_2) => to nest values
    // after copied one of the var_1 and var_2
    arr_of_bytes_values[i + sizeof(var_1) + sizeof(var_2)] =
        *(ptr_byte_at_var_3 + i);
  }

  for (unsigned char i = 0; i < arr_of_bytes_values_length; i += 1) {
    printf("%u ", arr_of_bytes_values[i]);
  }

  return 0;
}
