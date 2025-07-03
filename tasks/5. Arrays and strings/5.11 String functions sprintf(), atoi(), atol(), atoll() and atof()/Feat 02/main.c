/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191301/step/4?unit=1204289}
 *
 */

#include <stdio.h>
#include <string.h>

// "hh\0" => 3
#define STR_TIME_PART_SIZE (2 + 1)
// "hh:mm:ss\0"
#define STR_TIME_HH_MM_SS_SIZE (2 * 3 + 2 + 1)
#define MAX_HOUR_LITERAL 24
#define MAX_MINUTES_LITERAL 60
#define MAX_SECONDS_LITERAL 60

int main(void) {
  int h;
  int m;
  int s;
  char str_hour_literal[STR_TIME_PART_SIZE] = {0};
  char str_minutes_literal[STR_TIME_PART_SIZE] = {0};
  char str_seconds_literal[STR_TIME_PART_SIZE] = {0};
  char res_str[STR_TIME_HH_MM_SS_SIZE] = {0};

  // get hours, minutes, seconds
  if (scanf("%d %d %d", &h, &m, &s) != 3) {
    printf("expected three space separated integers like: hh mm ss");
    return 0;
  }

  // check that h [0 : 23], m[0 : 59], s[0 : 59] or set "--" otherwise
  h / MAX_HOUR_LITERAL == 0 ? sprintf(str_hour_literal, "%02d", h)
                            : sprintf(str_hour_literal, "--");
  m / MAX_MINUTES_LITERAL == 0 ? sprintf(str_minutes_literal, "%02d", m)
                               : sprintf(str_minutes_literal, "--");
  s / MAX_SECONDS_LITERAL == 0 ? sprintf(str_seconds_literal, "%02d", s)
                               : sprintf(str_seconds_literal, "--");

  //  combine 'res_str'
  snprintf(res_str, sizeof(res_str), "%s:%s:%s", str_hour_literal,
           str_minutes_literal, str_seconds_literal);
  puts(res_str);

  return 0;
}
