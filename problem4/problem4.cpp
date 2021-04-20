/* This file solves problem 4 of project euler

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

int palindrome(int numDigits);

int main () {
  int numDigits = 3;
  int largest;

  largest = palindrome(numDigits);

  std::cout << "Largest palindrome for a " << numDigits << "-digit number = " 
            << largest << "\n";
}

int palindrome(int numDigits) {
  int res;
  int largest;
  std::string pal, pal_rev;
  int power = pow(10,numDigits);
  for (int i = 1; i < power; i++) {
    for (int j = 1; j < power; j++) {
      res = i * j;
      pal = std::to_string(res);
      pal_rev = pal;
      std::reverse(pal_rev.begin(), pal_rev.end());
      // Compare the 2 strings (pal and reversed pal)
      if ( pal == pal_rev ) {
        // If they are identical, and the result is larger than the current largest, 
        // then save the value
        if ( res > largest ) {
          largest = std::stoi(pal);
        }
      }
    }
  }
  return largest;
}
