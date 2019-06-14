#include<stdio.h>
#include<iostream>
#include <math.h>
#include<algorithm>
//#include<chrono>
#include<vector>
using namespace std;

int main()
{
	//Get results with O(n) complexity
	int count = 1;

	while (scanf("%d", &count) != EOF) 
	{
		bool *hasValue = new bool[count];

		for (int i = 1; i < count; i++)
		{
			hasValue[i] = false;
		}
		int prevNum;
		int recentNum;
		int differ;
		int jollyCounter = 0;

		scanf("%d", &prevNum);

		for (int i = 1; i < count; i++)
		{
			scanf("%d", &recentNum);
			differ = abs(recentNum - prevNum);

			prevNum = recentNum;

			if (differ < count)
			{
				if (hasValue[differ] == true)
				{
				}
				else
				{
					jollyCounter += 1;
					hasValue[differ] = true;
				}
			}
		}

		for (int i = 1; i < count; i++)
		{
			if (hasValue[i] == false)
			{
				jollyCounter = 0;

			}
		}

		if (jollyCounter == count - 1 )
		{
			printf("Jolly\n");
		}
		else
		{
			printf("Not jolly\n");
		}
	}
	
	
	return 0;
}




