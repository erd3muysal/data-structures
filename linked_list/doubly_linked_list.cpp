#include "DoublyLinkedList.h"

using namespace std;

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    /*
    Constructor
    */

    cout << "////////////////////////////////////////////////////////////" << endl;
	cout << "//////      Doubly linked list has been created !      /////" << endl;
    cout << "////////////////////////////////////////////////////////////" << endl;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other)
{
    /*
    Copy constructor
    */
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    /*
    Destructor
    */

    clear();
    cout << "Doubly Linked List has been deleted" << endl;
}

template <class T>
DoublyLinkedList<T>* DoublyLinkedList<T>::getInstance()
{
    /*
    Creates a singleton pattern instance
    */

	if(instance == 0) {  // If there is no instance available
		instance = new DoublyLinkedList<T>;  // Create new one
	}
	return instance;
}

template <class T>
void DoublyLinkedList<T>::clear()
{
    /*
    Clears this linked list, O(n)
    */

    Node<T>* trav = head;
    while(trav != nullptr) {
        Node<T>* next = trav->next;
        trav->prev = trav->next = nullptr;
        trav->data = 0;
        trav = next;
    }
    head = tail = trav = nullptr;
    size = 0;
}

template <class T>
int DoublyLinkedList<T>::getSize()
{
    /*
    Returns the size of this linked list
    */

    return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    /*
    Checks whether the link list is empty

    Returns:
    TRUE if yes
    FALSE if no
    */

    return getSize() == false;
}

template <class T>
void DoublyLinkedList<T>::addNode(T element)
{
    /*
    Adds an element to the tail of the linked list, O(1)

    Argument:
    element -- element to be added
    */

    addLastNode(element);
}

template <class T>
void DoublyLinkedList<T>::addFirstNode(T element)
{
    /*
    Adds an element to the head of the linked list, O(1)

    Argument:
    element -- element to be added
    */

    if(isEmpty()) {
        head = tail = new Node<T>(element, nullptr, nullptr);
    }
    else {
        head->prev = new Node<T>(element, nullptr, head);
        head = head->prev;
    }
    size++;
    printElements();
}

template <class T>
void DoublyLinkedList<T>::addLastNode(T element)
{
    /*
    Adds an element to the tail of the linked list, O(1)

    Argument:
    element -- element to be added
    */

    if(isEmpty()) {
        head = tail = new Node<T>(element, nullptr, nullptr);
    }
    else {
        tail->next = new Node<T>(element, tail, nullptr);
        tail = tail->next;
    }
    size++;
    printElements();
}

template <class T>
void DoublyLinkedList<T>::printElements()
{
    /*
    Displays whole elements in the linked list, O(n)
    */

	if (isEmpty() == true) // Can't display data from an empty list
		return;

    Node<T>* temp;
    temp = head;
    cout << "The doubly linked list is: ";

    while (temp != nullptr)  // Take a loop until reach last pointer which is a NULL
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <class T>
T DoublyLinkedList<T>::peekFirstNode()
{
    /*
    Displays the element in the first node, O(n)
    */

    if(isEmpty() == true)  // Can't display data from an empty list
        return 0;
    else
        return head->data;
}

template <class T>
T DoublyLinkedList<T>::peekLastNode()
{
    /*
    Displays the element in the last node, O(n)
    */

    if(isEmpty() == true)  // Can't display data from an empty list
        return 0;
    else
        return tail->data;
}

template <class T>
T DoublyLinkedList<T>::removeFirstNode()
{
    /*
    Removes the element in the first node, O(n)
    */

    if(isEmpty())  // Can't remove data from an empty list
        return 0;

    T data = head->data;  // Extract the data at the head and move
    head = head->next;    // the head pointer forwards one node
    --size;

    if(isEmpty())  // If the list is empty set the tail to null as well
        tail = nullptr;
    else  // Do a memory clean of the previous node
        head->prev = nullptr;

    return data;  // Return the data that was at the first node we just removed
}

template <class T>
T DoublyLinkedList<T>::removeLastNode()
{
    /*
    Removes the element in the last node, O(n)
    */

    if(isEmpty())  // Can't remove data from an empty list
        return 0;

    T data = tail->data;  // Extract the data at the tail and move
    tail = tail->prev;    // the tail pointer forwards one node
    --size;

    if(isEmpty())  // If the list is empty set the tail to null as well
        head = nullptr;
    else  // Do a memory clean of the previous node
        tail->next = nullptr;

    return data;  // Return the data that was at the first node we just removed
}

template <class T>
DoublyLinkedList<T>* DoublyLinkedList<T>::instance = 0;  // Initialize instance as zero
