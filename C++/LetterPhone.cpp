/*
Given a digit string, return all possible number combinations that the number can represent.
The mapping of digit to letters is just like the telephone number.
The digit 0 and 1 maps to itself.
Make sure the strings are lexicographically sorted.

======Input=====
Digit string "23"
================

======Output======
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
==================
*/

#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>

using namespace std;

string GetCharMap(int i);
vector<string> letterCombinations(string A);
void GenerateHelper(string curr, int index, string digits, vector<string> &ans);

int main()
{
    string input;
    cout<<"Enter a digit string:";
    cin>>input;

    vector<string> result = letterCombinations(input);
    for(int j = 0; j < result.size(); j++)
    {
        cout<<result[j]<<endl;
    }

    return 0;
}

string GetCharMap(int i)
{
    string charMap;
    switch(i)
    {
        case 0: charMap = "0";
                break;

        case 1: charMap = "1";
                break;

        case 2: charMap = "abc";
                break;

        case 3: charMap = "def";
                break;

        case 4: charMap = "ghi";
                break;

        case 5: charMap = "jkl";
                break;

        case 6: charMap = "mno";
                break;

        case 7: charMap = "pqrs";
                break;

        case 8: charMap = "tuv";
                break;

        case 9: charMap = "wxyz";
                break;

        default:
                break;
    }

    return charMap;
}

void GenerateHelper(string curr, int index, string digits, vector<string> &ans)
{
    if(index == digits.length())
    {
        ans.push_back(curr);
        return;
    }

    int digit = digits[index] - '0';
    string charMap = GetCharMap(digit);
    for(int i = 0; i < charMap.length(); i++)
    {
        curr.push_back(charMap[i]);
        GenerateHelper(curr, index + 1, digits, ans);
        curr.pop_back();
    }
}

vector<string> letterCombinations(string A)
{
    vector<string> result;
    string curr = "";
    GenerateHelper(curr, 0, A, result);
    return result;
}