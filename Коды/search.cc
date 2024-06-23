#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Бинарный поиск. Функция bsearch

//Сигнатура функции
//void* bsearch{
//	const void* key,   //указатель на элемент для поиска
//	const void* ptr,   //указатель на массив для исследования
//	std::size_t count, //количество элементов в массиве
//	std::size_t size,  //размер каждого элемента в массиве в байтах
//	comp			   //функция сравнения
//};

// int cmp(const void*a, const void*b); тип функции сравнения


//bsearch для целочисленных значений
int comparing_int(const void* a, const void* b) { return*(int*)a - *(int*)b; }

void bsearch_int() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int val = 7;
    void* res = bsearch(&val, arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), comparing_int);
    if (res != nullptr) {
        cout << "Index: " << ((int*)res - arr) << "\nFound: " << *(int*)res << endl;
    }
    else {
        cout << "Value not found in the array." << endl;
    }
};

//bsearch для строк
int comparing_str(const void* a, const void* b) { return strcmp(*(const char**)a, *(const char**)b); }

void bsearch_str() {
    const char* names[] = { "anna", "petr", "daniil","elena", "george", "ivan" };
    const char* val = "ivan";
    size_t count = sizeof(names) / sizeof(names[0]);
    size_t elmsz = sizeof(names[0]);
    auto res = bsearch(&val, names, count, elmsz, comparing_str);
    if (res != nullptr) {
        cout << "Index: " << ((const char**)res - names) << "\nFound: " << *(const char**)res << endl;
    }
    else {
        cout << "Value not found in the array." << endl;
    }
};

//Операции бинарного поиска
/*
1. lower_bound - возвращает итератор на первый элемент не меньше заданного
template<class ForwardIt, class T>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value);

template<class ForwardIt, class T, class Compare>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp);

2. upper_bound - возвращает итератор на первый элемент больший заданного
template<class ForwardIt, class T>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value);

template<class ForwardIt, class T, class Compare>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp);

3. binary_search - определяет, есть ли заданный элемент в диапазоне
template<class ForwardIt, class T>
bool binary_search(ForwardIt first, ForwardIt last, const T& value);

template<class ForwardIt, class T, class Compare>
bool binary_search(ForwardIt first, ForwardIt last, const T& value, Compare comp);

4. equal_range - возвращает диапазон элементов, соответствующих данному
template<class ForwardIt, class T>
std::pair<ForwardIt, ForwardIt> equal_range(
    ForwardIt first, //
    ForwardIt last, //диапазон элементов
    const T& value // искомое значение
);

template<class ForwardIt, class T, class Compare>
std::pair<ForwardIt, ForwardIt> equal_range(
    ForwardIt first, //
    ForwardIt last, //диапазон элементов
    const T& value, // искомое значение
    Compare comp // предикат возвращающий истину, если 1-ый элемент  меньше 2-го
);
*/

//equal_range
void equal_range_example(){
    struct Student {
        string name;
        int mark;
        bool operator<(const Student& s) const { return mark < s.mark; }
    };
    vector<Student> vec = { {"petr", 3}, {"ivan", 4}, {"anna", 4}, {"richard", 4}, {"petr", 5} };
    Student val = { "",4 };
    auto res = equal_range(vec.begin(), vec.end(), val);
    for (auto it = res.first; it != res.second; it++) {
        cout << it->name << ":" << it->mark<< " ";
    }
    cout << endl;
}

//Функция бинарного поиска
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

template<typename T>
int EasilyBinarySearch(T* arr, T key, size_t size) {
    int left = 0, right = size, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] > key)
            right = mid;
        else
            left = mid + 1;
    }
    right--;
    if (arr[right] == key)
        return right;
    else
        return - 1;
}

void binarysearch() {
    int array[] = { 9,15,33,41,67,89 };
    int size = sizeof(array) / sizeof(array[0]);
    cout <<"Index of key by BinarySearch: "<<  BinarySearch(array, 67, size) << endl;
    cout << "Index of key by EasilyBinarySearch: " << EasilyBinarySearch(array, 67, size) << endl;

}

int main() {
    bsearch_int();
    bsearch_str();
    equal_range_example();
    binarysearch();
    return 0;
}