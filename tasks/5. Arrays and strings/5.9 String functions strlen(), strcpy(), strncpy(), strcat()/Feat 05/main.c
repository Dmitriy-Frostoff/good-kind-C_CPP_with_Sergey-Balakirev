/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191299/step/7?unit=1204287}
 *
 */

#include <stdio.h>
#include <string.h>

#define SURNAME_COUNT 7
#define SURNAME_LENGTH 50
#define PS_RES_LENGTH (SURNAME_COUNT * SURNAME_LENGTH + 7)

int main(void) {
  char ps[SURNAME_COUNT][SURNAME_LENGTH] = {0};
  // prevent unpredictable characters at arr =>
  // use initialization
  char ps_res[PS_RES_LENGTH] = {0};

  for (int i = 0; i < SURNAME_COUNT; i += 1) {
    // %50s => SURNAME_LENGTH = 50
    if (scanf("%50s", ps[i]) != 1) {
      printf("expected surname with max 50 characters");
      return 0;
    }
  }

  for (int i = 0; i < SURNAME_COUNT; i += 1) {
    int ps_res_length = (int)strlen(ps_res);
    strncat(ps_res, ps[i], (int)sizeof(ps_res) - ps_res_length - 1);
    ps_res_length = (int)strlen(ps_res);

    if (i == SURNAME_COUNT - 1) {
      ps_res[ps_res_length] = '\0';
      break;
    }

    ps_res[ps_res_length] = ' ';
  }

  puts(ps_res);

  /**
   *  макроопределение для тестирования
   *  (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__
  return 0;
}
