#include "./utils.h"

/**
 *  @brief Empty the stack via @link{callback} usage
 *
 *  @note ! Impure function !
 *  - free's allocated memory (wipes) of the outer @link{top}
 *  - implicit dependency on @link{OBJ} type
 *  - implicit dependency on @link{empty_stack_callback} callback type
 *    defenition
 *
 *  @param {OBJ *} top - pointer to the current stack's top
 *  @param {empty_stack_callback} callback - @see{pop}
 *
 *  @return {OBJ*} - NULL as pointer (happy path) or some address (negative
 *  path)
 *
 *  @example
 *    OBJ *top = {
 *      char id[ID_SIZE] = "obj_id_00000001";
 *      char url[URL_SIZE] = "https://www.youtube.com/";
 *      struct tag_obj *next = {
 *        char id[ID_SIZE] = "obj_id_00000000";
 *        char url[URL_SIZE] = "https://www.google.com/";
 *        struct tag_obj *next = NULL;
 *      }
 *    }
 *
 *    empty_stack(top, pop);
 *    =>
 *    top = NULL;
 *
 */
OBJ *empty_stack(OBJ *top, empty_stack_callback callback) {
  OBJ *ptr_current = top;

  // check @link{top}
  if (top == NULL) {
    puts("empty_stack() function: Stack is empty");
    return NULL;
  }

  // empty stack
  while (ptr_current != NULL) {
    // wipe current @link{OBJ} instance and update stack's top
    ptr_current = callback(ptr_current);
  }

  return ptr_current;
}
