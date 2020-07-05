#pragma once

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

template <class T>
class Node
{
    public:
        Node(T data, Node<T>* prev, Node<T>* next);
        Node(const Node<T>& other);
        ~Node();
        string toString();

        T data;
        Node<T>* prev = nullptr;
        Node<T>* next = nullptr;

    private:
        //T data;
        //Node<T>* prev = nullptr;
        //Node<T>* next = nullptr;
        //friend class DoublyLinkedList;

};

