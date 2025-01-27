//priority queue

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

//support heap property O(log n)
void max_heapify(vector<int>& arr, int i)
{
	int largest = i;
	int l = i * 2;
	int r = i * 2 + 1;

	if (l < arr.size() && arr[l] >= arr[i])
	{
		largest = l;
	}

	if (r < arr.size() && arr[r] >= arr[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		max_heapify(arr, largest);
	}
}

//building a heap O(n)
void build_max_heap(vector<int>& arr)
{
	for (int i = arr.size() / 2; i >= 0; i--)
	{
		max_heapify(arr, i);
	}
}

//max element O(1)
int heap_maximum(vector<int>& arr)
{
	return arr[0];
}

//return and delete max O(log n)
int heap_extract_max(vector<int>& arr)
{
	if (arr.size() < 1)
	{
		cout << "Queue is empty" << endl;
		return -1;
	}

	int max = arr[0];
	arr[0] = arr[arr.size() - 1];
	arr.pop_back();

	max_heapify(arr, 0);

	return max;
}

//change arr[i] value to key O(log n)
void heap_increase_key(vector<int>& arr, int i, int key)
{
	if (key < arr[i])
	{
		cout << "Wrong key" << endl;
	}
	else {
		arr[i] = key;

		while (i > 0 && arr[i / 2] < arr[i])
		{
			swap(arr[i / 2], arr[i]);
			i = i / 2;
		}
	}
}

//insert new key O(log n)
void max_heap_insert(vector<int>& arr, int key)
{
	arr.push_back(std::numeric_limits<int>::min());

	heap_increase_key(arr, arr.size() - 1, key);
}

int main()
{
	vector<int> numbers = { 1,5,6,7,36,84,34,78,35,4 };

	build_max_heap(numbers);

	int max = heap_extract_max(numbers);

	cout << max << endl;

	heap_increase_key(numbers, 4, 12);

	max_heap_insert(numbers, 22);

	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << " ";
	}
}