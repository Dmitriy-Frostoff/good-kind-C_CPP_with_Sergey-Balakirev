/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191253/step/6?unit=1204224}
 *
 */

#include <stdio.h>

int main(void) {
  unsigned short time_h = 10; // hours
  unsigned short time_m = 33; // minutes
  unsigned short time_s = 5;  // seconds

  // increased time's values
  unsigned short time_h_summed;
  unsigned short time_m_summed;
  unsigned short time_s_summed;
  unsigned short time_sec_total;

  // add time: h - hours; m - minutes; s - seconds
  unsigned short h;
  unsigned short m;
  unsigned short s;
  scanf("%hu; %hu; %hu", &h, &m, &s);

  // get total additional time in sec to prevent unncecessary countings
  // (over 24 hours, over 60 min, over 60s)
  time_sec_total = h * 3600 + m * 60 + s;

  time_s_summed = (time_s + time_sec_total % 60);
  time_m_summed = time_m + (time_sec_total / 60) % 60 + time_s_summed / 60;
  time_h_summed = time_h + time_sec_total / 3600 + time_m_summed / 60;

  printf("%02d:%02d:%02d", time_h_summed % 24, time_m_summed % 60,
         time_s_summed % 60);

  return 0;
}
