nclude<stdio.h>
#include<iostream>
#include <math.h>
#include<algorithm>
#include <string>
#include<string.h>
//#include<chrono>
#include<vector>
using namespace std;

void solver(char line[][60], char answer[], int m, int n,int length)
{ 
	int iter;
	int xPivot;
	int yPivot;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			iter = 0;
			if (line[i][j] == toupper(answer[iter]) || line[i][j] == tolower(answer[iter]))
			{
				iter++;
				for (int a = -1; a < 2; a++)
				{
					if (i + a < 0 || i + a >= m)
					{}
					else
					{
						for (int b = -1; b < 2; b++)
						{
							if (j + b < 0 || j + b >= n || (a == 0 && b == 0))
							{}
							else
							{
								iter = 1;
								xPivot = i;
								yPivot = j;

								while (line[xPivot + a][yPivot + b]==tolower(answer[iter])|| line[xPivot + a][yPivot + b] == toupper(answer[iter]))//대소문자 구분 없이 비교해야 한다
								{
									iter++;
									xPivot = xPivot + a;
									yPivot = yPivot + b;
									if (iter == length)
									{
										cout << i+1 << " " << j+1 << endl;
										return;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


int main()
{
	int caseNum;

	scanf("%d", &caseNum);

	while (caseNum--) 
	{

		// Get Problem
		int m;
		int n;

		char line[60][60];

		scanf("%d %d", &m, &n);

		string input;
		// allocate array
		for (int i = 0; i < m; i++)
		{
			cin >> input; 
			strcpy(line[i], input.c_str());
			//cout << line[i][2] << endl;
		}


		// Get answer
		int k;

		cin >> k;
		char answer[20][60];
		for (int i = 0; i < k; i++)
		{
			cin >> input;
			strcpy(answer[i], input.c_str());	
		}

		// Problem solver
		for (int i = 0; i < k; i++)
		{
			solver(line,answer[i],m,n,strlen(answer[i]));
		}

		if(caseNum!=0)
			cout << endl;
	}
	
	return 0;
}

