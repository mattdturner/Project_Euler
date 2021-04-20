/* Problem 7 for project euler

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

#include <iostream>

bool isItPrime(long int n);

int main () {
  int cnt = 0;
  int maxN = 10001;
  bool prime = false;
  long int num = 0;

  while ( cnt <= maxN ) {
    prime = isItPrime(num);
    if ( prime ) {
      cnt++;
    }
    num++;
  }

  std::cout << "The " << maxN << " prime number is " << num-1 << "\n";
}

bool isItPrime(long int n) {
  // 0 and 1 are not prime numbers...
  if ( n == 0 || n == 1 ){
    return false;
  }

  for ( int i = 2; i < n / 2; i++ ) {
    if ( n % i == 0 ) {
      return false;
    }
  }

  // If we made it here, then it is a prime number
  return true;
}
