// Febraury 2015, Codechef challenge problem 1.
// http://www.codechef.com/FEB15/problems/CHEFCH

#include<iostream>
#include<string>
#include<limits>
#include<stdio.h>

using namespace std;

int main()
{
	int numTestCases;
	string inputString;
	int countFirstMinus, countSecondMinus,i,j;
	int length;
	cin>>numTestCases;
	cin.ignore( numeric_limits< streamsize >::max(), '\n' );
	
	for(i = 0; i < numTestCases; i++)
	{
		getline(cin, inputString);
		countFirstMinus = 0;
		countSecondMinus = 0;
		length = inputString.length();
		for(j =0 ; j<length; j+=2)
		{
			if(inputString[j] == '-')
				countSecondMinus++;
			else
				countFirstMinus++;

			if(j+1 != length)
			{
				if(inputString[j+1] == '+')
					countSecondMinus++;
				else
					countFirstMinus++;
			}
		}

		if(countFirstMinus < countSecondMinus)
			printf("%d\n", countFirstMinus);
		else
			printf("%d\n", countSecondMinus);
	}

	return 0;
}