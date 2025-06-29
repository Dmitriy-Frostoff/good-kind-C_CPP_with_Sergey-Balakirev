/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191249/step/12?unit=1204220}
 *
 */
#include <stdio.h>

int main(void) {
  float temperature_1;
  float temperature_2;
  float temperature_3;
  float temperature_4;
  float temperature_5;
  float temperature_6;
  float temperature_7;
  float temperature_8;
  float temperature_9;
  float temperature_10;

  scanf("%f; %f; %f; %f; %f; %f; %f; %f; %f; %f; -1", &temperature_1,
        &temperature_2, &temperature_3, &temperature_4, &temperature_5,
        &temperature_6, &temperature_7, &temperature_8, &temperature_9,
        &temperature_10);

  printf("%.1f %.1f %.1f %.1f %.1f", temperature_6, temperature_7,
         temperature_8, temperature_9, temperature_10);

  return 0;
}
