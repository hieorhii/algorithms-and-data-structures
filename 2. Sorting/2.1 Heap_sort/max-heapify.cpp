//building a heap from array

#include <iostream>

using namespace std;

//support heap property
int max_heapify(int* arr, int i)
{
	int largest = i;
	int l = i * 2;
	int r = i * 2 + 1;

	if (l < sizeof(arr) && arr[l] >= arr[i])
	{
		largest = l;
	}

	if (r < sizeof(arr) && arr[r] >= arr[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		max_heapify(arr, largest);
	}
	return *arr;
}

//building a heap
int build_max_heap(int *arr)
{
	for (int i = sizeof(arr) / 2; i >= 0; i--)
	{
		max_heapify(arr, i);
	}
	return *arr;
}

int main()
{
	int numbers[10] = {1,5,6,7,36,84,34,78,35,4};
	build_max_heap(numbers);
	for (int i = 0; i < 10; i++)
	{
		cout << numbers[i] << " ";
	}
}