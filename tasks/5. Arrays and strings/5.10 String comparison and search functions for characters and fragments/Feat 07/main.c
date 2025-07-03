/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191300/step/9?unit=1204288}
 *
 */

#include <stdio.h>
#include <string.h>

#define CITY_SIZE 10
#define CITY_NAME_SIZE 50
#define MAX_WORD_SPACES (CITY_SIZE - 1)

int main(void) {
  char cities[CITY_SIZE][CITY_NAME_SIZE] = {0};
  char *ptr_search_n = NULL;
  char *ptr_search_string = NULL;
  char res_str[CITY_SIZE * CITY_NAME_SIZE + MAX_WORD_SPACES] = {0};

  int city_counter = 0;

  // fill 'cities' array
  while (city_counter < CITY_SIZE &&
         fgets(cities[city_counter], CITY_NAME_SIZE, stdin) != NULL) {
    // get the address of last '\n'
    ptr_search_n = strrchr(cities[city_counter], '\n');

    // empty input? => clean up current string from '\n' and go further
    if (*cities[city_counter] == '\n' || *cities[city_counter] == '\0') {
      *ptr_search_n = '\0';
      continue;
    }

    // remove '\n' from the end of the string
    if (ptr_search_n) {
      *ptr_search_n = '\0';
    }

    city_counter += 1;
  }

  // reset pointer
  ptr_search_n = NULL;

  // fill 'res_str' with city name (without duplication)
  // >>> {Барнаул Кишинев Ярославль Кишинев} =>
  //  "Барнаул, Кишинев, Ярославль"
  for (int i = 0; i < CITY_SIZE; i += 1) {
    ptr_search_string = strstr(res_str, cities[i]);

    // add only unique strings
    if (ptr_search_string == NULL) {
      strncat(res_str, cities[i],
              (int)sizeof(res_str) - 1 - (int)strlen(res_str));
      strcat(res_str, " ");
    }
  }

  // reset pointer
  ptr_search_string = NULL;

  puts(res_str);

  return 0;
}
