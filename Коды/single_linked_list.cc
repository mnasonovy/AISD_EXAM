#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
struct Node {
	T _value;
	Node* _next;
	Node(T val) :_value(val), _next(nullptr) {};
};

template<typename T>
class Single_Linked_List {
private:
	Node<T>* _head;
public:
	Single_Linked_List() :_head(nullptr) {};

	~Single_Linked_List() {
		while (_head) {
			Node<T>* temp = _head;
			_head = _head->_next;
			delete temp;
		}
	}

	void push_front(T value) {
		Node<T>* new_node = new Node<T>(value);
		new_node->_next = _head;
		_head = new_node;
	}

	void push_back(T value) {
		Node<T>* new_node = new  Node<T>(value);
		if (!_head)
			_head = new_node;
		else {
			Node<T>* temp = _head;
			while (temp->_next) {
				temp = temp->_next;
			}
			temp->_next = new_node;
		}
	}

	void insert(int index, T value) {
		if (index<0) {
			throw std::out_of_range("Index out of range!");
		}

		if (!index) {
			Node<T>* new_node = new Node<T>(value);
			new_node->_next = _head;
			_head = new_node;
		}
		else{
			Node<T>* temp = _head;
			for (int i = 0; i < index - 1; ++i) {
				if (!temp || !temp->_next) {
					throw std::out_of_range("Index out of range!");
				}
				temp = temp->_next;
			}

			Node<T>* new_node = new Node<T>(value);
			new_node->_next = temp->_next;
			temp->_next = new_node;
		}
	}

	void remove_by_index(int index) {
		if (!index) {
			Node<T>* current = _head;
			_head = current->_next;
			delete current;
			current = NULL;
		}
		else {
			Node<T>* temp = _head;
			for (int i = 0; i < index - 1 ; ++i) {
				if (!temp || !temp->_next) {
					throw std::out_of_range("Index out of range!");
				}
				temp = temp->_next;
			}
			if (!temp || !temp->_next) {
				throw std::out_of_range("Index out of range!");
			}
			Node<T>* node_to_delete = temp->_next;
			temp->_next = node_to_delete->_next;
			delete node_to_delete;
		}
	}

	int find_by_value(T value) {
		Node<T>* current = _head;
		int index = 0;
		while (current && current->_value != value) {
			index++;
			current = current->_next;
		}
		if (!current) {
			return -1; 
		}
		return index;
	}

	void print() {
		if (_head==nullptr)
			cout << "List is empty!" << endl;
		else {
			Node<T>* temp = _head;
			while (temp) {
				cout << temp->_value<<" ";
				temp = temp->_next;
			}
		}
	}
};

int main() {
	Single_Linked_List<int> list;
	list.push_front(5);
	list.push_back(9);
	list.insert(1, 11);
	list.push_back(12);
	list.remove_by_index(2);
	list.print();
	cout<< "\nIndex of value:"<< list.find_by_value(11);
	return 0;
}