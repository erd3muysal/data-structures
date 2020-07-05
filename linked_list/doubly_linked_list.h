#pragma once

#include <iostream>
#include "Node.h"

template <class T>
class DoublyLinkedList
{
    public:
        static DoublyLinkedList* getInstance();
        void clear();
        int getSize();
        bool isEmpty();
        void addNode(T element); // Last as default
        void addFirstNode(T element);
        void addLastNode(T element);
        void printElements();
        T peekFirstNode();
        T peekLastNode();
        T removeFirstNode();
        T removeLastNode();

    private:
        DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList& other);
        ~DoublyLinkedList();
        static DoublyLinkedList* instance;
        int size = 0;
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
};
