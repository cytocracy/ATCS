//
// Created by Theo on 9/23/2022.
//
#include <iostream>
#include "shpvector.h"
using namespace std;

template <typename ElemType>
shpvector<ElemType>::shpvector() {
    arr = new ElemType[10];
    length = 0;
    capacity = 10;
}

template <typename ElemType>
shpvector<ElemType>::~shpvector() {
    delete[] arr;
}

template <typename ElemType>
void shpvector<ElemType>::push_back(ElemType val) {
    if(length == capacity) increaseCapacity();
    arr[length] = val;
    length++;
}

template <typename ElemType>
ElemType shpvector<ElemType>::at(int index) const {
    if(index < 0 || index >= length) cout << "Array index out of bounds" << endl;
    else return arr[index];
}

template <typename ElemType>
void shpvector<ElemType>::insert(int index, ElemType val) {
    if (length == capacity) increaseCapacity();
    for (int i=length; i>index; i--)
        arr[i] = arr[i-1];
    arr[index] = val;
    length++;
}

template <typename ElemType>
void shpvector<ElemType>::remove(int index) {
    length--;
    for (int i=index; i<length; i++)
        arr[i] = arr[i+1];
}

template <typename ElemType>
void shpvector<ElemType>::set(int index, ElemType val) {
    if (index < 0 || index >= length) cout << "Array index out of bounds" << endl;
    else arr[index] = val;

}

template <typename ElemType>
void shpvector<ElemType>::clear() {
    delete[] arr;
    arr = new ElemType[10];
    length = 0;
    capacity = 10;
}

template <typename ElemType>
void shpvector<ElemType>::increaseCapacity() {
    ElemType* bigger = new ElemType[capacity * 2];
    for(int i = 0; i < capacity; i++)
        bigger[i] = arr[i];
    delete[] arr;
    arr = bigger;
    capacity *= 2;
}

template <typename ElemType>
int shpvector<ElemType>::size() const {
    return length;
}
