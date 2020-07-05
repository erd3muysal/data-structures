#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dynamic_array.h"

template <class T>
DynamicArray<T>::DynamicArray()
{
    /*
    Constructor
    */
	capacity = initial_capacity;
	arr = new T[capacity];
	size = 0;
}

// Copy Constructor
template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
    /*
    Copy constructor
    */

    if(other.arr == nullptr){
        return;
    }

    arr = new T[other.capacity];
    capacity = other.capacity;
    size = other.size;

    for(unsigned int i=0; i<size; i++)
    {
        arr[i] = other.arr[i];
    }
}

// Instance creation
template <class T>
DynamicArray<T>* DynamicArray<T>::getInstance()
{
    /*
    Creates a singleton pattern instance
    */

	if(instance == 0){ 		// If there is no instance available
		instance = new DynamicArray<T>; // Create new one
	}
	return instance;
}

template <class T>
void DynamicArray<T>::pushBack(const T t)
{
	if(size == capacity){
		capacity *= 2;
		arr = (T *)realloc(arr, sizeof(T)*capacity);
	}
	arr[size] = t;
	size++;
	printElements();
}

template <class T>
void DynamicArray<T>::toVector(vector<int> &vec)
{
	vec.clear();
	for(unsigned int i = 0; i < size; i++){
		vec.push_back(arr[i]);
	}
}

template <class T>
unsigned int DynamicArray<T>::getSize()
{
    /*
    Returns the size of this linked list
    */

    return size;
}

template <class T>
unsigned int DynamicArray<T>::getCapacity()
{
    /*
    Returns the capacity of this linked list
    */

    return capacity;
}

template <class T>
bool DynamicArray<T>::isEmpty()
{
    /*
    Checks whether the link list is empty

    Returns:
    TRUE if yes
    FALSE if no
    */

    return getSize() == 0;
}

template <class T>
T DynamicArray<T>::getElement(int index)
{
    /*
    Displays element at index in the dynamic array, O(n)
    */

    return arr[index];
}

template <class T>
void DynamicArray<T>::setElement(int index, T element)
{
    /*
    Sets the index in the dynamic array with the element, O(n)
    */

    arr[index] = element;
}

template <class T>
void DynamicArray<T>::printElements()
{
    /*
    Displays whole elements in the dynamic array, O(n)
    */

	for(unsigned int i = 0; i < capacity; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class T>
void DynamicArray<T>::clearArray()
{
    /*
    Clears this dynamic array, O(n)
    */

	if (arr != nullptr)
	{
		arr.clear();	// Clearing memory
		arr = nullptr;  // Freeing memory
		size = 0;
	}
}

// Destructor
template <class T>
DynamicArray<T>::~DynamicArray()
{
    /*
    Destructor
    */

    clearArray();
}

template <class T>
DynamicArray<T>* DynamicArray<T>::instance = 0;
