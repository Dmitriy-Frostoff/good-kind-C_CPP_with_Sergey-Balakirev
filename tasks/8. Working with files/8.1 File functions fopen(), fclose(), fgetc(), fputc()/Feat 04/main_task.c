#include "./config.h"
#include "./utils.h"

/**
 *  @brief Just a wrapper function for tests
 *  @note only one main function can be used and this one is
 *  absolutely similar to main() but for GTests running
 *  @note one can rename @link{main_task} -> @link{main} for sure
 *
 */
int main_task(void) {
  // open file stream
  FILE *f_stream = fopen("test.dat", "r");

  // check that stream was opened
  if (f_stream == NULL) {
    return 2;
  }

  // close file stream
  if (fclose(f_stream) != 0) {
    fprintf(stderr,
            "(%s at line %d): error occurred while file stream closing\n",
            __func__, __LINE__);
    return 1;
  }

  return 0;
}
