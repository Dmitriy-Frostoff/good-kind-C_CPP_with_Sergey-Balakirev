#include "./utils.h"

/**
 *  @brief Count the USD quantity and mutate the @link{person} fields
 *
 *  @note ! Impure function !
 *  - mutates outer @link{person} fields: @link{person->ratio_usd} and
 *    @link{person->rubs};
 *  - depends on @link{RUBS_USD_EXCHANGE} type
 *  - depends on @link{get_rubles} callback type
 *
 *  @param {RUBS_USD_EXCHANGE} person - pointer to the exchange struct
 *    @note it based on an allocated memory area !
 *  @param {double} usd_ratio - 1 USD to RUB exchange rate (1$ = xx rubles)
 *  @param {get_rubles} callback - @see{get_rubles} and @see{get_input_data}
 *
 *  @return {double} - counted quantity of USD
 *  @return {-1.0} - if not positive rubles quantity was produced or problems
 *    occured at the INPUT: process
 *
 *  @example
 *    RUBS_USD_EXCHANGE *person = (RUBS_USD_EXCHANGE *)calloc(1,
 *      sizeof(RUBS_USD_EXCHANGE));
 *    double usd_ratio = 100;
 *    double usd_balance = 0.0;
 *
 *    usd_balance = get_rubles_quantity(&person, usd_ratio, get_input_data);
 *    INPUT:
 *    1000 =>
 *    usd_balance = 10.0000 (1000 / 100.0);
 *    person {
 *      ratio_usd = 100;
 *      rubs = 1000;
 *    }
 *
 *    **clean up**
 *    free(person);
 *    @note and do `person = NULL` at the area of declaring!
 *
 *    usd_balance = get_rubles_quantity(&person, usd_ratio, get_input_data);
 *    INPUT:
 *    -1000 =>
 *    usd_balance = -1;
 *    person {
 *      ratio_usd = 0;
 *      rubs = 0;
 *    }
 *    @note rubles quantity is < 0, person data didn't mutate this case
 *
 *    **clean up**
 *    free(person);
 *    @note and do `person = NULL` at the area of declaring!
 *
 */
double get_usd_quantity(RUBS_USD_EXCHANGE *person, double usd_ratio,
                        get_rubles callback) {
  int rubs_quantity = 0;
  double usd_balance = 0.0;

  // get rubs quantity
  if (callback(&rubs_quantity) == -1) {
    return -1;
  }

  // set @link{person->ratio_usd}
  person->ratio_usd = usd_ratio;
  // set @link{person->rubs_quantity}
  person->rubs = rubs_quantity;

  // count usd balance
  usd_balance = person->rubs / person->ratio_usd;

  return usd_balance;
}
