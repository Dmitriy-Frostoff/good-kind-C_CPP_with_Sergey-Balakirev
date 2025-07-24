#ifndef CONFIG_H
#define CONFIG_H

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { WORDS_QUANTITY = 20, WORD_LENGTH = 50 };

typedef int (*FUNC_CORRECT)(const char *str);
typedef char WORD[WORD_LENGTH];
typedef WORD WORDS_ARR[WORDS_QUANTITY];

#endif
