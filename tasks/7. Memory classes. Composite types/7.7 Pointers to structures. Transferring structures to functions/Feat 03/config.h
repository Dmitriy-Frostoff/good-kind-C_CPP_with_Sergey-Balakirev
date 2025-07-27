#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>

/**
 *  @details
 *  {double} ratio_usd - 1 USD to RUB exchange rate (1$ = xx rubles)
 *  {int} rubs - rubles quantity
 *
 */
typedef struct tag_rub {
  double ratio_usd;
  int rubs;
} RUBS_USD_EXCHANGE;

typedef int (*get_rubles)(int *rubs);

#endif
