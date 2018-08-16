#ifndef LL_H
#define LL_H

#include <iostream>


// A template class takes in a type in the <>. Look at how we declare a vector
// with: vector<int> thing, there the <int> is the template type.
template <typename T> class LinkedList {
private:
	// private struct for the LL
	struct Node {
		T data;
		Node* next;
		Node* prev;

		Node(): // <- this is called an initializer list, the most common
				// way to write constructors since C++11
			data { T{} },
			next {nullptr},
			prev {nullptr} {};
		explicit Node(const T & _dataMember): // <- the explicit means we
				// can't pass in any extra values to this function or do
				// implicit type casting – important only because this is
				// allowed in C
			data {_dataMember},
			next {nullptr},
			prev {nullptr} {};
		explicit Node(const T && _dataMember):
			data {_dataMember},
			next {nullptr},
			prev {nullptr} {};
	};

	Node* head;	// head pointer: first Node in the LinkedList
	Node* tail; // tail pointer: last Node in the LinkedList
	int size;	// int to keep the size of the list; should be modified
				// as the data structure changes size


	// checks if a given k is within the size of indices in LinkedList
	// returns true if 0 <= k < size,
	// false otherwise
	bool kWithinBounds(int k) const {
		if (k >= 0 && k < size){
			return true;
		}
		return false;
	}

	// will return the kth Node in the LinkedList. This is private
	// because we don't want to support this function for outside
	// classes, this is just for internal usage
	Node* getKthNode(int k) const {
		// CODE HERE
		if (k < 0 || k >= size) {
			return nullptr;
		}
		Node *tmp = head;
		int i = 0;
		for (i=0; i<k; i++) {
			tmp = tmp->next;
		}
		return tmp;

	}


public:
	// constructor/destructor
	LinkedList(): 	// default values for LinkedList
		head {nullptr},
		tail {nullptr},
		size {0} {};

	~LinkedList(){	// calls a defined function empty() to clean up all
		// memory in the LinkedList (delete all allocated memory)
		empty();
	}
	// copy constructor -- note that this does a /deep/ copy
	LinkedList (const LinkedList<T> & other):
		head {nullptr}, tail {nullptr}, size {0} {
		Node* temp = other.head;
		while (temp != nullptr){
			this->add(temp->data);
			temp = temp->next;
		}
	}
	// copy assignment operator
	LinkedList& operator= (const LinkedList & other){
		LinkedList copy = other;
		std::swap(*this,copy);
		return *this;
	}

	// move constructor
	LinkedList (LinkedList<T> && other):
		head {other.head}, tail {other.tail}, size {other.size} {
		other.head = other.tail = nullptr;
		other.size = 0;
	}

	// move assignment operator
	LinkedList& operator= (LinkedList<T> && other){
		std::swap(head, other.head);
		std::swap(tail, other.tail);
		std::swap(size, other.size);
		return *this;
	}


	// accessors ----------------------------------------------

	// returns the data stored in the tail Node
	T getHead() const {
		if (head != nullptr){
			return head->data;
		} else {
			return T {};
		}
	}
	// returns the data stored in the tail Node
	T getTail() const {
		if (tail != nullptr){
			return tail->data;
		} else {
			return T {};
		}
	}
	// returns the number of nodes in the list.
	int getSize() const {
		return size;
	}

	// will return the index of the item in the list, if it
	// is found. If not, return -1.
	int member(T dataMember) const {

		int x=0;
		Node *tmp = head;
		while (tmp != tail) {
			if (tmp->data == dataMember) {
				return x;
			}
			x++; // increment
			tmp = tmp->next; // Point to next spot
		}
		return -1;
	}
	// returns the data at index j
	T* findKth(int j) const {

		Node *tmp = getKthNode(j);
		if (tmp != nullptr) {
			return &tmp->data;
		}
		return nullptr;
	}

	void printList() const {
		Node* tmp = head;
		std::cout << "[";
		while (tmp != nullptr){
			if (tmp->next != nullptr){
				std::cout << tmp->data << ", ";
			} else {
				std::cout << tmp->data;
			}
			tmp = tmp->next;
		}
		std::cout << "]" << std::endl;
	}
	void printListBackwards() const {
		Node* tmp = tail;
		std::cout << "[";
		while (tmp != nullptr){
			if (tmp->prev != nullptr){
				std::cout << tmp->data << ", ";
			} else {
				std::cout << tmp->data;
			}
			tmp = tmp->prev;
		}
		std::cout << "]" << std::endl;
	}




	// mutators -------------------------------------------------

	// inserts at the first position, replacing the old head pointer
	void insert(const T dataMember) {

		Node* tmp = new Node(dataMember);
		if (head == nullptr) {
			head = tmp;
			tail = tmp;
			size = 1;
			return;
		}
		else {
			tmp->next = head;
			head->prev = tmp;
			head = tmp;
			size++;
			return;
		}
	}

	// takes a T var called dataMember and makes it the kth
	// value in the list, its next pointing to the node
	// previously at the kth position. If k is out of range, don't
	// insert anything.
	// Note you can never insert at a position outside the
	// size of the list, so no inserting at the end with
	// this function.
	void insertAtK(T dataMember, int k){

		Node *tNode = getKthNode(k);
		if (tNode != nullptr) {
			if (tNode == head) {
				insert(dataMember);
				return;
			}
			else if (tNode == tail) {
				Node *tmp = new Node(dataMember);
				tail->next = tmp;
				tmp->prev = tail;
				tail = tmp;
				size++;
				return;
			}
			else {
				Node *tmp = new Node(dataMember);
				tmp->prev = tNode->prev;
				tNode->prev->next = tmp;
				tmp->next = tNode;
				tNode->prev = tmp;
				size++;
				return;
			}
		}

	}

	// insert at the end of the list
	void add(T dataMember){
		Node* tmp = new Node(dataMember);
		if (!head){
			head = tmp;
			tail = tmp;
		} else {
			tail->next = tmp;
			tmp->prev = tail;
			tmp->next = nullptr;
			tail = tmp;
		}
		size++;
	}


	// deletes memory at head, sets head to be the prev node, or
	// nullptr if only one node in list.
	void removeHead(){
		if (head != nullptr){
			if (tail == head){ // if only one node
				delete head;
				head = tail = nullptr;
			} else {
				Node* temp = head;
				head = head->next;
				head->prev = nullptr;
				delete temp;
			}
			size--;
		}
	}

	// deletes memory at tail, sets tail to be the prev node, or
	// nullptr if only one node in list.
	void removeTail(){

		if (head == nullptr) {
			return;
		}
		if (head == tail) {
			delete head;
			head = tail = nullptr;
			size = 0;
		}
		else {
			Node *tmp = tail;
			tail = tmp->prev;
			tail->next = nullptr;
			delete tmp;
			size--;
		}
	}

	// removes the kth item in the list
	void removeAtK(int k){

		if (head == nullptr) {
			return;

		}
		Node *tmp = getKthNode(k);
		if (tmp != nullptr) {
			if (tmp == head) {
				removeHead();
			}
			else if (tmp == tail) {
				removeTail();
			}
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				size--;
			}
		}
	}

	// free all memory in the list with delete and reset
	// head, tail and size.
	void empty(){

		if (head != nullptr) {
			Node *tmp = head;
			while (tmp != nullptr) {
				tmp = tmp->next;
				if (tmp != nullptr) {
					delete tmp->prev;
				}
				if (tail != nullptr) {
					delete tail;
				}
				head = tail = nullptr;
				size = 0;
			}
		}
	}








};








#endif
