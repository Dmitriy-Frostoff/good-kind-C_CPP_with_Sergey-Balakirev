/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191249/step/11?thread=solutions&unit=1204220}
 *
 */
#include <stdio.h>

int main(void) {
  long long var_ll = 0;
  long double var_ld = 0.;
  short sh = 0;

  scanf("%lld, %Lf, %hd", &var_ll, &var_ld, &sh);
  printf("%lld %d", var_ll, sh);

  return 0;
}
