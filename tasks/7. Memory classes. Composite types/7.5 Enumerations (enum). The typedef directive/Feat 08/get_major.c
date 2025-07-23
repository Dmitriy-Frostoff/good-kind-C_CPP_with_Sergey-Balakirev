#include "./utils.h"

/**
 *  @brief Check that the note one of _do (1) || _mi (3) || _sol (5),
 *  where _do, _mi, _sol are defined in @link{NOTES} enum
 *
 *  @note ! Impure function! Depends on @link{NOTES} enum !
 *
 *  @param {NOTES} note - note to check
 *
 *  @return {1} - note is one of the _do (1) || _mi (3) || _sol (5)
 *  @return {0} - note is not one of the _do (1) || _mi (3) || _sol (5)
 *
 *  @example
 *      get_major(_do) => 1
 *      get_major(_mi) => 1
 *      get_major(_sol) => 1
 *      get_major(_re) => 0
 *
 */
char get_major(NOTES note) {
  if (note == _do || note == _mi || note == _sol) {
    return 1;
  }

  return 0;
}
