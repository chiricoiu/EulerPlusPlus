/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?

answer : 6857
*/

#include <iostream>
#include <chrono>

long long int largestPrimeFactor(long long int n)
{
    long long int i=2;
    do
    {
        if (n%i != 0)
        {
            i++;
        }
        else
        {
            n = n / i;
        }        
    } while (i <= n);
    return i;    
}

int main()
{
    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << largestPrimeFactor(600851475143) << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "solved in: " << std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count() << " msec" << std::endl;
    return 0;
}
