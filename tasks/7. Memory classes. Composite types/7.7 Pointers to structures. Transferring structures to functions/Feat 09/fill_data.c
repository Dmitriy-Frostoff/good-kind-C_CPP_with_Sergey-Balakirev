#include "./utils.h"
#include "config.h"
#include <stddef.h>

/**
 *  @brief Free allocated memory area via pointer
 *
 *  @note ! Impure function ! Creates side effects:
 *  - frees allocated memory area
 *
 *  @param {void **} ptr - pointer to the allocated memory area
 *    @note Don ' t forget to narrow pointer type to the @type{void **}
 *
 *  @example
 *    char *ptr_buffer = (char *)calloc(10, sizeof(char));
 *
 *    if (ptr_buffer == NULL) {
 *      puts("Error: couldn't allocate memory area");
 *      return 1;
 *    }
 *
 *    ** usage **
 *    clean_up_alloc_mem_ptr((void **)&ptr_buffer);
 *    ptr_buffer = NULL;
 *
 */
static void clean_up_alloc_mem_ptr(void **ptr) {
  if (*ptr != NULL) {
    free(*ptr);
  }
}

/**
 *  @brief Break @link{str} via chars of the @link{SEPARATOR_STRING} and save
 *  the remaining chars to the outer @link{res_str}
 *
 *  @note ! Impure function !
 *  - mutates outer @link{res_str}
 *  - implicit dependency on @link{clean_up_alloc_mem_ptr} function
 *
 *  @note Under the hood uses allocated memory area (via `calloc` function) with
 *  proper clean up
 *
 *  @param {const char *} str - string for extracting command abbreviation
 *    letters
 *  @param {size_t} str_len - size of @link{str}
 *  @param {char *} res_str - string for copying remaining command letters after
 *  wiping unnecessary ones
 *  @param {size_t} RES_STR_SIZE - size of @link{res_str}
 *  @param {const char *} SEPARATOR_STRING - string of chars to handle as
 *    separators (e.g "#' '-,;/")
 *
 *  @throw if process of memory area allocation failed
 *  @throw if @link{str} doesn't have any of @link{SEPARATOR_STRING} chars
 *
 *  @example
 *    char str[] = "#o #e #s #f";
 *    size_t str_len = 11;
 *    char res_str[10] = {0};
 *    size_t res_str_size = 10;
 *    char SEPARATOR_STRING[] = "#' '-,;/";
 *
 *    break_str_into_commands(str, str_len, res_str,
 *      res_str_size, SEPARATOR_STRING) => void
 *    res_str = "oesf"
 *
 *    char str[] = "oesf";
 *    size_t str_len = 11;
 *    char res_str[10] = {0};
 *    size_t res_str_size = 10;
 *    char SEPARATOR_STRING[] = "#' '-,;/";
 *
 *    break_str_into_commands(str, str_len, res_str,
 *      res_str_size, SEPARATOR_STRING) => void
 *    OUTPUT:
 *    "Error(break_str_into_commands() funcion): string doesn't include any "
 *      "of separators #' '-,;/""
 *
 *     res_str = "\0 x 10"
 *
 */
static void break_str_into_commands(const char *str, size_t str_len,
                                    char *res_str, const size_t RES_STR_SIZE,
                                    const char *SEPARATOR_STRING) {
  char *ptr_str = NULL;
  size_t res_str_len = strlen(res_str);

  // allocate memory area
  char *ptr_buffer = (char *)calloc(str_len + 1, sizeof(char));

  if (ptr_buffer == NULL) {
    puts("Error(break_str_into_commands() funcion): couldn't allocate memory "
         "area");
    clean_up_alloc_mem_ptr((void **)&ptr_buffer);
    ptr_buffer = NULL;
    return;
  }

  // copy @link{str}
  memcpy(ptr_buffer, str, str_len + 1);
  // check that string end with '\0'
  ptr_buffer[str_len] = '\0';

  // break @link{str} via next @link{SEPARATOR_STRING}
  ptr_str = strtok(ptr_buffer, SEPARATOR_STRING);

  if (ptr_str == NULL) {
    puts("Error(break_str_into_commands() funcion): string doesn't include any "
         "of separators #' '-,;/");
    clean_up_alloc_mem_ptr((void **)&ptr_buffer);
    ptr_buffer = NULL;
    return;
  }

  while (ptr_str != NULL && res_str_len < RES_STR_SIZE) {
    // copy the char after separator to the @link{res_str}
    if (res_str_len < RES_STR_SIZE) {
      strncat(res_str, ptr_str, 1);
    }

    // update @link{res_str_len} value
    res_str_len = strlen(res_str);

    // step to the next separator
    ptr_str = strtok(NULL, SEPARATOR_STRING);
  }

  // clean up allocated memory area pointer
  clean_up_alloc_mem_ptr((void **)&ptr_buffer);
  ptr_buffer = NULL;

  // clean up static pointer
  ptr_str = NULL;
}

/**
 *  @brief Fill the @link{person} fields with data from the variadic params
 *
 *  Command (format) string is this (it's corresponds with fields in the
 *  @type{PERSON} ):
 *    {char *} #f - string with surname ( @link{PERSON.fname} );
 *    {int} #o - age ( @link{PERSON.old} );
 *    {int} #g - work experience ( @link{PERSON.stag} );
 *    {int} #s - salary ( @link{PERSON.salary} );
 *    {double} #e - work efficiency ( @link{PERSON.efs} );
 *
 *  @note ! Impure function (it ' s also conveyor (aggregator) function)!
 *  - mutates outer @link{person}
 *  - implicit dependency on @type{PERSON}
 *  - implicit dependency on @link{enum choice_letters}
 *  - implicit dependency on variable @link{CHOICE_STR_SIZE}
 *  - implicit dependency on function @link{break_str_into_commands}
 *
 *  @note under the hood uses hardcoded
 *    @link{SEPARATOR_STRING_TEMPLATE} = "#' '-,;/"
 *
 *  @note ! every call of va_arg(arg, type) step to the next variadic param !
 *  ! Do not do so:
 *    ...
 *    case f:
 *    if (strlen(va_arg(arg, const char *)) + 1 < sizeof(person->fname)) {
 *      strcpy(person->fname, va_arg(arg, const char *));
 *      person->fname[strlen(va_arg(arg, const char *)) + 1] = '\0';
 *    }
 *    break;
 *    ...
 *    In this case va_arg(arg, type) steps !!! 3 times to next variable !!!
 *   !
 *
 *  @param {PERSON *} person - structure to fill fields with data (from variadic
 *    params)
 *  @param {const char *} str - string of commands to use (it's length also used
 *    as quantity for variadic params)
 *  @param {char * || int || double} ... - variadic params (up to 5)
 *
 *  @throw if inner @link{break_str_into_commands} function didn't work as
 *  expected ( @link{choice_str} didn't change)
 *  @throw if any letter is not one of predefined in command string (not one of
 *   "fogse")
 *
 *  @example
 *    PERSON person = {};
 *    char command_str[] = "#o #e #s #f";
 *
 *    fill_data(&person, command_str, 30, 85.0, 12000, "Doe") => void
 *    person = {old = 30; efs = 85.0; salary = 12000; fname = "Doe"}
 *
 */
void fill_data(PERSON *person, const char *str, ...) {
  size_t str_len = strlen(str);
  char choice_str[CHOICE_STR_SIZE] = {0};
  size_t choice_str_capacity = sizeof(choice_str) / sizeof(*choice_str);
  size_t choice_str_len = strlen(choice_str);
  const char SEPARATOR_STRING_TEMPLATE[] = "#' '-,;/";

  // fill string of choices letters @link{choice_str}
  break_str_into_commands(str, str_len, choice_str, choice_str_capacity,
                          SEPARATOR_STRING_TEMPLATE);

  // update @link{choice_str_len}
  choice_str_len = strlen(choice_str);

  if (choice_str_len == 0) {
    puts("Error(fill_data() function): break_str_into_commands() function "
         "didn't work as expected");
    return;
  }

  // setup variadic args usage
  va_list arg;
  va_start(arg, str);

  // handle command letters string
  for (size_t i = 0; i < choice_str_len; i += 1) {
    enum choice_letters temp_var = (int)choice_str[i];

    // handle the command letter
    switch (temp_var) {
    case f:
      // copy all the chars from the arg and it will be not greater than
      // capacity of @link{person->fname}
      // @note strncpy() function stop copying if '\0' char met
      strncpy(person->fname, va_arg(arg, const char *), sizeof(person->fname));
      break;
    case o:
      person->old = va_arg(arg, int);
      break;
    case g:
      person->stag = va_arg(arg, int);
      break;
    case s:
      person->salary = va_arg(arg, int);
      break;
    case e:
      person->efs = va_arg(arg, double);
      break;
    default:
      puts("Error(fill_data() function): choice letter is not one of 'fogse'");
      return;
    }
  }

  // wipe the variadic @link{arg}
  va_end(arg);
}
