#include <iostream>

/* Project 2 from Project Euler
 *
 * Each new term in the Fibonacci sequence is generated by adding the previous 
 * two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not exceed 
 * four million, find the sum of the even-valued terms.
 *
 */

int main () {
    int limit = 100000;
    int fib_sequence[limit];
    int max_i;
    int tmp;
    int sum = 0;

    fib_sequence[0] = 1;
    fib_sequence[1] = 2;

    int i = 1;
    while ( true ) {
	i += 1;
	tmp = fib_sequence[i-1] + fib_sequence[i-2];
        if ( tmp > 4000000 ) {
            max_i = i;
	    break;
	}
        fib_sequence[i] = tmp;
    }


    for ( int i = 0; i < max_i; i++) {
	if ( fib_sequence[i] % 2 == 0 ) {
	    sum += fib_sequence[i];
	}
        //std::cout << fib_sequence[i] << "\n";
    }
    std::cout << "Sum: " << sum << "\n";

}