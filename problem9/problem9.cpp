/* Problem 9 for Project Euler

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

https://projecteuler.net/problem=9

*/

#include <iostream>

long int pythagTriplet(int tripletSum) {
  long int product;
  int sum;

  for (int a = 1; a < tripletSum; a++) {
    for (int b = a+1; b < tripletSum; b++) {
      for (int c = b+1; c < tripletSum; c++) {
        if ( a*a + b*b == c*c ) {
          if ( a+b+c == tripletSum ) {
            std::cout << "Triplet numbers = " << a << ", " << b << ", " << c << "\n";
            return a*b*c;
          }
        }
      }
    }
  }

  // If we got here, no answer found
  return 0;
}

int main () {
  int tripletSum = 1000;
  long int product;

  product = pythagTriplet(tripletSum);

  std::cout << "The product of the triplet = " << product << "\n";
}
