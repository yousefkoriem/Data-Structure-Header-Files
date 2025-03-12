#include <iostream>
#include "LinkedList.h"
#include "OrderedLinkedList.h"
using namespace std;

int main() {
	LinkedList<int> lst, pos, neg;

	lst.push_back(5);
	lst.push_back(9);
	lst.push_back(-7);
	lst.push_back(-2);
	lst.push_back(3);
	lst.push_back(-5);
	lst.push_back(1);
	lst.push_back(6);
	cout << "Origional List: " << lst << '\n';

	lst.sepSplit(pos, neg);

	cout << "Positive Numbers: " << pos << '\n';

	cout << "negative Numbers: " << neg << '\n';

	cout << "\n\n";

	OrderedLinkedList<int> olst;
	olst.insert(5);
	olst.insert(6);
	olst.insert(7);
	olst.insert(7);
	olst.insert(9);
	olst.insert(12);
	olst.insert(15);
	olst.insert(22);
	olst.insert(22);
	olst.insert(22);

	olst.print();
	olst.remDuplicate();

	olst.print();
}