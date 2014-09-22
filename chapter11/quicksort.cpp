#include <iostream>
#include <cstdio>

using namespace std;

int partition(int array[], int left, int right)
{
	int pivot = array[(left+right)/2];
	while(left <= right)
	{
		while(array[left] < pivot) left++;
		while(array[right] > pivot) right--;
		
		//swap elements, and move left and right indices
		if(left <= right)
		{
			swap(array[left], array[right]);
			left++;
			right--;
		}
	}
	return left;
}

void quicksort(int array[], int left, int right)
{
	int index = partition(array, left, right);
	
}
