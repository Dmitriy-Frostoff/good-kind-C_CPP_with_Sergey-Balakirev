#ifndef CONFIG_H
#define CONFIG_H

#include <locale.h>
#include <stdio.h>
#include <string.h>

#define STR_SRC_SIZE 100
#define STR_DST_SIZE 20

#define CHAR_CODE_A 65
#define CHAR_CODE_Z 90
#define CHAR_CODE_A_LOW 97
#define CHAR_CODE_Z_LOW 122
// All RU letters А-Яа-я are of two bytes 0xD0 + ... or 0xD1 + ...
// 0xD0 0x90 'А', 0xD0 0xAF 'Я'
// 0xD0 0xB0 'а', 0xD1 0x8F 'я', 0xD0 == 208, 0xD1 == 209
#define CHAR_CODE_RU_PREFIX_V1 208
#define CHAR_CODE_RU_PREFIX_V2 209

#endif
