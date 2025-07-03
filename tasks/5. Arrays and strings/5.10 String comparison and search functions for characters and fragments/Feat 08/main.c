/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191300/step/10?unit=1204288}
 *
 */

#include <stdio.h>
#include <string.h>

// two integers + '\0'
#define TIME_DATA_SIZE (2 + 1)
// hh:mm:ss\0 => 9
#define TIME_FORMAT_SIZE (TIME_DATA_SIZE * 3)

int main(void) {
  char str_hours[TIME_DATA_SIZE] = {0};
  char str_minutes[TIME_DATA_SIZE] = {0};
  char str_seconds[TIME_DATA_SIZE] = {0};
  char input_str[TIME_FORMAT_SIZE] = {0};
  char res_str[TIME_FORMAT_SIZE] = {0};
  const char TIME_DELIMETER[] = ":";

  char *ptr_str_start = NULL;
  char *ptr_str_end = NULL;

  if (fgets(input_str, (int)sizeof(input_str), stdin) == NULL) {
    puts("empty input string. End of process");
    return 0;
  }

  // get hours from the input
  ptr_str_start = input_str;
  ptr_str_end = strchr(input_str, *TIME_DELIMETER);

  if (ptr_str_start && ptr_str_end) {
    strncpy(str_hours, ptr_str_start, ptr_str_end - ptr_str_start);
    strcat(str_hours, "\0");
  }

  // get minutes from the input
  ptr_str_start = ptr_str_end + 1;
  ptr_str_end = strchr(ptr_str_start, *TIME_DELIMETER);

  if (ptr_str_start && ptr_str_end) {
    strncpy(str_minutes, ptr_str_start, ptr_str_end - ptr_str_start);
    strcat(str_minutes, "\0");
  }

  // get seconds from the input
  ptr_str_start = ptr_str_end + 1;
  ptr_str_end = strchr(ptr_str_start, '\0');

  if (ptr_str_start && ptr_str_end) {
    strncpy(str_seconds, ptr_str_start, ptr_str_end - ptr_str_start);
    strcat(str_seconds, "\0");
  }

  // create 'res_str'
  // >>> "15:24:10" => "10:24:15"
  strcat(res_str, str_seconds);
  strcat(res_str, TIME_DELIMETER);
  strcat(res_str, str_minutes);
  strcat(res_str, TIME_DELIMETER);
  strcat(res_str, str_hours);
  strcat(res_str, "\0");

  puts(res_str);

  return 0;
}
