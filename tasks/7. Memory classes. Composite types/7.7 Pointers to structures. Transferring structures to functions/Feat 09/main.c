/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191316/step/11?unit=1204304}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  PERSON person = {};

  // fill the @link{person} fields due to format string
  fill_data(&person, "#o #e #s #f", 30, 85.0, 12000, "Doe");

  return 0;
}
