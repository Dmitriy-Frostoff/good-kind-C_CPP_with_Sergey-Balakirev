/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191300/step/8?unit=1204288}
 *
 */

#include <stdio.h>
#include <string.h>

#define CITY_SIZE 10
#define CITY_NAME_SIZE 50
#define MAX_WORD_SPACES (CITY_SIZE - 1)

int main(void) {
  char cities[CITY_SIZE][CITY_NAME_SIZE] = {0};
  const char EXCLUDE_CHARS[] = "на";
  char *ptr_search_n = NULL;
  char *ptr_search_excl_chars = NULL;
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

  // fill 'res_str' with city name (without EXCLUDE_CHARS (e.g. "на"))
  // >>> Барнаул\n Кишинев\n Ярославль\n => {Кишинев, Ярославль}
  for (int i = 0; i < CITY_SIZE; i += 1) {
    ptr_search_excl_chars = strstr(cities[i], EXCLUDE_CHARS);

    if (ptr_search_excl_chars == NULL) {
      strncat(res_str, cities[i],
              (int)sizeof(res_str) - 1 - (int)strlen(res_str));
      strcat(res_str, " ");
    }
  }

  // reset pointer
  ptr_search_excl_chars = NULL;

  puts(res_str);

  return 0;
}
