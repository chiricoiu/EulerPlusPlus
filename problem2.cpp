/*
Each new term in the Fibonacci sequence is generated by adding 
the previous two terms. By starting with 1 and 2, the first 10 
terms will be:
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...


By considering the terms in the Fibonacci sequence whose values 
do not exceed four million, find the sum of the even-valued terms.

answer : 4613732
*/

#include <iostream>

int sumEvenFibonacci(int n)
{
    int term1 = 1;
    int term2 = 2;
    int term3 = 0;
    int sumEven = 0;

    while(term3<n)
    {
        term3 = term1 + term2;      
        if(term3%2 == 0)
        {
            sumEven = sumEven + term3;            
        }
        term1 = term2;
        term2 = term3;
    }
    return sumEven + 2;
}

int main()
{
    std::cout << sumEvenFibonacci(4000000) << std::endl;
    return 0;
}