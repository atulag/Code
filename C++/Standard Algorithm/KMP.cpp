/* 
    Knuth-Morris-Pratt algorithm for pattern searching problem
    
    Input:
        String inputStr which is the primary string.
        String patternStr which is the pattern string we want to
        search in inputStr.

    Output:
        Where the pattern begin in inputStr.
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

/*  Function declaration */
void KMPAlgorithm(string inputStr, string patternStr);
void ComputePatternTable(string patternStr, int *patternTable);

// Main function
int main(int argc, char const *argv[])
{
    string inputStr, patternStr;
    printf("Enter the primary string:\n");
    getline(cin, inputStr);
    printf("Enter the pattern string:\n");
    getline(cin, patternStr);

    // Call KMPAlgorithm to do pattern searching
    KMPAlgorithm(inputStr, patternStr);
    return 0;
}

/*  Function definations */

// Computes the partial mattching table for pattern string.
void ComputePatternTable(string patternStr, int *patternTable)
{
    int previousMatchLength = 0;
    int lengthStr = patternStr.length();

    patternTable[0] = 0;
    int i = 1;
    for(i = 1; i < lengthStr; i++)
    {
        if(patternStr[i] == patternStr[previousMatchLength])
        {
            previousMatchLength++;
            patternTable[i] = previousMatchLength;
        }
        else if(previousMatchLength > 0)
        {
            previousMatchLength = patternTable[previousMatchLength - 1];

            // Move back to the current index again.
            i--;
        }
        else
        {
            // previousMatchLength is already 0.
            patternTable[i] = previousMatchLength;
        }
    }

    return;
}

// Implements KMP algorithm
void KMPAlgorithm(string inputStr, string patternStr)
{
    int inputStrLength = inputStr.length();
    int patternStrLength = patternStr.length();

    int *patternTable = (int*)malloc(sizeof(int)*patternStrLength);
    ComputePatternTable(patternStr, patternTable);

    int i=0, j=0;
    while(i < inputStrLength)
    {
        if(inputStr[i] == patternStr[j])
        {
            if(j == patternStrLength - 1)
            {
                printf("Pattern found at start index:%d\n", i-j);
                i++;
                j = patternTable[j];
            }
            else
            {
                i++;
                j++;
            }
        }
        else if (j != 0)
        {
            j = patternTable[j-1];
        }
        else
        {
            i++;
        }
    }

    free(patternTable);
    return;
}