/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'
You may assume that there will be only one unique solution.
PROBLEM Link - https://www.interviewbit.com/courses/programming/topics/backtracking/problems/sudoku/

This is a good backtracking problem
*/

#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

void printSudoku(vector<vector<char> > &A);
// Returns all the possiblen Numbers at that position.
vector<int> possibleNumbers(vector<vector<char> > &A, int i, int j);
// Recursive function to solve the sudoku
bool sudokuHelper(vector<vector<char> > &A, vector<vector<bool> > &visit, int i, int j);
// sudoku solver
void solveSudoku(vector<vector<char> > &A);

int main()
{
    vector<vector<char> > A;
    int R, C;
    cin>>R;
    cin>>C;
    char ch;

    for(int i = 0; i < R; i++)
    {
        vector<char> row;
        for(int j = 0; j < C; j++)
        {
            cin>>ch;
            row.push_back(ch);
        }

        A.push_back(row);
    }

    cout<<"InputSudoku: "<<endl;
    printSudoku(A);

    solveSudoku(A);
    cout<<"\nOutputSudoku: "<<endl;
    printSudoku(A);

}

void printSudoku(vector<vector<char> > &A)
{
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A[i].size(); j++)
        {
            cout<<A[i][j]<<"  ";
        }

        cout<<endl;
    }
}

// Returns all the possiblen Numbers at that position.
vector<int> possibleNumbers(vector<vector<char> > &A, int i, int j)
{
    vector<int> posN;
    if(A[i][j] != '.')
    {
        posN.push_back(A[i][j] - '0');
        return posN;
    }
    
    bool flag = true;
    int iquad, jquad;
    iquad = (i/3)*3;
    jquad = (j/3)*3;
    for(int k = 1; k < 10; k++)
    {
        int l,m;
        flag = true;
        for(l = 0; l < 9; l++)
        {
            if((A[i][l] -'0' == k) || (A[l][j] - '0' ==k))
            {
                flag =false;
                break;
            }
        }
        
        for(l = iquad; l < iquad + 3; l++)
        {
            for(m = jquad; m < jquad + 3; m++)
            {
                if(A[l][m] - '0' == k)
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag)
        {
            posN.push_back(k);
        }
    }
    
    return posN;
}

// Recursive function to solve the sudoku
bool sudokuHelper(vector<vector<char> > &A, vector<vector<bool> > &visit, int i, int j)
{
    if(i==9 || j == 9)
        return true;
    
    if( i < 0 || j < 0)
        return true;
        
    if(visit[i][j] && A[i][j] != '.')
        return true;
    
    vector<int> posN = possibleNumbers(A, i, j);
    if(posN.size() == 0)
        return false;
    visit[i][j] = true;
    bool rightN = true;
    char old = A[i][j];
    
    for(int k = 0; k < posN.size(); k++)
    {
        A[i][j] = posN[k] + '0';
        rightN = true;
        rightN &= sudokuHelper(A, visit, i, j + 1);
        if(!rightN)
            continue;
        rightN &= sudokuHelper(A, visit, i + 1, j);
        if(!rightN)
            continue;
        rightN &= sudokuHelper(A, visit, i, j - 1);
        if(!rightN)
            continue;
        rightN &= sudokuHelper(A, visit, i - 1, j);
        if(!rightN)
            continue;
            
        if(rightN)
        {
            return true;
        }
    }
    
    if(!rightN)
    {
        visit[i][j] = false;
        A[i][j] = old;
        return false;
    }
}

// sudoku solver
void solveSudoku(vector<vector<char> > &A)
{
    vector<vector<bool> > visit;
    for(int i = 0; i < 9; i++)
    {
        vector<bool> row;
        for(int j = 0; j < 9; j++)
        {
                row.push_back(false);
        }
        visit.push_back(row);
    }
    
    sudokuHelper(A, visit, 0, 0);
}