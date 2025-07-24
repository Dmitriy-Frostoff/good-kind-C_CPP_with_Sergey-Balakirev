#include "./utils.h"
#include "config.h"

/**
 *  @brief Remove last '\n' char in the @link{str}
 *
 *  @note ! Not a pure function. Mutates the @link{str} !
 *
 *  @param {char *} str - pointer to the string
 *
 *  @example
 *    char str[] = "Hello, World!)\n"
 *    remove_last_word_n(str) => void
 *    =>
 *    str{"Hello, World!)"}
 *
 */
static void remove_last_word_n(char *str) {
  // get last '\n' char
  char *ptr = strrchr(str, '\n');

  // check that @link{ptr} is not NULL
  if (ptr == NULL) {
    return;
  }

  // replace last '\n' with '\0'
  *ptr = '\0';

  // clean up
  ptr = NULL;
}

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
 *  @brief Break string ( @link{ptr_string} ) into words with @link{separator}
 *    string
 *
 *  @note Expected separator like: " ", "_", ",", ", " etc
 *  @note ! Expected @link{ptr_string} to be allocated memory area only !
 *  @note ! Impure function! Mutates the outer @link{ptr_string} !
 *  @note ! Implicit dependence on @link{clean_up} function !
 *  @note look at @link{WORDS_ARR} type for more
 *
 *  @param {WORDS_ARR} arr - 2d array for strings (i.e. char arr[20][50])
 *  @param {char *} ptr_string - pointer to the string for splitting
 *  @param {char []} separator - string like separator, e.g. " ", ", " , ",;"
 *    (means that every ',' or ';' will be assumed as separator)
 *  @param {int} WORD_LENGTH - max length of word in the @link{arr}
 *
 *  @return {size_t} - qunatity of got words after separation
 *  @throw if no @link{separator} in the @link{ptr_string}
 *
 *  @example
 *    arr of 20 words each of 50 chars max
 *    char arr[20][50] = {0};
 *    char *ptr_string = "God RA";
 *    break_string_into_words(arr, ptr_string, " ", 50) => 2
 *    arr{{'G', 'o', 'd', \0}, {'R', 'A', \0}}
 *
 */
static int break_string_into_words(WORDS_ARR arr, char *ptr_string,
                                   char separator[2], int WORD_LENGTH) {
  int word_count = 0;

  // break string into words via ' ' separator
  char *ptr_word = strtok(ptr_string, separator);
  size_t arr_index = 0;

  if (ptr_word == NULL) {
    puts(
        "Error(get_input_data() function): fail to split string into words via "
        "current separator");
    return word_count;
  }

  while (ptr_word != NULL && arr_index < WORDS_QUANTITY) {
    // safe copy param
    size_t copy_len =
        strlen(ptr_word) + 1 < WORD_LENGTH ? strlen(ptr_word) + 1 : WORD_LENGTH;

    // safe copy the word to the @link{arr}
    memcpy(arr[arr_index], ptr_word, copy_len * sizeof(char));

    // create valid C string
    strcat(arr[arr_index], "\0");

    arr_index += 1;
    word_count += 1;
    ptr_word = strtok(NULL, separator);
  }

  // clean up
  ptr_word = NULL;

  return word_count;
}

/**
 *  @brief Get the string from the INPUT: , breaks it into words (e.g. space is
 *  the separator) and save words to the outer @link{arr}
 *
 *  @note ! Impure function! Mutates outer @link{arr} !
 *  @note Has an implicit dependencies in the module:
 *  - global enums @link{WORDS_QUANTITY} and @link{WORD_LENGTH}
 *  - function (in this module): @link{remove_last_word_n},
 *    @link{break_string_into_words}, @link{clean_up}
 *
 *  @note Under the hood uses allocated memory area with clean ups after all
 *
 *  @param {WORDS_ARR} arr - 2d array for strings (i.e. char arr[20][50])
 *  @param {size_t} arr_size - size of arr (qunatity of rows, e.g. 20)
 *  @param {char []} separator - string like separator, e.g. " ", ", " , ",;"
 *    (means that every ',' or ';' will be assumed as separator)
 *
 *  @return {int} - qunatity of got words after separation
 *  @return {-1} - if one of the below cases happened
 *  @throw if process of memory allocation has failed
 *  @throw if empty string was produced (or something went wrong at INPUT: data)
 *
 *  @example
 *    arr of 20 words each of 50 chars max
 *    char arr[20][50] = {0};
 *    size_t arr_size = 20;
 *
 *    get_input_data(arr, arr_size, " ") =>
 *    INPUT:
 *    God RA => 2
 *    arr{{'G', 'o', 'd', \0}, {'R', 'A', \0}}
 *
 */
int get_input_data(WORDS_ARR arr, size_t arr_size, char separator[]) {
  int count = 0;

  // allocate memmory area
  char *ptr_buffer = (char *)calloc(WORDS_QUANTITY * WORD_LENGTH, sizeof(char));

  if (ptr_buffer == NULL) {
    puts("Error(get_input_data() function): fail to allocate memory area");
    return -1;
  }

  // get the entire string of words (space separated)
  if (fgets(ptr_buffer, WORDS_QUANTITY * WORD_LENGTH, stdin) == NULL) {
    puts("Error(get_input_data() function): empty input string");
    clean_up((void **)&ptr_buffer);
    return -1;
  }

  // remove last '\n' in the str
  remove_last_word_n(ptr_buffer);

  // break string into the words
  count = break_string_into_words(arr, ptr_buffer, separator, WORD_LENGTH);

  // clean up
  clean_up((void **)&ptr_buffer);

  return count;
}
