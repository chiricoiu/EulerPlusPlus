/*
A palindromic number reads the same both ways. 
The largest palindrome made from the product of 
two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from 
the product of two 3-digit numbers.

answer : 906609
*/

#include <iostream>
#include <chrono>

#include<string>

bool isPalindrome(int number)
{
    auto strNumber = std::to_string(number);
    int length = strNumber.length();
    int flag = 0;

    for (int i = 0; i < length; i++)
    {
        if (strNumber[i] != strNumber[length - i - 1])
        {
            flag = 1;
            break;
        }
        
    } 

    if (flag == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int largestPalindrome(int digits)
{
    std::string str = "";

    for (int i = 0; i < digits; i++)
    {
        str.append(std::to_string(9));
    }

    int largest = 0;

    for (int i = std::stoi(str); i>1; i--)
    {
        for (int j = std::stoi(str); j>1; j--)
        {
            if (isPalindrome(i*j) == true and i*j > largest)
            {                
                largest = i*j;
                break;
            }        
        }       
    }  
    return largest;    
}

int main()
{
    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << largestPalindrome(3) << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "solved in: " << std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count() << " msec" << std::endl;
    return 0;
}