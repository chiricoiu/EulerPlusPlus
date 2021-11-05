/*
if we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

answer : 233168
*/

#include <iostream>

int sumMultiple(int n)
{
    int sum = 0;
    for(int i=1; i<n; ++i)
    {
        if(i%3 == 0 or i%5 == 0)
        {
            sum = sum + i;
        }
        
    }
    return sum;
}

int main()
{
    std::cout << sumMultiple(1000) << std::endl;
    return 0;
}


