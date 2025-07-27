/**
 *  The task description is at
 *  @link{https://stepik.org/lesson/1191316/step/5?unit=1204304}
 *
 */

#include "./config.h"
#include "./utils.h"

int main(void) {
  const double USD_RUB_RATIO = 91.32;
  double usd_balance = 0.0;

  // allocate memory for the @link{account_r}
  RUBS_USD_EXCHANGE *account_r =
      (RUBS_USD_EXCHANGE *)calloc(1, sizeof(RUBS_USD_EXCHANGE));

  if (account_r == NULL) {
    puts("Error(main() function): couldn't allocate memory for "
         "RUBS_USD_EXCHANGE type data");
    return 1;
  }

  // count @link{usd_balance} and mutate @link{account_r} fields
  usd_balance = get_usd_quantity(account_r, USD_RUB_RATIO, get_input_data);

  if (usd_balance == -1) {
    return 1;
  }

  // print the usd balance
  printf("%.2f", usd_balance);

  /*
   * макроопределение для тестирования
   * (не убирать и должно идти непосредственно перед return 0)
   */
  __ASSERT_TESTS__

  // clean up
  free(account_r);
  account_r = NULL;

  return 0;
}
