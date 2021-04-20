#include <iostream>

/* This file solves problem 1 from project euler.  The problem statement is:
If we list all the natural numbers below 10 that are multiples of 3 or 5, we
get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

bool mult3or5(int x) {
    int remainder_3;
    int remainder_5;

    remainder_3 = x % 3;
    remainder_5 = x % 5;

    return (remainder_3 == 0) || (remainder_5 == 0);
}


int main() {
    int sum = 0;
    for(int i; i < 1000; i++){
        if ( mult3or5(i) == 1){
            //std::cout << "adding to sum for " << i << "\n";
            sum += i;
        }
        // std::cout << "is " << i << " divisible by 3 or 5? " << mult3or5(i) << "\n";
    }
    std::cout << "Sum = " << sum << "\n";
}

