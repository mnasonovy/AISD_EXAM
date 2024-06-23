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
int BinarySearch(T* arr, T key, size_t size) {
    bool flag = false;
    int left = 0;
    int right = size - 1;
    int mid;
    while ((left <= right) && (flag == false)) {
        mid = (left + right) / 2;
        if (arr[mid] == key)
            flag = true;
        if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (flag)
        return mid;
    else
        return -1;
}


int main() {
    int array[] = { 7, 6, 9, 4, 1, 2, 8, 0, 3 };
    int size = sizeof(array) / sizeof(array[0]);
    cout << "Sorting algorithm by simply inclusion:" << endl;
    SimpleInclusionSort(array, size);
    int array_1[] = { 9,15,33,41,67,89};
    int size_1 = sizeof(array_1) / sizeof(array_1[0]);
    cout << BinarySearch(array_1, 67, size_1) << endl;
    
    return 0;
}

