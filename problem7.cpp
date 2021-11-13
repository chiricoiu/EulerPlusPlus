/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, 
we can see that the 6th prime is 13.
What is the 10 001st prime number?

answer : 104743
*/

#include <iostream>
#include <chrono>

#include <vector>

bool isPrime(int n)
{
    int flag = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            flag++;
            break;
        }
    }        
    if (flag != 0)
    {
        return false;
    }
    else
    {
        return true;
    }     
}

int umpteenthPrime(int n)
{
    std::vector <int> primeList(n);
    int i=2, pos=0;
    do
    {
        if (isPrime(i) == true)
        {
            primeList[pos] = i;
            pos++;
        }
        i++;        
    } while (pos < n);
    return primeList.back();
}

int main()
{
    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << umpteenthPrime(10001) << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "solved in: " << std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count() << " msec" << std::endl;
    return 0;
    
}
