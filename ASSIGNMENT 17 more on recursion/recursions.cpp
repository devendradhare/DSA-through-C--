//                   Assignment-17: More on Recursion
#include <iostream>
using namespace std;
// 1.  recursive function to calculate sum of first N natural numbers
int sum_of_first_n_num(int n)
{
    if (!n)
        return 0;
    return n + sum_of_first_n_num(n - 1);
}
// 2.  recursive function to calculate sum of first N odd natural numbers
int sum_of_first_n_odd_num(int n)
{
    if (!n)
        return 0;
    return n + n - 1 + sum_of_first_n_odd_num(n - 1);
}
// 3.  recursive function to calculate sum of first N even natural numbers
int sum_of_first_n_even_num(int n)
{
    if (!n)
        return 0;
    return n + n + sum_of_first_n_even_num(n - 1);
}

// 4.  recursive function to calculate sum of squares of first N natural numbers
int sum_of_squares_of_first_n_num(int n)
{
    if (!n)
        return 0;
    return n * n + sum_of_squares_of_first_n_num(n - 1);
}
// 5.  recursive function to calculate factorial of a number
int factorial(int n)
{
    if (!n)
        return 1;
    return n * factorial(n - 1);
}
// 6.  recursive function to calculate sum of the digits of a given number
int sum_of_digits(int n)
{
    if (!n)
        return 0;
    return (n % 10) + sum_of_digits(n / 10);
}
// 7.  recursive function to print binary of a given decimal number
void decimal_to_binary(int n)
{
    if (!n)
        return;
    decimal_to_binary(n / 2);
    cout << n % 2;
}
// 8.  recursive function to find nth term of the Fibonacci series
int nth_term_of_fibonacci(int n, int a = -1, int b = 1)
{
    int c = a + b;
    if (!n)
        return c;
    return nth_term_of_fibonacci(n - 1, b, c);
}
// 9.  recursive function to calculate HCF of two numbers
int HCF(int a, int b, int n = 0)
{
    n = !n ? a : n;
    if (a % n == 0 && b % n == 0)
        return n;
    return HCF(a, b, n - 1);
}
// 10. recursive function to calculate x power y.
int power(int a, int b)
{
    if (!b)
        return 1;
    return a * power(a, b - 1);
}

int main()
{
    cout << "\nsum of first 10 number             = " << sum_of_first_n_num(10);
    cout << "\nsum of first 10 odd numbers        = " << sum_of_first_n_odd_num(10);
    cout << "\nsum of first 10 even numbers       = " << sum_of_first_n_even_num(10);
    cout << "\nsum of squares of first 10 numbers = " << sum_of_squares_of_first_n_num(5);
    cout << "\nfactorial of 10                    = " << factorial(10);
    cout << "\nsum of digits of 1234              = " << sum_of_digits(1234);
    cout << "\nbinary of 23 is                    = ";
    decimal_to_binary(23);
    cout << "\n5th term of fibonacci series       = " << nth_term_of_fibonacci(5);
    cout << "\nHCF of 12 and 13 is                = " << HCF(12, 13);
    cout << "\n0 the power 0                      = " << power(0, 0);
    return 0;
}