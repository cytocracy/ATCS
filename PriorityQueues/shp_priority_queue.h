//
// Created by Theo on 11/4/2022.
//
#include <string>
#include <iostream>
#include <vector>

#ifndef PRIORITYQUEUES_SHP_PRIORITY_QUEUE_H
#define PRIORITYQUEUES_SHP_PRIORITY_QUEUE_H

using namespace std;


class shp_priority_queue {
public:
    shp_priority_queue();
    ~shp_priority_queue();
    void push(string str);
    void pop();
    string top() const;
    int size() const;
    bool empty() const;


private:
    vector<string> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);

};


#endif //PRIORITYQUEUES_SHP_PRIORITY_QUEUE_H
