/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191299/step/4?unit=1204287}
 *
 */

#include <stdio.h>
#include <string.h>

#define CITIES_QUANTITY 6
#define CITY_NAME_MAX_LENGTH 50 - 1

int main(void) {
  char cities[CITIES_QUANTITY][CITY_NAME_MAX_LENGTH];
  int length_max_city_name = -1;
  int index_max_city_name_length = 0;

  for (int i = 0; i < CITIES_QUANTITY; i += 1) {
    if (scanf("%49s", cities[i]) != 1) {
      printf("expected City name max 49 characters length");
    }
  }

  for (int i = 0; i < CITIES_QUANTITY; i += 1) {
    int the_city_length = (int)strlen(cities[i]);

    if (the_city_length > length_max_city_name) {
      length_max_city_name = the_city_length;
      index_max_city_name_length = i;
    }
  }

  puts(cities[index_max_city_name_length]);
  return 0;
}
