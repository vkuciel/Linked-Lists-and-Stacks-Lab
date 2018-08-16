#ifndef DEQUE_H
#define DEQUE_H

#include "LL.h"


template <typename T> class Deque {
private:
	// using a LinkedList as the storage for this Deque 
	LinkedList<T>& data;


public: 
	Deque(): 
		data {*(new LinkedList<T>())} {} 


	// accessors -----------------------------------------------------

	LinkedList<T>& getData() const {
		return data;
	}

	// for your testing purposes - should print out each element of 
	// the deque without destroying the original deque 
	void printDeque() const {
		data.printList();
	}

	// returns the back element 
	T getBack() const {

		return data.getTail();
	}
	// returns the front element 
	T getFront() const {

		return data.getHead();
	}

	// inserts element thing at back of Deque 
	void pushBack(T thing){

		data.add(thing);
	}

	// inserts element thing at front of Deque 
	void pushFront(T thing){

		data.insert(thing);
	}

	// removes element at back of Deque and returns it
	T popBack(){

		T sol = data.getTail();
		data.removeTail();
		return sol;
	}

	// removes element at front of Deque and returns it
	T popFront(){

		T sol = data.getHead();
		data.removeHead();
		return sol;
	}

};



#endif 
