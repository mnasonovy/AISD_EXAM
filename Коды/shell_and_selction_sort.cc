#include <iostream>
using namespace std;


template<typename T>
void ShellSort(T* arr, size_t size) {
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; ++i) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
}


template<typename T>
void SelectionSort(T* arr, size_t size) {
	for (int i = 0; i < size-1; ++i) {
		int min_index=i;
		for (int j = i+1; j < size; ++j) {
			if (arr[min_index] > arr[j])
				min_index = j;
		}
		swap(arr[i], arr[min_index]);

		cout << i << ". ";
		for (int k = 0; k < size; ++k) {
			cout << arr[k] << " ";
		}
		cout << endl;

	}
}

int main() {
	int array[] = { 7, 6, 9, 4, 1, 2, 8, 0, 3 };
	int size = sizeof(array) / sizeof(array[0]);
	cout << "Sorting by Shell sort:" << endl;
	ShellSort(array, size);
	for (int k = 0; k < size; ++k) {
		cout << array[k] << " ";
	}
	cout << endl;

	int array_1[] = { 7, 6, 9, 4, 1, 2, 8, 0, 3 };
	int size_1 = sizeof(array_1) / sizeof(array_1[0]);
	cout << "Sorting by Selection sort:" << endl << 0 << ". ";
	for (int k = 0; k < size_1; ++k) {
		cout << array_1[k] << " ";
	}
	cout << endl;
	SelectionSort(array_1, size_1);
	return 0;
}