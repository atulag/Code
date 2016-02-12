// Maximum occuring character in the string

#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    string input;
    int count[256] = {0};
    getline(cin, input);
    
    int i, length = input.length();
    char ch;
    int maxCount = 0, temp;

    for(i = 0; i<length; i++)
    {
        temp = (int)input[i];
        
        if(maxCount < count[temp])
        {
            maxCount = count[temp];
            ch = input[i];
        }
    }

    printf("%c\n", ch);
    return 0;
}