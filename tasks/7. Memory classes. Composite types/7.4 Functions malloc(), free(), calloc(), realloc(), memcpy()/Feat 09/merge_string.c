#include "./utils.h"

/**
 *  @brief Merge two strings and return address of the result
 *
 *  @note ! Don't forget to free() allocated memory after usage of the result !
 *
 *  @param {const char *} str1 - pointer to the first string
 *  @param {const char *} str2 - pointer to the second string
 *
 *  @return {char*} - pointer to the allocated memory area with valid C string
 *    data (result of merging str1 + str2)
 *
 *  @example
 *    char str1 = "Hello,"
 *    char str2 = "World!)"
 *    char *ptr = merge_string(str1, str2);
 *    =>
 *    ptr{"Hello, World!)\0"}
 *
 *    ! clean up after all !
 *    free(ptr);
 *    ptr = NULL;
 *
 */
char *merge_string(const char *str1, const char *str2) {
  size_t str1_length = strlen(str1);
  size_t str2_length = strlen(str2);
  // ... + 1 ? => to add last '\0' char
  char *ptr = (char *)calloc(str1_length + str2_length + 1, sizeof(char));

  if (ptr == NULL) {
    return NULL;
  }

  // copy strings data to the allocated memory area @link{ptr}
  memcpy(ptr, str1, str1_length * sizeof(char));
  // ptr + str1_length ? => no nest @link{str2} right after @link{str1}
  memcpy(ptr + str1_length, str2, str2_length * sizeof(char));

  // create correct C string
  ptr[str1_length + str2_length] = '\0';

  return ptr;
}
