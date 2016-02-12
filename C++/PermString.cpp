/*
    Print all the permutations of a string using iteration

    Input:
        String inputStr;

    Output:
        Permutations of inputStr;
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    string inputStr;
    printf("Enter the string for which you want all permutations:\n");
    getline(cin, inputStr);

    int strLength = inputStr.length();
    int *permTable = (int *)malloc(sizeof(int)*strLength);
    
    int i, count = 0;
    char ch;

    for(i =0; i< strLength; i++)
    {
        permTable[i] = 0;
    }

    i = strLength - 2;

    printf("\nAll permutation\n%s\n", inputStr.c_str());
    count++;

    while(true)
    {
        if(i == 0 && permTable[i] == strLength - 1)
        {
            break;
        }

        // back track
        // swap inputStr[i], inputStr[i+permTable[i]]
        {
            ch = inputStr[i];
            inputStr[i] = inputStr[i+permTable[i]];
            inputStr[i+permTable[i]] = ch;
        }

        if(permTable[i] != strLength - 1 - i)
        {
            permTable[i]++;

            // swap inputStr[i], inputStr[i+permTable[i]]
            {
                ch = inputStr[i];
                inputStr[i] = inputStr[i+permTable[i]];
                inputStr[i+permTable[i]] = ch;
            }
            
            printf("%s\n", inputStr.c_str());
            i = strLength - 2;
            count++;
        }
        else
        {
            permTable[i] = 0;
            i--;
        }
    }

    printf("Permuation count: %d\n", count);
    return 0;
}