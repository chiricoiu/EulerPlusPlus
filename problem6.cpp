/*
The sum of the squares of the first ten natural numbers is: 
1² + 2² + ... + 10² = 385

The square of the sum of the first ten natural numbers is:
(1 + 2 + ... + 10)² = 3025

Hence the difference between the sum of the squares of the
first ten natural numbers and the square of the sum is :
3025 - 385 = 2640 

Find the difference between the sum of the squares of the 
first one hundred natural numbers and the square of the sum.

answer : 25164150
*/

#include <iostream>
#include <chrono>

int sumSquares(int n)
{
    int sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        sum += i*i;
    }    
    return sum;
}

int squareSum(int n)
{
    int sum = 0;
    for (int i = 1; i < n+1; i++)
    {
        sum += i;
    }    
    return sum*sum;
}

int main()
{
    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << squareSum(100) - sumSquares(100) << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "solved in: " << std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count() << " msec" << std::endl;
    return 0;
}