#include <iostream>
using namespace std;

//              Assignment-16: Recursion
// 1. Write a recursive function to print first N natural numbers
void first_n_natural(int n)
{
    if (!n)
        return;
    first_n_natural(n - 1);
    cout << " " << n;
}
// 2. Write a recursive function to print first N natural numbers in reverse order
void first_n_natural_reverse(int n)
{
    if (!n)
        return;
    cout << " " << n;
    first_n_natural_reverse(n - 1);
}
// 3. Write a recursive function to print first N odd natural numbers
void first_n_odd(int n)
{
    if (!n)
        return;
    cout << " " << n * 2 - 1;
    first_n_odd(n - 1);
}
// 4. Write a recursive function to print first N odd natural numbers in reverse order
void first_n_odd_reverse(int n)
{
    if (!n)
        return;
    first_n_odd_reverse(n - 1);
    cout << " " << n * 2 - 1;
}
// 5. Write a recursive function to print first N even natural numbers
void first_n_even(int n)
{
    if (!n)
        return;
    first_n_even(n - 1);
    cout << " " << n + n;
}
// 6. Write a recursive function to print first N even natural numbers in reverse order.
void first_n_even_reverse(int n)
{
    if (!n)
        return;
    cout << " " << n + n;
    first_n_even_reverse(n - 1);
}
// 7. Write a recursive function to print squares of first N natural numbers
void first_n_squares(int n)
{
    if (!n)
        return;
    first_n_squares(n - 1);
    cout << " " << n * n;
}
// 8. Write a recursive function to print squares of first N natural numbers in reverse order.
void first_n_squares_reverse(int n)
{
    if (!n)
        return;
    cout << " " << n * n;
    first_n_squares_reverse(n - 1);
}
// 9. Write a recursive function to print cubes of first N natural numbers
void first_n_cube(int n)
{
    if (!n)
        return;
    first_n_cube(n - 1);
    cout << " " << n * n * n;
}
// 10.Write a recursive function to print cubes of first N natural numbers in reverse order
void first_n_cube_reverse(int n)
{
    if (!n)
        return;
    cout << " " << n * n * n;
    first_n_cube_reverse(n - 1);
}

int main()
{
    cout << "\nfirst n natural numbers                      = ";
    first_n_natural(10);

    cout << "\nfirst n natural numbers in reverse           = ";
    first_n_natural_reverse(10);

    cout << "\nfirst n odd natural number                   = ";
    first_n_odd(10);

    cout << "\nfirst n odd natural number in reverse        = ";
    first_n_odd_reverse(10);

    cout << "\nfirst n even natural number                  = ";
    first_n_even(10);

    cout << "\nfirst n even natural number in reverse       = ";
    first_n_even_reverse(10);

    cout << "\nsquares of first n natural numbers           = ";
    first_n_squares(10);

    cout << "\nsquares of first n natural number in reverse = ";
    first_n_squares_reverse(10);

    cout << "\ncube of first n natural number               = ";
    first_n_cube(10);

    cout << "\ncube of first n natural number in reverse    = ";
    first_n_cube_reverse(10);

    return 0;
}