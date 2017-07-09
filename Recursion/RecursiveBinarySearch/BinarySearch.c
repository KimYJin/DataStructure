#define _CRT_SECURE_NO_WARNINGS

//  BinarySearch 

#include<stdio.h>

int BSearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (arr[mid] == target)
			return mid;			//search success
		else
		{
			if (target < arr[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}

	return -1;	//search fail

}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int index;

	index = BSearch(arr, sizeof(arr) / sizeof(int), 7);

	if (index == -1)
		printf("Search Fail\n");
	else
		printf("index stored target: %d\n", index);

	index = BSearch(arr, sizeof(arr) / sizeof(int), 4);

	if (index == -1)
		printf("Search Fail\n");
	else
		printf("index stored target: %d\n", index);

	return 0;
}
