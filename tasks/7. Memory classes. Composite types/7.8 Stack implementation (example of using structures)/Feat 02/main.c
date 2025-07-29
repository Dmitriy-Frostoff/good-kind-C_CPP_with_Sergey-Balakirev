/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191317/step/4?unit=1204305}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  OBJ *top = NULL;

  // fill the stack
  top = push(top, "https://proproprogs.ru/c_base/"
                  "c_etapy-translyacii-programmy-v-mashinnyy-kod-standarty");
  top = push(top, "https://proproprogs.ru/c_base/"
                  "c_struktura-i-ponimanie-raboty-programmy-hello-world");
  top = push(
      top,
      "https://proproprogs.ru/c_base/"
      "c_dvoichnaya-shestnadcaterichnaya-i-vosmerichnaya-sistemy-schisleniya");
  top = push(top,
             "https://proproprogs.ru/c_base/c_lokalnye-i-globalnye-peremennye");
  top = push(
      top,
      "https://proproprogs.ru/c_base/c_perechisleniya-enum-direktiva-typedef");

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  // __ASSERT_TESTS__

  // empty the stack
  top = empty_stack(top, pop);

  if (top != NULL) {
    puts("Error(empty_stack() function): stack wasn't emptied properly!");
    return 1;
  }

  return 0;
}
