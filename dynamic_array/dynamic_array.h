#pragma once

#include <vector>

using namespace std;

template <class T>
class DynamicArray
{
    public:
        static DynamicArray* getInstance();
        unsigned int getSize();
        unsigned int getCapacity();
        bool isEmpty();
        T getElement(int index);
        void setElement(int index, T element);
        void pushBack(const T t);
        void toVector(vector<int> &vec);
        void printElements();
        void clearArray();

    private:
        DynamicArray();
        DynamicArray(const DynamicArray& other);
        ~DynamicArray();
        static DynamicArray* instance;
        T* arr;                                      // Internal static array
        const unsigned int initial_capacity = 4;     // Default capacity
        unsigned int capacity;                       // Allocated capacity
        unsigned int size;                           // Actual array size
};
