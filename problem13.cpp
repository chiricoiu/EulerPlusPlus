/*
Work out the first ten digits of the sum of the following one-hundred 
50-digit numbers

result : 5537376230
*/

#include <iostream>
#include <chrono>

#include <fstream>
#include <vector>
using std::vector;

vector<vector<int>> readDigits(int nrows, int ncols)
{
    vector<vector<int>> matrix(nrows, vector<int>(ncols, 0));
    std::fstream txtfile;
    txtfile.open("data/problem13/listDigits.txt", std::ios::in);
    // To open the file in reading mode - ios::in
    // To open the file in writing mode - ios::out
    if (txtfile.is_open())
    {
        int num_line = 0;
        std::string line;
        while (std::getline(txtfile, line))
        {
            int i = 0;
            for (auto digit : line)
            {
                matrix[num_line][i] = digit - '0';
                i++;
            }
            num_line++;            
        }
    }
    txtfile.close();
    return matrix;
}

vector<int> sumDigits(vector<vector<int>> matrixDigits)
{
    vector<int> digitcol(50, 0);
    int div = 0;
    for (int j = matrixDigits[0].size() - 1; j >= 0; j--)
    {
        int sumcol = div;
        for (int i = 0; i < matrixDigits.size(); i++)
        {
            sumcol += matrixDigits[i][j];
        }
        div = sumcol / 10;
        
        if (j == 0)
        {
            digitcol[j] = sumcol;
        }
        else
        {
            digitcol[j] = sumcol % 10;
        }
    }
    return digitcol;
}

int main()
{
    auto t0 = std::chrono::high_resolution_clock::now();    
    vector<vector<int>> matrix = readDigits(100, 50);
    vector<int> sum_digits = sumDigits(matrix);
    for (int i = 0; i < 8; i++)
    {
        std::cout << sum_digits[i];
    }
    std::cout << std::endl;   
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "solved in: " << std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count() << " msec" << std::endl;
    return 0;
}