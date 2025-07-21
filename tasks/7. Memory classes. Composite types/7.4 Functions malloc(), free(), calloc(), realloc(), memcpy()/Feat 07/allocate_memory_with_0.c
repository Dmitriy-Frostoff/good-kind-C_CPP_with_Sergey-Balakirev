#include "./utils.h"

/**
 *  @brief Allocate clear memory area of @link{ELEMS_COUNT} with
 *  @link{ONE_ELEM_SIZE} and return pointer to that memory area
 *
 *  @note ! Don't forget to free the memory area after all
 *  via assigned pointer !
 *
 *  @param {const size_t} ELEMS_COUNT - quantity of nums to nest to the memory
 *    area
 *  @param {const size_t} ONE_ELEM_SIZE - size of one nums (bytes, e.g.
 *    sizeof(int))
 *
 *  @return {void *} - address to the allocated memory area
 *  @note ! Don't forget to allign to the proper data size !
 *
 *  @example
 *    int *ptr_d = NULL;
 *    ptr_d = (int *)allocate_memory_with_0(5, sizeof(int));
 *    ptr_d{0, 0, 0, 0, 0}
 *
 *    free(ptr_d);
 *
 */
void *allocate_clear_memory(const size_t ELEMS_COUNT,
                            const size_t ONE_ELEM_SIZE) {
  int *ptr = (int *)calloc(ELEMS_COUNT, ONE_ELEM_SIZE);

  if (ptr == NULL) {
    return NULL;
  }

  return ptr;
}
