#include "./utils.h"

/**
 *  @brief Get the prime factors of @link{num}
 *
 *  @note ! Impure function! Depends on macros @link{PRIME_FACTORS_QUANTITY} !
 *  @note ! Impure function! Mutates the outer @link{arr} !
 *
 *  @param {unsigned int} num - number for breaking into prime factors
 *  @param {unsigned int} arr - array to fill with founded prime factors of
 *    @link{num}
 *  @param {size_t} arr_size - size of @link{arr}
 *  @param {void (*)(unsigned short arr[], size_t arr_size)} callback -
 *    @see{get_eratosthen_sieve} callback
 *
 *  @return {size_t} - quantity of got prime factors
 *
 *  @example
 *    unsigned int num = 874;
 *    unsigned int arr[20] = {0}
 *    size_t arr_size = 20;
 *    @see{get_eratosthen_sieve} callback
 *    get_prime_factors_of_num(num, arr_size, get_eratosthen_sieve) => 3
 *      arr{2, 19, 23}
 *
 *    unsigned int num = 2;
 *    -//-
 *    get_prime_factors_of_num(num, arr_size, get_eratosthen_sieve) => 1
 *      arr{2}
 *
 *    unsigned int num = 1;
 *    -//-
 *    get_prime_factors_of_num(num, arr_size, get_eratosthen_sieve) => 1
 *      arr{1}
 *
 *    unsigned int num = 9484;
 *    -//-
 *    get_prime_factors_of_num(num, arr_size, get_eratosthen_sieve) => 3
 *      arr{2, 2, 2371}
 *
 */
size_t get_prime_factors_of_num(unsigned int num, unsigned int arr[],
                                size_t arr_size,
                                void (*callback)(unsigned short arr[],
                                                 size_t arr_size)) {
  // get the primes factors
  unsigned short primes_arr[PRIME_FACTORS_QUANTITY] = {0};
  size_t primes_arr_size = sizeof(primes_arr) / sizeof(*primes_arr);
  callback(primes_arr, primes_arr_size);

  // prime factorization
  size_t primes_arr_index = 0;
  size_t arr_index = 0;
  unsigned int current_quotient = num;

  // 0 or 1 ? => return quantity 1 and add num itself to the @link{arr}
  if (num < 2) {
    arr[arr_index] = num;
    arr_index += 1;
    return arr_index;
  }

  // 2 ? => is the first prime factor (<= 1 is not)
  while (current_quotient >= 2) {
    if (current_quotient % primes_arr[primes_arr_index] == 0) {
      // update quotient
      current_quotient /= primes_arr[primes_arr_index];
      // add the prime factor
      if (arr_index < arr_size) {
        arr[arr_index] = primes_arr[primes_arr_index];
        // set index to next cell
        arr_index += 1;

        // reset @link{primes_arr_index} to start from the begining of the
        // @link{primes_arr}
        primes_arr_index = 0;
        continue;
      }
    }
    primes_arr_index += 1;
  }

  // @note prime factors quantity is arr_index + 1 (index starts from 0)
  // e.g. num = 49, arr{7, 7} => arr_index = 1, nums quantity = 2
  //  (arr_index + 1)
  return arr_index;
}
