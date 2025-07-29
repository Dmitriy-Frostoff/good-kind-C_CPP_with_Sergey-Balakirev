#include "./utils.h"

/**
 *  @brief Remove current instance of @link{obj} from the stack's top
 *
 *  @note ! Impure function !
 *  - free's allocated memory (wipe instance) of the outer @link{top}
 *  - implicit dependency on @link{OBJ} type
 *
 *  @param {OBJ *} top - pointer to the current @link{OBJ} instance on the
 *  stack's top
 *
 *  @return {OBJ*} - pointer to the next @link{top} (previous @link{OBJ}
 *  instance to the current one) or NULL
 *
 *  @example
 *    OBJ *top = {
 *      char id[ID_SIZE] = "obj_id_00000000";
 *      char url[URL_SIZE] = "https://www.google.com/";
 *      struct tag_obj *next = NULL;
 *    }
 *
 *    top = pop(top);
 *    =>
 *    top = NULL;
 *
 */
OBJ *pop(OBJ *top) {
  // check pointer
  if (top == NULL) {
    puts("pop() function: Stack is empty");
    return NULL;
  }

  // create pointer to the next instance of @link{OBJ}
  OBJ *ptr_next = top->next;

  // remove current instance of @link{OBJ}
  printf("pop() function: deleted: %s\n", top->id);
  free(top);

  // return updated top of the stack
  return ptr_next;
}
