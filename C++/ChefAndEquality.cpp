// Febraury 2015, Codechef challenge problem.
// http://www.codechef.com/FEB15/problems/CHEFEQ

#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int numTestCases;
    int inputSize;
    int maxInputSize = 100000;
    int hash[maxInputSize], input[maxInputSize];
    int i,j, duplicate;

    // Input the number of test cases.
    cin>>numTestCases;

    for(i = 0; i < numTestCases; i++)
    {
        // Clear the hash array
        for(j =0; j< maxInputSize; j++)
            hash[j] = 0;

        duplicate = 0;
        // Input the size of input
        cin>>inputSize;
        for(j=0;j<inputSize; j++)
        {
            cin>>input[j];
            hash[input[j]]++;

            // Get the maximum number of duplicates.
            duplicate = max(duplicate, hash[input[j]]);
        }

        printf("%d\n", inputSize - duplicate);
    }

    return 0;
}