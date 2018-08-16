
// stdlib includes
#include <iostream>
#include <cassert>
// local includes
#include "LL.h"
#include "Stack.h"
#include "Deque.h"


template <typename T>
void testLinkedList() {
	LinkedList<T> testing {};
	// testing add
	testing.add(T{4});
	testing.add(T{7});
	testing.add(T{1});
	testing.add(T{9});
	testing.add(T{2});

	assert (testing.getSize() == 5);
	assert (testing.getHead() == 4);
	assert (testing.getTail() == 2);

	// testing member
	assert (testing.member(7) == 1);
	//assert (testing.member(2) == 4);

	// testing empty
	testing.printList();
	testing.empty();
	assert (testing.getSize() == 0);

	// testing insert
	testing.insert(T{4});
	testing.insert(T{7});
	testing.insert(T{1});
	testing.insert(T{9});
	assert (testing.getTail() == 4);

	// testing findKth
	assert (testing.findKth(2) &&
		*testing.findKth(2) == 7);
	assert (!testing.findKth(4)); // out of bounds


	testing.insertAtK(3,1); // insert 3 at position 1
	testing.insertAtK(8,4); // insert 8 at position 4
	assert (*testing.findKth(1) == 3);
	assert (testing.getSize() == 6);

	// testing remove head/remove tail
	testing.removeHead();
	assert (testing.getHead() == 3);
	assert (testing.getSize() == 5);

	// testing removeAtK
	testing.removeAtK(1);
	assert (testing.getSize() == 4);
	assert (testing.getHead() == 3);

	testing.printList();
}

template <typename T>
void testLinkedList2() {
	LinkedList<T> testing {};
	// testing add
	testing.add(T{2});
	testing.add(T{4});
	testing.add(T{1});

	assert (testing.getSize() == 3);
	assert (testing.getHead() == 2);
	assert (testing.getTail() == 1);

	// testing member
	assert (testing.member(4) == 1);

	// testing empty
	testing.printList();
	testing.empty();
	assert (testing.getSize() == 0);

	// testing insert
	testing.insert(T{2});
	testing.insert(T{4});
	assert (testing.getTail() == 2);

	// testing findKth
	assert (testing.findKth(1) &&
		*testing.findKth(1) == 4);
	assert (!testing.findKth(2)); // out of bounds


	testing.insertAtK(3,1); // insert 3 at position 1
	testing.insertAtK(8,2); // insert 8 at position 2
	assert (*testing.findKth(1) == 3);
	assert (testing.getSize() == 4);

	// testing remove head/remove tail
	testing.removeHead();
	assert (testing.getHead() == 3);
	assert (testing.getSize() == 3);

	// testing removeAtK
	testing.removeAtK(1);
	assert (testing.getSize() == 2);
	assert (testing.getHead() == 3);

	testing.printList();
}

template <typename T>
void testLinkedList3() {
	LinkedList<T> testing {};
	// testing add
	testing.add(T{3});
	testing.add(T{50});
	testing.add(T{10});
	testing.add(T{99});

	assert (testing.getSize() == 4);
	assert (testing.getHead() == 3);
	assert (testing.getTail() == 99);

	// testing member
	assert (testing.member(50) == 1);

	// testing empty
	testing.printList();
	testing.empty();
	assert (testing.getSize() == 0);

	// testing insert
	testing.insert(T{3});
	testing.insert(T{50});
	testing.insert(T{10});
	assert (testing.getTail() == 3);

	// testing findKth
	assert (testing.findKth(2) &&
		*testing.findKth(2) == 50);
	assert (!testing.findKth(3));


	testing.insertAtK(6,1); // insert 6 at position 1
	testing.insertAtK(8,4); // insert 8 at position 3
	assert (*testing.findKth(1) == 50);
	assert (testing.getSize() == 5);

	// testing remove head/remove tail
	testing.removeHead();
	assert (testing.getHead() == 6);
	assert (testing.getSize() == 4);

	// testing removeAtK
	testing.removeAtK(1);
	assert (testing.getSize() == 3);
	assert (testing.getHead() == 6);

	testing.printList();
}

template <typename T>
void testStack() {
	Stack<T> testing {};

	assert (testing.getData().getSize() == 0);
	testing.push(5);
	assert (testing.getData().getSize() == 1);
	assert (testing.peek() == 5);
	assert (testing.pop() == 5);
	assert (testing.getData().getSize() == 0);
	assert (!testing.peek());	// should be 0 (default)

	testing.push(1);
	testing.push(6);
	testing.push(3);
	testing.push(9);
	testing.push(7);
	assert (testing.getData().getSize() == 5);

}

template <typename T>
void testStack2() {
	Stack<T> testing {};

	assert (testing.getData().getSize() == 0);
	testing.push(7);
	assert (testing.getData().getSize() == 1);
	assert (testing.peek() == 7);
	assert (testing.pop() == 7);
	assert (testing.getData().getSize() == 0);
	assert (!testing.peek());

	testing.push(1);
	testing.push(6);
	testing.push(3);
	testing.push(9);
	testing.push(8);
	testing.push(10);
	testing.push(11);
	assert (testing.getData().getSize() == 7);
}

template <typename T>
void testStack3() {
	Stack<T> testing {};

	assert (testing.getData().getSize() == 0);
	testing.push(3);
	assert (testing.getData().getSize() == 1);
	assert (testing.peek() == 3);
	assert (testing.pop() == 3);
	assert (testing.getData().getSize() == 0);
	assert (!testing.peek());

	testing.push(1);
	testing.push(6);
	testing.push(2);
	assert (testing.getData().getSize() == 3);
}


template <typename T>
void testDeque() {
	// use this to test Deque
	Deque<T> testing {};

	assert (testing.getData().getSize() == 0);
	testing.pushBack(3);
	testing.pushBack(8);
	testing.pushBack(1);
	testing.pushBack(9);
	assert (testing.getData().getSize() == 4);
	assert (testing.getBack() == 9);
	assert (testing.getFront() == 3);

	testing.popBack();
	assert (testing.getBack() == 1);
	testing.popFront();
	assert (testing.getFront() == 8);
	assert (testing.getData().getSize() == 2);


	testing.printDeque();


}

template <typename T>
void testDeque2() {
	// use this to test Deque
	Deque<T> testing {};

	assert (testing.getData().getSize() == 0);
	testing.pushBack(4);
	testing.pushBack(7);
	testing.pushBack(2);
	testing.pushBack(8);
	assert (testing.getData().getSize() == 4);
	assert (testing.getBack() == 8);
	assert (testing.getFront() == 4);

	testing.popBack();
	assert (testing.getBack() == 2);
	testing.popFront();
	assert (testing.getFront() == 7);
	assert (testing.getData().getSize() == 2);


	testing.printDeque();


}

template <typename T>
void testDeque3() {
	// use this to test Deque
	Deque<T> testing {};

	assert (testing.getData().getSize() == 0);
	testing.pushBack(500);
	testing.pushBack(790);
	testing.pushBack(243);
	testing.pushBack(1010);
	assert (testing.getData().getSize() == 4);
	assert (testing.getBack() == 1010);
	assert (testing.getFront() == 500);

	testing.popBack();
	assert (testing.getBack() == 243);
	testing.popFront();
	assert (testing.getFront() == 790);
	assert (testing.getData().getSize() == 2);


	testing.printDeque();


}


int main(int argc, char* argv[]){
	// Each LinkedList test below works separately.

	//testLinkedList<float>();
	//testLinkedList2<float>();
	//testLinkedList3<float>();
	testStack<float>();
	testStack2<float>();
	testStack3<float>();
	testDeque<float>();
	testDeque2<float>();
	testDeque3<float>();

	std::cout << "finished all tests" << std::endl;
}
