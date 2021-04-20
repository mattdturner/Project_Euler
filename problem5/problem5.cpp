/* Problem 5 of project euler

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

#include <iostream>

void smallestDivisible(int maxN);

int main () {
  int maxN = 20;
  smallestDivisible(maxN);
}

void smallestDivisible(int maxN) {
  bool success = false;
  int number = maxN;
  while ( !success ) {
    for (int i=1; i <= maxN; i++) {
      if ( number % i != 0 ) {
        break;
      }
      if ( i == maxN ) {
        success = true;
      }
    }
    number++;
  }
  std::cout << "The smallet positive number that is evenly divisible by all of the numbers \n";
  std::cout << "from 1 to " << maxN << " = " << number-1 << "\n";
}
