/*
Given a string s, partition s such that every string of the partition is a pallindrome.
Return all possible pallindrome partitioning of s.

======Input=====
String "aab"
================

======Output======
Output: [ ["a", "a", "b"], ["aa", "b"]]
==================
*/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>

using namespace std;

bool isPallindrome(string str);
void partitionHelper(string &str, int index, vector<string> &curr, vector<vector<string> > &result);
vector<vector<string> > partition(string str);
void printPartition(vector<vector<string> > result);

int main()
{
    string input;
    cout<<"Enter the input string:";
    cin>>input;

    vector<vector<string> > result = partition(input);
    //cout<<"Partition completed";
    printPartition(result);
    return 0;
}

bool isPallindrome(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while(i < j)
    {
        if(str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void partitionHelper(string &str, int index, vector<string> &curr, vector<vector<string> > &result)
{
    if(index == str.length())
    {
        result.push_back(curr);
        return;
    }

    for(int i = 1; i <= str.length() - index; i++)
    {
        string substring = str.substr(index, i);
        if(isPallindrome(substring))
        {
            curr.push_back(substring);
            partitionHelper(str, index + i, curr, result);
            curr.pop_back();
        }
    }
}

vector<vector<string> > partition(string str)
{
    vector<vector<string> > result;
    vector<string> curr;
    //cout<<str<<endl;
    partitionHelper(str, 0, curr, result);
    return result;
}

void printPartition(vector<vector<string> > result)
{
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<"\t";
        }

        cout<<endl;
    }
}