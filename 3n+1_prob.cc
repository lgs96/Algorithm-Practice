#include <iostream>
#include <math.h>
#include<algorithm>
#include<chrono>
#include<vector>
using namespace std;

#define mm ((s+e)>>1)

int tree[1<<21];

int init(int node, int begin, int end) {
	if (begin == end) return tree[node] = 0;
	int mid = (begin + end) / 2;
	return tree[node] = init(node * 2, begin, mid) + init(node * 2 + 1, mid + 1, end);
}

int sum(int node, int begin, int end, int left, int right) {
	if (end < left || right < begin) return 0;
	if (left <= begin && end <= right) return tree[node];
	int mid = (begin + end) / 2;
	return max(sum(node * 2, begin, mid, left, right), sum(node * 2 + 1, mid + 1, end, left, right));
}

void update(int node, int begin, int end, int index, int diff) {
	if (index < begin || end < index) return;
	tree[node] = max(tree[node], diff);
	if (begin == end) return;
	int mid = (begin + end) / 2;
	update(node * 2, begin, mid, index, diff);
	update(node * 2 + 1, mid + 1, end, index, diff);
}


int main()
{

	int a, b;
	const int lim = 1000000;
	unsigned int cycleLength;
	unsigned int *cache = new unsigned int[lim];
	init(1,0,lim-1);

	for (int i = 0; i < lim; i++)
	{
		cache[i] = 0;
	}

   //Cache calculation results with dynamic programming
	for (unsigned int i = 0; i < lim; i++)
	{
		cycleLength = 1;
		unsigned int input = i + 1;

		while (input != 1)
		{
			if ((input)<=lim && cache[input - 1] != 0)
			{
				cycleLength += cache[input - 1]-1;
				break;
			}

			if (input % 2 == 0)
			{
				input = input / 2;
			}
			else if (input % 2 == 1)
			{
				input = input * 3 + 1;
			}
			cycleLength += 1;
		}
		cache[i] = cycleLength;
		update(1,0,lim-1,i+1,cycleLength);
	}
	

	//Get results with O(n) complexity
	while (scanf("%d %d", &a, &b) != EOF) {

		int temp_a = a;
		int temp_b = b;

		if (a > b) swap(a, b);

		printf("%d %d %d\n", temp_a, temp_b, sum(1, 0, lim - 1, a, b));


	}

	return 0;
}



