#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "DoublyLinkedList.h"
#include "src/DoublyLinkedList.cpp"
#include "Node.h"
#include "src/Node.cpp"

using namespace std;

const int NUMBER_OF_ELEMENTS = 10;
const int MAX_ELEMENT = 50;
const int QUERY_ELEMENT = 20;

int main()
{
    srand(time(NULL));
    DoublyLinkedList<int> *list = DoublyLinkedList<int>::getInstance();  // Create instance (singleton pattern)

	for(int i = 0; i < NUMBER_OF_ELEMENTS; i++){
		int randInt = static_cast<int>(rand() % MAX_ELEMENT + 1);
		list->addNode(randInt);
		cout << "Size of the doubly linked list is: " << list->getSize() << endl;
		cout << "------------------------------------------------------------" << endl;
	}

    list->printElements();
	cout << endl;
	cout << "First node of the linked list is: " << list->peekFirstNode() << endl;
	cout << "Last node of the linked list is: " << list->peekLastNode() << endl;

    return 0;
}
