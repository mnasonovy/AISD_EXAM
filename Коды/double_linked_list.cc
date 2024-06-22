#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
struct Node {
	T _value;
	Node<T>* _prev, * _next;
	Node() :_value(0), _prev(nullptr), _next(nullptr) {};
	Node(T value) : _value(value), _prev(nullptr), _next(nullptr) {};
};

template<typename T>
class Double_Linked_List {
private:
	Node<T>* _head;
public:
	Double_Linked_List() :_head(nullptr) {};

	~Double_Linked_List() {
		while (_head) {
			Node<T>* temp = _head;
			_head = _head->_next;
			delete temp;
		}
	}

	void push_front(T value) {
		Node<T>* new_node = new Node<T>(value);
		if (!_head)
			_head = new_node;
		else {
			_head->_prev = new_node;
			new_node->_next = _head;
			_head = new_node;
		}
	}

	void push_back(T value) {
		Node<T>* new_node = new Node<T>(value);
		Node<T>* temp = _head;
		while (temp->_next)
			temp = temp->_next;
		temp->_next = new_node;
		new_node->_prev = temp;
	}

	void insert_by_index(int index, T value) {
		if (index < 0)
			throw out_of_range("Index can't be negative!");
		Node<T>* new_node = new Node<T>(value);
		if (index == 0) {
			_head->_prev = new_node;
			new_node->_next = _head;
			_head = new_node;
		}
		else {
			Node<T>* temp = _head;
			for (int i = 0; i < index - 1; ++i) {
				if (!temp || !temp->_next)
					throw out_of_range("Index out of range!");
				temp = temp->_next;
			}
			new_node->_prev = temp;
			new_node->_next = temp->_next;
			temp->_next->_prev = new_node;
			temp->_next = new_node;
		}

	}
	void pop_front() {
		Node<T>* temp = _head;
		temp->_next->_prev = nullptr;
		_head = temp->_next;
		delete temp;
		temp = NULL;
	}
	void pop_back() {
		Node<T>* temp = _head;
		while (temp->_next) {
			temp = temp->_next;
		}
		temp->_prev->_next = nullptr;
		delete temp;
		temp = NULL;
	}

	void remove_by_index(int index) {
		if (index < 0)
			throw out_of_range("Index can't be negative!");
		Node<T>* temp = _head;
		for (int i = 0; i < index; ++i) {
			if (!temp || !temp->_next)
				throw out_of_range("Index out of range!");
			temp = temp->_next;
		}
		if (!temp || !temp->_next)
			throw out_of_range("Index out of range!");
		temp->_prev->_next = temp->_next;
		temp->_next->_prev = temp->_prev;
		delete temp;
		temp = NULL;
	}
	int find_by_value(T value) {
		Node<T>* temp = _head;
		int index = 0;
		while (temp && temp->_value!=value) {
			index++;
			temp = temp->_next;
		}
		if (!temp)
			return -1;
		else
			return index;
	}

	void print() {
		Node<T>* temp = _head;
		while (temp) {
			cout << temp->_value<<" ";
			temp = temp->_next;
		}
	}
};

int main() {
	Double_Linked_List<int> list;
	list.push_front(50);
	list.push_front(17);
	list.push_back(33);
	list.push_back(15);
	list.insert_by_index(2, 24);
	list.insert_by_index(4, 99);
	list.pop_front();
	list.pop_back();
	list.remove_by_index(2);
	list.print();
	cout << "\nIndex of value: " << list.find_by_value(99);
	return 0;
}