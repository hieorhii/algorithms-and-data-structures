//heapsort

#include <iostream>

using namespace std;

//support heap property O(lg n)
int max_heapify(int* arr, int i, int size)
{
	int largest = i;
	int l = i * 2;
	int r = i * 2 + 1;

	if (l < size && arr[l] >= arr[i])
	{
		largest = l;
	}

	if (r < size && arr[r] >= arr[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		max_heapify(arr, largest, size);
	}
	return *arr;
}

//building a heap O(n)
int build_max_heap(int* arr, int size)
{
	for (int i = size / 2; i >= 0; i--)
	{
		max_heapify(arr, i, size);
	}
	return *arr;
}

//heapsort O(n lg n)
int heapsort(int* arr, int size)
{
	build_max_heap(arr, size);

	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);
		size = size - 1;
		max_heapify(arr, 0, size);
	}
	return *arr;
}

int main()
{
	int numbers[10] = { 1,5,6,7,36,84,34,78,35,4 };
	int s = size(numbers);

	heapsort(numbers, s);

	for (int i = 0; i < 10; i++)
	{
		cout << numbers[i] << " ";
	}
}