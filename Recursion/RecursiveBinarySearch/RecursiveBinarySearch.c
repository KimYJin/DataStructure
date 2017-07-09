#define _CRT_SECURE_NO_WARNINGS

//  RecursiveBinarySearch

#include<stdio.h>

int BSearchRecur(int arr[], int first, int last, int target)
{
	int mid;

	if (first > last)	
		return -1;	//search fail


	mid = (first + last) / 2;


	if (arr[mid] == target)
			return mid;			//search success
	else if (target < arr[mid])
		return BSearchRecur(arr, first, mid - 1, target);
	else
		return BSearchRecur(arr, mid + 1, last, target);

}	

int main(void)
{
	int arr[] = { 1,3,5,7,9 };

	int index;

	//test1
	index = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int)-1, 7);

	if (index == -1)
		printf("Search Fail\n");
	else
		printf("index stored target: %d\n", index);

	//test2
	index = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);

	if (index == -1)
		printf("Search Fail\n");
	else
		printf("index stored target: %d\n", index);


	return 0;
}
