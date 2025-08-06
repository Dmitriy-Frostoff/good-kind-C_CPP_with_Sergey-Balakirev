#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>

/**
 *  @brief Bit field defining the person characterisitcs:
 *
 *  @details
 *  - field old - person's age (size: 7 bits)
 *  - field salary - person's salary (size: 20 bits)
 *  - field height - person's height (size: 8 bits)
 *  - field weight - person's weight (size: 7 bits)
 *
 */
typedef struct bit_field_person {
  unsigned int old : 7;     /**< person's age */
  unsigned int salary : 20; /**< person's salary */
  unsigned int height : 8;  /**< person's height */
  unsigned int weight : 7;  /**< person's weight */
} PERSON_DATA;

#endif
