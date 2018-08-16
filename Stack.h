#ifndef STACK_H
#define STACK_H

#include "LL.h"

template <typename T> class Stack {
private:
	// using a LinkedList as the storage for this Stack 
	LinkedList<T> & data;

public:
	// constructor
	Stack (): 
		data {*(new LinkedList<T>())} {} 

	// accessors -----------------------------------------------------

	// returns a copy of the pointer to the local data variable 
	LinkedList<T>& getData() const {
		return data;
	}

	void printStack() const {
		data.printList(); 
	}

	// return first element of stack without removing 
	T peek() const {
		// CODE HERE 
		return data.getHead();
	}

	// mutators ------------------------------------------------------

	// remove the element off the top of the stack and return it. If 
	// the stack is empty, return the empty constructor for type T. 

	T pop() {
		// CODE HERE
		T sol = data.getHead();
		data.removeHead();
		return sol;
	}

	/*  T isEmpty() {               ///////////////////////// Helper function for pop()
			T first;
			if (first == -1) {
				return 1;
			}
			else {
				return 0;
			}
		}

		T pop(){                     /////////////////////// If original function doesn't work
			// CODE HERE
			T first;
			T num;
			T sol;
			if (isEmpty()) {
				return 0;
			}
			sol = num[first];
			--first;
			return sol;
		}
		*/

	// push item thing of type T onto the stack 
	void push(T thing) {
		// CODE HERE 
		data.insert(thing);
	}


};




#endif 
