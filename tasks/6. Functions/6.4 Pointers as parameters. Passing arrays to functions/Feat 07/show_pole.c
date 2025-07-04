#include "./utils.h"

/**
 *  @brief modify and print to the console 2d array
 *  @note !Impure function! Uses functions that are not declared as callbacks!
 *  TODO! Rewrite with callbacks usage for @link{modify_array} and
 *    @link{print_maxtrix} functions!!!
 *
 *  @param {char *} (*arr)[SIZE] - pointer to the 2d array of integers
 *   @type{char} (SIZE is from #define)
 *
 *  @return {void} - just modifies and print to the console array values
 *
 *  @example
 *    arr[3][3] = {0}
 *      show_pole(arr) => void
 *      arr{
 *        0 1 0
 *        2 0 2
 *        1 0 0
 *      } =>
 *      arr[3][3]{
 *        '#, x, #'
 *        'o, #, o'
 *        'x, #, #'
 *      }
 *      >>>
 *      # x #
 *      o # o
 *      x # #
 */
void show_pole(char (*arr)[SIZE]) {
  // modify 2d array via template: 1 => 'x', 2 => 'o', 0 => '#'
  modify_array(arr);

  // print 2d array to the console
  print_maxtrix(arr);
}
