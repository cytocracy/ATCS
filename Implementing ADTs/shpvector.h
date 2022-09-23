//
// Created by Theo on 9/23/2022.
//

#include <string>
#ifndef IMPLEMENTING_ADTS_SHPVECTOR_H
#define IMPLEMENTING_ADTS_SHPVECTOR_H

using namespace std;

template <typename ElemType>
class shpvector {
public:
    shpvector();
    ~shpvector();

    void push_back(ElemType val);
    ElemType at(int index) const;
    void insert(int index, ElemType val);
    void remove(int index);
    void set(int index, ElemType val);
    void clear();
    int size() const;

private:
    ElemType* arr;
    int length;
    int capacity;
    void increaseCapacity();
};

#include "shpvector.cpp"


#endif //IMPLEMENTING_ADTS_SHPVECTOR_H
