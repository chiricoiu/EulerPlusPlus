/*
2520 is the smallest number that can be divided
by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly
divisible by all of the numbers from 1 to 20?

answer : 232792560
*/

#include <iostream>
#include <chrono>

int smallestDiv(int n)
{
    int flag = 1;
    int num = n;  
    do
    {
        flag = 0;
        num++;
        for (int i = 1; i < n+1; i++)
        {
            if (num % i != 0)
            {
                flag++;
                break;
            }              
        }
    } while (flag != 0);    
    return num;
}

int main()
{
    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << smallestDiv(20) << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "solved in: " << std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count() << " msec" << std::endl;
    return 0;
}