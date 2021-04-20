/* Problem 3 for Project Euler
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 *
 */

#include <iostream>
#include <cmath>

void primeFactors(long int n);

int main () {
    //int n = 13195;
    long int n;
    std::cout << "What number do you want the largest prime factor for?  ";
    std::cin >> n;

    primeFactors(n);
}

void primeFactors(long int n) {
    int largestFactor = 0;
    while ( n % 2 == 0 ) {
        // Find all instances where 2 is a factor
        n = n / 2;
        largestFactor = 2;
    }

    // Find the rest of the factors, knowing that n must be odd now
    for (int i = 3; i <= sqrt(n); i=i+2) {
        while ( n%i == 0 ) {
            n = n/i;
            //std::cout << i << "\n";
            if ( i > largestFactor ) {
                largestFactor = i;
            }
        }
    }

    // print n if it is > 2 (last prime factor)
    if ( n > 2 ) {
        std::cout << n << "\n";
        if ( n > largestFactor ) {
            largestFactor = n;
        }
    }
    std::cout << "Largest prime factor = " << largestFactor << "\n";
}
