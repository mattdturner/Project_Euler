/* Problem 10 of Project Euler

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million

*/

#include <iostream>
#include <string.h>

bool isItPrime(long int n) {
  // 0 and 1 are not prime numbers...
  if ( n == 0 || n == 1 ){
    return false;
  }

  for ( int i = 2; i <= n / 2; i++ ) {
    if ( n % i == 0 ) {
      return false;
    }
  }

  // If we made it here, then it is a prime number
  return true;
}

long int sumPrimes(const int sumBelow) {
  long int sum=0;

  #pragma omp parallel for reduction(+:sum)
  for (int i = 0; i < sumBelow; i++) {
    if ( isItPrime(i) ) {
      sum += i;
    }
  }
  return sum;
}

long int sieveOfEratosthenes(int limit) {
  // Create a boolean array to hold if a number is a prime.
  // Initialize it to true.  It will be set to false later if
  // the number is not a prime.
  bool primes[limit+1];
  std::memset(primes, true, sizeof(primes));

  for (int p = 2; p*p <= limit; p++) {
    if ( primes[p] ) {
      // Set all multiples of p as not prime
      for ( int i = p*p; i <= limit; i+=p) {
        primes[i] = false;
      }
    }
  }

  // Return the sum of all prime numbers
  long int sum = 0;
  for (int p = 2; p <= limit; p++) {
    if ( primes[p] ) {
      sum += p;
    }
  }
  return sum;
}

int main () {
  int sumBelow = 2000000;
  long int sum;

  // Routine sumPrimes takes a very long time.  Replaced with new sieve of Eratosthenes algo
  //sum = sumPrimes(sumBelow);
  sum = sieveOfEratosthenes(sumBelow);

  std::cout << "The sum of all primes below " << sumBelow << " = " << sum << "\n";
}
