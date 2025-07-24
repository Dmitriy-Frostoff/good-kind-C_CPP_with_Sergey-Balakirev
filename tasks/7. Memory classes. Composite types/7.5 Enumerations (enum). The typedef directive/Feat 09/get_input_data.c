#include "./utils.h"

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
 *  @note ! Only for allocated memory area pointers !
 *  @note ! free() and makes NULL outer @link{ptr} !
 *  @note Under the hood narrowing pointer to @type{char}
 *
 *  @param {void *} ptr - pointer to the allocated memory area
 *
 *  @example
 *    char *ptr = (char *)calloc(10, sizeof(char));
 *
 *    clean_up(ptr) => void
 *    ptr{NULL}
 */
static void clean_up(void *ptr) {
  // clean up
  free((char *)ptr);
  ptr = NULL;
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
  char *ptr_word = strtok(ptr_string, " ");
  size_t arr_index = 0;

  if (ptr_word == NULL) {
    puts(
        "Error(get_input_data() function): fail to split string into words via "
        "space separator");
    clean_up(ptr_string);
    return word_count;
  }

  while (ptr_word != NULL) {
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
 *  @param {type} arr_size -
 *  @param {char []} separator - string like separator, e.g. " ", ", " , ",;"
 *    (means that every ',' or ';' will be assumed as separator)
 *
 *  @return {int} - qunatity of got words after separation
 *  @throw if process of memory allocation has failed
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
    return 1;
  }

  // get the entire string of words (space separated)
  fgets(ptr_buffer, WORDS_QUANTITY * WORD_LENGTH, stdin);

  // remove last '\n' in the str
  remove_last_word_n(ptr_buffer);

  // break string into the words
  count = break_string_into_words(arr, ptr_buffer, separator, WORD_LENGTH);

  // clean up
  clean_up(ptr_buffer);

  return count;
}
