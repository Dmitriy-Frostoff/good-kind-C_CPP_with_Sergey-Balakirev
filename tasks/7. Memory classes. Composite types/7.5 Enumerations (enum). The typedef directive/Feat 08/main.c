/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191314/step/10?unit=1204302}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  enum { ARR_SIZE = 5 };

  NOTES notes_arr[ARR_SIZE] = {0};
  NOTES major_notes_arr[ARR_SIZE] = {0};
  size_t check_notes_count = 0;

  // get notes from the INPUT: to @link{notes_arr}
  if (get_input_data(notes_arr, ARR_SIZE) == 0) {
    return 1;
  };

  // check the notes
  check_notes_count =
      check_notes(notes_arr, ARR_SIZE, major_notes_arr, ARR_SIZE, get_major);

  // no matches ? => empty output
  if (check_notes_count == 0) {
    return 0;
  }

  // print major notes
  print_major_notes(major_notes_arr, ARR_SIZE, check_notes_count);

  return 0;
}
