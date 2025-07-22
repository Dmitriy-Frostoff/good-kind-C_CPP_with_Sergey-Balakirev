/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191314/step/6?unit=1204302}
 *
 *  Declare 'enum' with identificator 'menu_item' that contains constant values:
 *  item_exit = 1, item_c = 2, item_python = 3, item_java = 4
 *
 *  In the 'main' function read the integer from the INPUT: and compare it with
 *  the data from enum 'menu_item' (use 'switch' operator for that).
 *
 *  Use the next scheme and print the correspondent message to the console
 *  (@note without ""):
 *  item_exit: "Выход";
 *  item_c: "Язык Си";
 *  item_python: "Язык Python";
 *  item_java: "Язык Java".
 *
 *  if no match was met, print "Не верный пункт меню"
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  int input_data = 0;

  // get the @link{input_data} from the INPUT:
  if (get_input_data(&input_data) != 0) {
    return 1;
  }

  // check the @link{input_data}
  char *ptr_message = (char *)check_input_case(input_data);

  if (ptr_message == NULL) {
    puts("Error: 'check_input_case' function returned NULL");
    return 1;
  }

  // print message
  puts(ptr_message);

  // clean up
  free(ptr_message);
  ptr_message = NULL;

  return 0;
}
