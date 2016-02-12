/*
================================= PROBLEM DESCRIPTION ==================================
You are given a string S constisting of uppercase Latin letters. Is it possible to reorder
the characters in this string to get a string with prefix "LTIME" and suffix "EMITL"?
We remind you that a prefix of a string is any substring which contains its first character,
while a suffix of a string is substring containing its last character.

Input

The first line contains a single integer T, denoting the number of testcases. The 
descriptions of T test cases follow.
The first and only line of the test case description has one non-empty string S consisting
of uppercase Latin letters only.

Output

For each testcase output a single line containing the string "YES" (without quotes) if it's
possible to reorder the characters to get the required prefix and suffix, or "NO" (without
quotes) otherwise.

Example:
Input:
3
LTIMEAZAZAITLME
LLLTTTIIIMMMEEEAHA
LTIMEM

Output:
YES
YES
NO
============================================================================================
*/

#include <iostream>
#include <stdio.h>
#include <string>                                           // For using string class

using namespace std;

bool reorderPossible(string input);

int main()
{
    int t;                      // Number of test cases
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        string input;
        char inputChar[100];
        //getline(cin, input);
        scanf("%s", inputChar);
        input = inputChar;
        if(reorderPossible(input))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }


    return 0;
}

bool reorderPossible(string input)
{
    int numOcc[5], i, twiceOcc;

    for(i = 0; i < 5; i++)
    {
        numOcc[i] = 0;
    }

    twiceOcc = 0;

    for(i = 0; i < input.size(); i++)
    {
        switch(input[i])
        {
            case 'L':
                numOcc[0]++;
                if(numOcc[0] == 2)
                    twiceOcc++;
                break;

            case 'M':
                numOcc[1]++;
                if(numOcc[1] == 2)
                    twiceOcc++;
                break;

            case 'I':
                numOcc[2]++;
                if(numOcc[2] == 2)
                    twiceOcc++;
                break;

            case 'T':
                numOcc[3]++;
                if(numOcc[3] == 2)
                    twiceOcc++;
                break;

            case 'E':
                numOcc[4]++;
                if(numOcc[4] == 2)
                    twiceOcc++;
                break;

            default:
                break;
        }

        if(twiceOcc == 5)
            return true;
    }

    if(input.size() == 9 && twiceOcc == 4 && numOcc[4] == 1)
    {
        return true;
    }

    if(twiceOcc == 5)
        return true;
    else
        return false;
}