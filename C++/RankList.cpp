// Febraury 2015, Codechef challenge problem.
// http://www.codechef.com/FEB15/problems/RANKLIST

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, t;
    long long s, diff;
    int num_op = 0;
    int i,j,temp, list_maxValue;
    
    // Input the number of test cases.
    cin>>t;
    for(i = 0; i<t; i++)
    {
        // Input the n and s;
        cin>>n;
        cin>>s;
        list_maxValue = ((int)sqrt(8*s+1)-1)/2;
        diff = s - (list_maxValue*list_maxValue + list_maxValue)/2;

        num_op = n - list_maxValue;
        while(list_maxValue + diff < n)
        {
            num_op++;
            diff+= list_maxValue;
            list_maxValue--;
        }

        printf("%d\n", num_op);
    }

    return 0;
}