#include <iostream>
using namespace std;

template<typename T>
void BubbleSort(T* arr, size_t size) {
	bool flag;
	for (int i = 0; i < size-1; ++i) {
		flag = false;
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]){
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

template<typename T>
void CocktailSort(T* arr, size_t size) {
	bool flag = true;
	int start = 0;
	int end = size - 1;
	while (flag) {
		flag = false;
		for (int i = start; i < end; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				flag = true;
			}
		}
		if (!flag)
			break;
		flag = false;
		--end;
		for (int j = end - 1; j >= start; --j) {
			if (arr[j + 1] < arr[j]) {
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		start++;
	}
}


template<typename T>
int Partition(T* arr, int low, int high) {
	T pivot = arr[low];
	int left = low + 1;
	int right = high;
	while (true) {
		while (left <= right && arr[left] <= pivot)
			left++;
		while (right >= left && arr[right] >= pivot)
			right--;
		if (left > right)
			break;
		else
			swap(arr[left], arr[right]);
	}
	swap(arr[low], arr[right]);
	return right;
}

template<typename T>
void QuickSort(T* arr, int low, int high) {
	if (low < high) {
		int pivotIndex = Partition(arr, low, high);
		QuickSort(arr, low, pivotIndex - 1);
		QuickSort(arr, pivotIndex + 1, high);
	}
}

int main() {
	int array[] = { 7, 6, 9, 4, 1, 2, 8, 0, 3 };
	int size = sizeof(array) / sizeof(array[0]);
	cout << "Sorting by Bubble sort:" << endl;
	BubbleSort(array, size);
	for (int k = 0; k < size; ++k) {
		cout << array[k] << " ";
	}
	cout << endl;

	int array_1[] = { 7, 6, 9, 4, 1, 2, 8, 0, 3 };
	int size_1 = sizeof(array_1) / sizeof(array_1[0]);
	cout << "Sorting by Cocktail sort:" << endl;
	CocktailSort(array_1, size_1);
	for (int k = 0; k < size_1; ++k) {
		cout << array_1[k] << " ";
	}
	cout << endl;

	int array_2[] = { 7, 6, 9, 4, 1, 2, 8, 0, 3 };
	int size_2 = sizeof(array_2) / sizeof(array_2[0]);
	cout << "Sorting by Quick sort:" << endl;
	QuickSort(array_2, 0, size_2 - 1);
	for (int k = 0; k < size_2; ++k) {
		cout << array_2[k] << " ";
	}
	cout << endl;
}