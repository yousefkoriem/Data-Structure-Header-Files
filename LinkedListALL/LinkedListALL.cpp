#include <iostream>
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "UnorderedLinkedList.h"
#include "Darray.h"
using namespace std;

int main() {
	OrderedLinkedList<int> lst;
	lst.insert(5);
	lst.insert(6);
	lst.insert(7);
	lst.insert(7);
	lst.insert(9);
	lst.insert(12);
	lst.insert(15);
	lst.insert(22);
	lst.insert(22);
	lst.insert(22);
	
	lst.print();
	int prev = -1;
	for (OrderedLinkedList<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (prev == *it) {
			lst.deleteNode(prev);
		}
		prev = *it;
	}

	lst.print();
}