#include "./utils.h"

/**
 *  @brief Check @link{notes_arr} for _do, _mi, _sol of @type{NOTES} and only
 *  them to the @link{major_notes_arr}
 *
 *  @note ! Impure function! Depends on @link{NOTES} enum !
 *  @note Mutates the outer @link{major_notes_arr}
 *
 *  @param {const NOTES []} notes_arr - array to check
 *  @param {type} NOTES_ARR_SIZE - size of @link{notes_arr}
 *  @param {type} major_notes_arr - array to fill
 *  @param {type} MAJOR_NOTES_ARR_SIZE - size of @link{major_notes_arr}
 *  @param {check_major_callback} callback - @see{get_major}
 *
 *  @return {size_t} - quantity of notes, that pass the check
 *  @throw if @link{NOTES_ARR_SIZE} != @link{MAJOR_NOTES_ARR_SIZE}
 *
 *  @example
 *    NOTES notes_arr[5] = {_do, _mi, _sol, _re, _la};
 *    size_t NOTES_ARR_SIZE = 5;
 *    NOTES major_notes_arr[5] = {0};
 *    size_t MAJOR_NOTES_ARR_SIZE = 5;
 *
 *    check_notes(notes_arr, NOTES_ARR_SIZE, major_notes_arr,
 *      MAJOR_NOTES_ARR_SIZE, get_major) => 3
 *    =>
 *    major_notes_arr{_do, _mi, _sol}
 *
 */
size_t check_notes(const NOTES notes_arr[], const size_t NOTES_ARR_SIZE,
                   NOTES major_notes_arr[], const size_t MAJOR_NOTES_ARR_SIZE,
                   check_major_callback callback) {
  if (NOTES_ARR_SIZE != MAJOR_NOTES_ARR_SIZE) {
    puts("Error: NOTES_ARR_SIZE != MAJOR_NOTES_ARR_SIZE");
    return 0;
  }

  size_t index = 0;

  for (size_t i = 0; i < NOTES_ARR_SIZE; i += 1) {
    if (callback(notes_arr[i])) {
      major_notes_arr[index] = notes_arr[i];
      index += 1;
    }
  }

  return index;
}
