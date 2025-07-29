#include "./utils.h"

/**
 *  @brief Initialize instance of {OBJ} type and return pointer to it
 *
 *  @note ! Impure function !
 *  - implicit dependency on @link{OBJ} type
 *  - implicit dependency on @link{URL_SIZE} of @link{global_variables}
 *
 *  @note Under the hood it uses calloc() function for memory area allocation,
 *  so don 't forget to free() the pointer to the instance
 *
 *  @param {OBJ *top} top - current top of the stack
 *  @param {const char *} url - string representation of url (not greater than
 *  1024 chars!)
 *
 *  @return {OBJ*} - pointer to the created instance of {OBJ} (i.e. new top
 *  pointer)
 *  @throw if @link{url} length is greater than link{OBJ->url} size
 *  @throw if some problems occured at the memory allocation process
 *
 *  @example
 *    **stack is empty**
 *    OBJ *top = NULL;
 *
 *    top = push(top, "https://www.google.com/");
 *    =>
 *    top = address of the new created instance of @link{OBJ}
 *    *top = {
 *      char id[ID_SIZE] = "obj_id_00000000";
 *      char url[URL_SIZE] = "https://www.google.com/";
 *      struct tag_obj *next = NULL;
 *    }
 *
 *    **clean up** e.g.
 *    free(top);
 *    top = NULL;
 *
 *    but better via created function like @link{pop}
 *
 */
OBJ *push(OBJ *top, const char *url) {
  static const char ID_LITERAL_PART[] = "obj_id";
  static int id_num_part = 0;

  // check the @link{url} length
  size_t url_length = strlen(url);
  if (url_length > URL_SIZE - 1) {
    puts("Error(push() function): the url length is greater than 1024 "
         "URL_SIZE(1024 chars)");
    return NULL;
  }

  // allocate memory for the new @link{OBJ} instance
  OBJ *ptr = (OBJ *)calloc(1, sizeof(OBJ));

  if (ptr == NULL) {
    puts("Error(push() function): couldn't allocate memory area");
    return NULL;
  }

  // initialize @link{OBJ} instance fields
  // @link{OBJ->url}
  strcpy(ptr->url, url);
  ptr->url[url_length] = '\0';

  // @link{OBJ->id}
  // %08d ? => ID_SIZE(=16) - "obj_id_"(=7) - '\0'(=1)
  sprintf(ptr->id, "%s_%08d", ID_LITERAL_PART, id_num_part);
  id_num_part += 1;

  // @link{OBJ->next}
  ptr->next = top;

  // return pointer to the created @link{OBJ} instance
  return ptr;
}
