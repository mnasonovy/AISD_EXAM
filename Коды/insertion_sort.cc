#include <iostream>
using namespace std;

template<typename T>
void SimpleInclusionSort(T* arr, size_t size) {
    for (int i = 1; i < size; ++i) {
        T current_value = arr[i]; 
        int current_index = i;
        while ((current_index > 0) && (arr[current_index - 1] > current_value)) {
            arr[current_index] = arr[current_index - 1];
            current_index--;
        }
        arr[current_index] = current_value;

        //Вывод для наглядной работы алгоритма
        cout << i << ". ";
        for (int k = 0; k < size; ++k) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}


template<typename T>
int BinarySearchForInsertion(T* arr, T key, size_t size) {
    int left = 0, right = size, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] > key)
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}

template<typename T>
void BinaryInclusionSort(T* arr, size_t size) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int insert_position = BinarySearchForInsertion(arr, key, i);
        for (int j = i; j > insert_position; --j)
            arr[j] = arr[j - 1];
        arr[insert_position] = key;

        //Вывод для наглядной работы алгоритма
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
    cout << "Sorting algorithm by simply inclusion:" << endl<<0<<". ";
    for (int k = 0; k < size; ++k) {
        cout << array[k] << " ";
    }
    cout << endl;
    SimpleInclusionSort(array, size);


    int array_1[] = { 7, 6, 9, 4, 1, 2, 8, 0, 3 };
    int size_1 = sizeof(array_1) / sizeof(array_1[0]);
    cout << "Sorting algorithm by binary inclusion:" << endl << 0 << ". ";
    for (int k = 0; k < size; ++k) {
        cout << array_1[k] << " ";
    }
    cout << endl;
    BinaryInclusionSort(array_1, size);

    return 0;
}

