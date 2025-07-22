#include "./utils.h"

/**
 *  @brief Check the @link{code} and return the result message
 *
 *  The check scheme:
 *  enum menu_item {
 *   item_exit = 1, item_c = 2, item_python = 3, item_java = 4
 *  };
 *
 *  item_exit: "Выход";
 *  item_c: "Язык Си";
 *  item_python: "Язык Python";
 *  item_java: "Язык Java"
 *
 *  or default message (for not listed code char)
 *  "Не верный пункт меню"
 *
 *  @note ! Don't forget to free allocated memory area after funtion usage!
 *  @note ! Don't forget to narrow returned allocated memeory area address to
 *    proper data type (it's assumed to be @type{char} )!
 *  @note ! Impure function! Depends on global @link{enum menu_item} !
 *
 *  @param {int} code - integer that specifies the result message
 *
 *  @return {void *} - allocated memory address with message
 *
 *  @example
 *    char *ptr_message = (char *)check_input_case(2);
 *    =>
 *    ptr_message{"Язык Си"}
 *    ! Clean up !
 *    free(ptr_message);
 *    ptr_message = NULL;
 *
 *    char *ptr_message = (char *)check_input_case(10);
 *    =>
 *    ptr_message{"Не верный пункт меню"}
 *    ! Clean up !
 *    free(ptr_message);
 *    ptr_message = NULL;
 *
 */
void *check_input_case(int code) {
  // enums defenitions
  typedef enum {
    MESSAGE_LEN = (size_t)strlen("Не верный пункт меню") + 1,
  } max_str_len;

  // 'switch' operator parts
  const char STR_ITEM_EXIT[] = "Выход";
  size_t str_len_item_exit = strlen(STR_ITEM_EXIT) + 1;

  const char STR_ITEM_C[] = "Язык Си";
  size_t str_len_item_c = strlen(STR_ITEM_C) + 1;

  const char STR_ITEM_PYTHON[] = "Язык Python";
  size_t str_len_item_python = strlen(STR_ITEM_PYTHON) + 1;

  const char STR_ITEM_JAVA[] = "Язык Java";
  size_t str_len_item_java = strlen(STR_ITEM_JAVA) + 1;

  const char STR_DEFAULT[] = "Не верный пункт меню";
  size_t str_len_default = strlen(STR_DEFAULT) + 1;

  // allocate buffer for output message
  max_str_len message_size = MESSAGE_LEN;
  char *ptr_str = (char *)calloc(message_size, sizeof(char));

  if (ptr_str == NULL) {
    return NULL;
  }

  // check @link{code} and assign message to the @link{ptr_str}
  switch (code) {
  case item_exit:
    memcpy(ptr_str, STR_ITEM_EXIT, str_len_item_exit * sizeof(char));
    // create valid C string
    ptr_str[str_len_item_exit] = '\0';
    break;
  case item_c:
    memcpy(ptr_str, STR_ITEM_C, str_len_item_c * sizeof(char));
    // create valid C string
    ptr_str[str_len_item_c] = '\0';
    break;
  case item_python:
    memcpy(ptr_str, STR_ITEM_PYTHON, str_len_item_python * sizeof(char));
    // create valid C string
    ptr_str[str_len_item_python] = '\0';
    break;
  case item_java:
    memcpy(ptr_str, STR_ITEM_JAVA, str_len_item_java * sizeof(char));
    // create valid C string
    ptr_str[str_len_item_java] = '\0';
    break;
  default:
    memcpy(ptr_str, STR_DEFAULT, str_len_default * sizeof(char));
    // create valid C string
    ptr_str[str_len_default] = '\0';
    break;
  }

  return ptr_str;
}
