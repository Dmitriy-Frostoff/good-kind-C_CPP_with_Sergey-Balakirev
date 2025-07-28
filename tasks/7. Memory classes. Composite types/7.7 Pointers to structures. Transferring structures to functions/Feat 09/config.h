#ifndef CONFIG_H
#define CONFIG_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  @details
 *  {int} STR_SIZE - size of string for surname in the @link{PERSON}
 *  {int} CHOICE_STR_SIZE - size of string for choices letters
 *
 */
enum { STR_SIZE = 100, CHOICE_STR_SIZE = 6 };

enum choice_letters { f = 102, o = 111, g = 103, s = 115, e = 101 };

/**
 *  @details
 *  {char} fname[STR_SIZE] - person's surname
 *  {int} old - person's age
 *  {int} stag - person's work experience
 *  {int} salary - person's salary
 *  {double} efs - person's work efficiency
 *
 */
typedef struct employee {
  char fname[STR_SIZE];
  int old;
  int stag;
  int salary;
  double efs;
} PERSON;

#endif
