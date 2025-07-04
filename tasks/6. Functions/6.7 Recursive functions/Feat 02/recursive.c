#include "./utils.h"

/**
 *  @brief Print (space separated) to the terminal recursively backwards nums
 *  from MAX_RECURSION to 1 [MAX_RECURSION; 1]
 *
 *  @note !Impure function! Depends on globals macros MAX_RECURSION !
 *
 *  @param {int} num - start num
 *
 *  @return {void} - nothing
 *
 *  @example
 *    recursive(1) => void
 *    OUTPUT:
 *    4 3 2 1
 */
void recursive(int num) {
  if (num < MAX_RECURSION) {
    recursive(num + 1);
  }

  // remove trailing space
  if (num == 1) {
    printf("%d", num);
    return;
  }

  printf("%d ", num);
}
