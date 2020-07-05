#include "Node.h"

template <class T>
Node<T>::Node(T data, Node<T>* prev, Node<T>* next)
{
    /*
    Constructor
    */

    this->data = data; // Constructor argümanlarını direkt olarak sınıf üye değişkenlerine atadığımız için "this" kullanıyoruz
    this->prev = prev; // Since we pass constructor's arguments directly to class member variables, we have to use "this" pointer
    this->next = next; //
    cout << "Node with a value of " << this->data << " has been added" << endl;

}


template <class T>
Node<T>::Node(const Node<T>& other)
{
    /*
    Copy constructor
    */
}

template <class T>
Node<T>::~Node()
{
    /*
    Destructor
    */
}


template <class T>
string Node<T>::toString()
{
    stringstream s;
    s << data;
    return s.str();
}
