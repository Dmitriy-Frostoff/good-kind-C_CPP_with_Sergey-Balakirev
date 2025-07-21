#include "./utils.h"
#include "config.h"

/**
 *  @brief Double the array size and fill the added amount with @link{fill}
 *    values
 *
 *  @note ! Impure function! Mutates the outer @link{len} value !
 *
 *  @param {short *} ptr - pointer to the allocated memory area
 *  @param {size_t *} len - pointer to length of the allocated memory area
 *  @param {short} fill - element to fill the rest of the doubled memory area
 *
 *  @return {void*} - address of the doubled allocated memory area
 *    @note ! Don't forget to narrow to proper data type of the outer pointer!
 *
 *  @example
 *    @note @link{ptr_outer} is the address of the allocated memory area
 *      (via @callback(calloc) from <stdlib.h>);
 *    short *ptr_outer = {6, 3, -2, 4, 10};
 *    size_t arr_size = 5;
 *    short fill = -1;
 *
 *    ptr_outer = (short *)expand_array(ptr_outer, arr_size, fill);
 *    =>
 *    ptr_outer{6, 3, -2, 4, 10, -1, -1, -1, -1, -1}
 *    arr_size{10}
 *
 *    don't forget to clean up! =>
 *    free(ptr_outer);
 *    ptr_outer = NULL;
 *
 */
void *expand_array(short *ptr, size_t *len, short fill) {
  size_t old_len = *len;
  size_t updated_len = *len * 2;

  short *ptr_buff = (short *)realloc(ptr, *len * 2 * sizeof(short));

  if (ptr_buff == NULL) {
    return NULL;
  }

  ptr = ptr_buff;

  // fill the rest part of the updated @link{ptr} memory area with
  // @link{fill} value
  for (size_t i = old_len; i < updated_len; i += 1) {
    ptr[i] = fill;
  }

  // update @link{len} value
  *len *= 2;

  // return updated @link{ptr} to the doubled allocated memory area
  return ptr;
}
