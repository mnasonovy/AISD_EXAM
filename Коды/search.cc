#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�������� �����. ������� bsearch

//��������� �������
//void* bsearch{
//	const void* key,   //��������� �� ������� ��� ������
//	const void* ptr,   //��������� �� ������ ��� ������������
//	std::size_t count, //���������� ��������� � �������
//	std::size_t size,  //������ ������� �������� � ������� � ������
//	comp			   //������� ���������
//};

// int cmp(const void*a, const void*b); ��� ������� ���������


//bsearch ��� ������������� ��������
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

//bsearch ��� �����
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

//�������� ��������� ������
/*
1. lower_bound - ���������� �������� �� ������ ������� �� ������ ���������
template<class ForwardIt, class T>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value);

template<class ForwardIt, class T, class Compare>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp);

2. upper_bound - ���������� �������� �� ������ ������� ������� ���������
template<class ForwardIt, class T>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value);

template<class ForwardIt, class T, class Compare>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp);

3. binary_search - ����������, ���� �� �������� ������� � ���������
template<class ForwardIt, class T>
bool binary_search(ForwardIt first, ForwardIt last, const T& value);

template<class ForwardIt, class T, class Compare>
bool binary_search(ForwardIt first, ForwardIt last, const T& value, Compare comp);

4. equal_range - ���������� �������� ���������, ��������������� �������
template<class ForwardIt, class T>
std::pair<ForwardIt, ForwardIt> equal_range(
    ForwardIt first, //
    ForwardIt last, //�������� ���������
    const T& value // ������� ��������
);

template<class ForwardIt, class T, class Compare>
std::pair<ForwardIt, ForwardIt> equal_range(
    ForwardIt first, //
    ForwardIt last, //�������� ���������
    const T& value, // ������� ��������
    Compare comp // �������� ������������ ������, ���� 1-�� �������  ������ 2-��
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
}

int main() {
    bsearch_int();
    bsearch_str();
    equal_range_example();
    return 0;
}