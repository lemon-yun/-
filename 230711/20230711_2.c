#include <stdio.h>

void paixu(int arr[], int x)
{
	int j, k;
	for (j = 0; j < x - 1; j++)
	{
		for (k = 0; k < x - 1 - j; k++)
		{
			if (arr[k] > arr[k + 1])
			{
				int y = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = y;
			}
		}
	}
}

int main()
{
	int arr[100] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	paixu(arr, sz);
	return 0;
}