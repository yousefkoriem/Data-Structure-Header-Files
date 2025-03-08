/*#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
	LinkedList<int> lst;

	lst.push_back(5);
	lst.push_back(9);
	lst.push_back(-7);
	lst.push_back(-2);
	lst.push_back(3);
	lst.push_back(-5);
	lst.push_back(1);
	lst.push_back(6);

	LinkedList<int> pos, neg;

	for (LinkedList<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		if (*it > 0) pos.push_back(*it);
		else neg.push_back(*it);
	}

	pos.print();
	neg.print();
}*/