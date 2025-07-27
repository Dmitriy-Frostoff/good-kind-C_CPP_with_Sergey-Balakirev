#ifndef UTILS_H
#define UTILS_H

#include "./config.h"

int get_input_data(int *rubs);
double get_usd_quantity(RUBS_USD_EXCHANGE *person, double usd_ratio,
                        get_rubles callback);

#endif
