#include <iostream>
#include <cstdio>

using namespace std;

//take the middle element as pivot
int partition1(int array[], int left, int right)
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

void quicksort1(int array[], int left, int right)
{
	int index = partition1(array, left, right);
	if(left < index-1)
		quicksort1(array, left, index-1);
	if(index < right)
		quicksort1(array, index, right);
}


///version 2. take the last element as pivot. taken from <<Introduction to Algorithms>>.
//take the middle element as pivot
int partition2(int array[], int left, int right)
{
	int pivot = array[right];
	int i = left-1;
	for(int j=left; j<=right; j++)
	{
		if(array[j] <= pivot)
		{
			i++;
			swap(array[i], array[j]);
		}
	}
	
	return i;
}

void quicksort2(int array[], int left, int right)
{
	if(left < right)
	{
		int index = partition2(array, left, right);
		quicksort2(array, left, index-1);
		quicksort2(array, index+1, right);
	}
}
