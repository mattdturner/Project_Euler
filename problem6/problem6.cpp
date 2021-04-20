/* Problem 6 of project euler

The sum of the squares of the first ten natural numbers is,

The square of the sum of the first ten natural numbers is,

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is .

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

https://projecteuler.net/problem=6

*/

#include <iostream>

long int sumOfSquares(int maxN);
long int squareOfSum(int maxN);

int main () {
  int maxN = 100;
  long int sumSquare, squareSum;
  sumSquare = sumOfSquares(maxN);
  squareSum = squareOfSum(maxN);

  std::cout << "Difference between sum of square (" << sumSquare << ") and square of sum (" << 
               squareSum << ") = " << squareSum - sumSquare << "\n";
}

long int sumOfSquares(int maxN) {
  long int res;

  res = 0;
  for ( int i = 1; i <= maxN; i++) {
    res = res + i * i;
  }

  return res;
}

long int squareOfSum(int maxN) {
  long int res;
  res = 0;
  for ( int i = 1; i <= maxN; i++) {
    res = res + i;
  }
  return res*res;
}
