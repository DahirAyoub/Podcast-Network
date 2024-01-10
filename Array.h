#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {

	public:
		//constructor
		Array();
				
		Array(const Array& );
		
		//destructor
		~Array();
		
		//other
		T add(T);
		T remove(T);
		T get(int index) const;
		int getSize() const;
		bool isFull() const;
		Array<T>& operator+=(T);
		Array<T>& operator-=(T);
		T operator[](int);
		T operator[](int) const;
		void clear();
	
	
	private:
		int numElements;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	numElements = 0;
}

template <class T>
Array<T>::Array(const Array& array2){
	numElements=array2.numElements;
	elements=new T[MAX_ARR];
	for(int i=0;i<numElements;++i){
		elements[i] = array2.get(i);
	}
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
int Array<T>::getSize() const{
	return numElements;
}

template <class T>
bool Array<T>::isFull() const {
	return numElements >= MAX_ARR;
}

template <class T>
Array<T>& Array<T>::operator+=(T t){
	if (numElements >= MAX_ARR)   return *this;
  	elements[numElements++] = t;
	return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(T t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
	return *this;
}

template <class T>
T Array<T>:: add(T t){
	if (numElements >= MAX_ARR) return T(); 
    elements[numElements++] = t;
    return t;
};

template <class T>
T Array<T>:: remove(T t){
	elements-=t;
	return t;
};
template <class T>
T Array<T>:: get(int index) const{
	return elements[index];
};

template <class T>
T Array<T>::operator[](int index) const{
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
T Array<T>::operator[](int index){
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
void Array<T>::clear(){
	numElements=0;
}


#endif