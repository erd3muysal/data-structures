#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "dynamic_array.h"

const int NUMBER_OF_ELEMENTS = 40;
const int MAX_ELEMENT = 50;
const int QUERY_ELEMENT = 13;

int findInVec(vector<int> vec, int element);  // Performs a binary search

int main(){

	srand(time(NULL));

	DynamicArray<int> *array = DynamicArray<int>::getInstance();

	for(int i = 0; i < NUMBER_OF_ELEMENTS; i++){
		int randInt = static_cast<int>(rand() % MAX_ELEMENT + 1);
		array->pushBack(randInt);
		cout << "Size of the array is: " << array->getSize() << endl;
		cout << "Capacity of the array is: " << array->getCapacity() << endl;
        cout << "First element is: " << array->getElement(0) << endl;
		cout << "------------------------------------------------------------" << endl;
	}

	vector<int> randVec;
	array->toVector(randVec);
	sort(randVec.begin(), randVec.end());  // Sorting the array
	cout << "The array is: " << endl;

	for(int i = 0; i < NUMBER_OF_ELEMENTS; i++){
		cout << randVec[i] << " ";
	}

	cout << endl;
	int k = findInVec(randVec, QUERY_ELEMENT);
	cout << endl;

	if(k == -1){
	    cout << "The element " << QUERY_ELEMENT << " is not present in the generated array.." << endl;
	}else{
	    cout << randVec[k] << " at " << k << endl;
	}

	return 0;
}

int findInVec(vector<int> vec, int element){
    /*
    Performs a binary search on this array to find an element in O(log(n)) time
    Make sure this array is sorted! Returns a value < 0 if item is not found
    */

	int start = 0;
	int end = vec.size() - 1;
	int occurance = -1;
	while(start <= end){
		int mid = start + (end - start) / 2;
		if (vec[mid] == element) {
			occurance = mid;
			end = mid -1;
		}
		else if (vec[mid] > element) {
			end = mid -1;
		}
		else { // vec[mid] > element
			start = mid + 1;
		}
	}
	if (occurance == -1) {
		return -1;
	}
	else {
		return occurance;
	}
}
