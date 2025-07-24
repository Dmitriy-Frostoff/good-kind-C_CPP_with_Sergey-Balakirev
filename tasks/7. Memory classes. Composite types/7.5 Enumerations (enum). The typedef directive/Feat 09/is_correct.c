#include "./utils.h"

/**
 *  @brief Clean up pointer to the allocated memory area
 *
 *  @note ! Impure function! Modifies outer @link{ptr} !
 *  @note ! Only for allocated memory area pointers !
 *  @note ! free() and makes NULL outer @link{ptr} !
 *  @note free() deals with @type{void *}
 *
 *  @param {void **} ptr - pointer to the allocated memory area
 *    @note !!!under the hood pointer to the pointer is used!!! No other way!
 *      if to set pointer like @type{void *} (i.e. clean_up(pointer))
 *      @link{clean_up} function will modify only local copy of @link{ptr}
 *
 *  @example
 *    char *ptr = (char *)calloc(10, sizeof(char));
 *
 *    ** (void **) ? => narrowing any pointer type to @type{void **}
 *    clean_up((void **)&ptr) => void
 *    ptr{NULL}
 *
 */
static void clean_up(void **ptr) {
  // clean up
  // @note free() deals with void* so (char *) before @link{ptr} is useless
  // e.g. free((char *)ptr) is useless
  if (*ptr != NULL) {
    free(*ptr);
    *ptr = NULL;
  }
}

/**
 *  @brief Create lower case copy of the @link{str}
 *
 *  @note ! Under the hood uses allocated memory!
 *
 *  @param {const char *} str - string for copiing
 *
 *  @return {char*} - lower case copy of the @link{str}
 *  @throw if failed to allocate memory area
 *
 *  @example
 *    char str[20] = "RadiO";
 *    char *ptr_str = str_to_low_case(str);
 *    ptr_str{'r', 'a', 'd', 'i', 'o', \0}
 *
 *    ** clean up **
 *    free(ptr_str);
 *    ptr_str = NULL;
 *
 */
static char *str_to_low_case(const char *str) {
  // allocate memory area for copiing string to prevent mutation
  // @note @link{strlen} returns quantity of only visible chars (i.e. \0, \n etc
  // are not counted!)
  size_t str_len = strlen(str);
  // str_len + 1 ? => to add free space for '\0' last char
  char *ptr_buffer = (char *)calloc(str_len + 1, sizeof(char));

  // check that memory allocation process succeeded
  if (ptr_buffer == NULL) {
    puts("Error(str_to_low_case() function): fail to allocate memory area");
    return NULL;
  }

  // create copy of @link{str}
  memcpy(ptr_buffer, str, (str_len + 1) * sizeof(char));

  // create for sure valid C string with last '\0'
  ptr_buffer[str_len] = '\0';

  // set @link{str} to lower case
  for (size_t i = 0; i < str_len; i += 1) {
    ptr_buffer[i] = (char)tolower(ptr_buffer[i]);
  }

  // return allocated memory area with lower case @link{str}
  return ptr_buffer;
}

/**
 *  @brief Check that @link{str} contains "ra" substring (case insensitive)
 *
 *  @note ! Impure function! It has implicit dependencies of:
 *    - @link{str_to_low_case} function
 *    - @link{clean_up} function
 *
 *  @note Under the hood uses the allocated memory areas (with proper clean ups)
 *
 *  @param {const char *} str - string for checking
 *
 *  @return {1} - true, @link{str} contains "ra"
 *  @return {0} - false, otherwise
 *
 *  @example
 *    char str[20] = "RaDiO";
 *    is_correct(str) => 1;
 *
 *    char str[20] = "Banana";
 *    is_correct(str) => 0;
 *
 */
int is_correct(const char *str) {
  // create lower case @link{str} copy
  char *ptr_str = str_to_low_case(str);

  // check that lower case @link{str} copy exist
  if (ptr_str == NULL) {
    return 0;
  }

  // check that @link{ptr_str} contains "ra"
  if (strstr(ptr_str, "ra") != NULL) {
    clean_up((void **)&ptr_str);
    return 1;
  }

  clean_up((void **)&ptr_str);

  return 0;
}
