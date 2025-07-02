/**
 * The task description is at
 * @link{https://stepik.org/lesson/1191286/step/11?unit=1204274}
 *
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define DecimalLiteral 10

int main(void) {
  unsigned short m;
  unsigned short n;

  if (scanf("%hu %hu", &m, &n) != 2 || m < 0 || n < 0 || m >= n) {
    printf("expected two positive integers 'm' and 'n' where m < n");
    return 0;
  }

  for (unsigned short num = m; num <= n; num += 1) {
    unsigned short numCopyForDigitsCount = num;
    unsigned short numCopy = num;
    unsigned char leftDigit;
    unsigned char rightDigit;
    unsigned char digitsCountBefore = 0;
    unsigned char digitsCountAfter = 0;
    bool isPalindrome = false;

    /**
     * @example
     *     123 => 1, 3 (isPalindrome => false) => 0
     *     12345 => 1, 5 (isPalindrome => false) => 234 => 2, 4 (isPalindrome =>
     * false) => 0 123321 => 1, 1 (isPalindrome => true)
     *        => 2332 => 2, 2 (isPalindrome => true) => 33 (isPalindrome =>
     * true) => 0
     */
    while (numCopy >= 10) {
      /**
       * @example
       *    0 => 1
       *    9 => 1
       *    123 => 3
       *    1234 => 4
       */
      do {
        numCopyForDigitsCount /= DecimalLiteral;
        digitsCountBefore += 1;
      } while (numCopyForDigitsCount > 0);

      leftDigit =
          numCopy / (unsigned short)pow(DecimalLiteral, digitsCountBefore - 1);
      rightDigit = numCopy % DecimalLiteral;

      isPalindrome = leftDigit == rightDigit ? true : false;

      // break the next iterations if isPalindrome == false
      if (!isPalindrome) {
        numCopy = -1;
      }

      /**
       * @example
       *    10024 => 1002
       *    1001 => 100
       */
      numCopy = numCopy / DecimalLiteral;

      // (digitsCountBefore - 1) - 1 => digitsCountBefore - 2 =>
      //     because in previous iteration
      //     numCopy reduced by 1 digit from the end
      /**
       * @example
       *    1002 => 2 (002 => 2)
       *    100 => 0 (00 => 0)
       */
      numCopy =
          numCopy % (unsigned short)pow(DecimalLiteral, digitsCountBefore - 2);

      // update numCopyForDigitsCount
      numCopyForDigitsCount = numCopy;

      /**
       * @example
       *    0 => 1
       *    9 => 1
       *    123 => 3
       *    1234 => 4
       */
      do {
        numCopyForDigitsCount /= DecimalLiteral;
        digitsCountAfter += 1;
      } while (numCopyForDigitsCount > 0);

      // update numCopyForDigitsCount
      numCopyForDigitsCount = numCopy;

      // for numbers with 0 inside
      /**
       * @example
       *    1024 (4 digits) => 102 => 02 (isPalindrome ? noup) => 2 (one digit)
       *     (after one iteration num decreased for more than two digits)
       *    10024 (5 digits) => 1002 => 002 (noup) => 2 (one digit)
       *    10001 (5 digits) => 1000 => 000 (yep) => 0
       *        all three 0 turn into one 0 and 10001 is palindrome
       *        that's why numCopy != 0 is in the condition (for that case)
       */
      if (digitsCountBefore - digitsCountAfter > 2 && numCopy != 0) {
        isPalindrome = false;

        // break the next iterations if isPalindrome == false
        numCopy = -1;
      }

      // reset digitsCounts
      digitsCountBefore = 0;
      digitsCountAfter = 0;
    }

    // print only correct num
    if (isPalindrome) {
      printf("%u ", num);
    }
  }

  return 0;
}
