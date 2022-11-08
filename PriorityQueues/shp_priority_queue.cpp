//
// Created by Theo on 11/4/2022.
//

#include "shp_priority_queue.h"

shp_priority_queue::shp_priority_queue() {
 //we're done
}

shp_priority_queue::~shp_priority_queue() {
 //we're done
}

void shp_priority_queue::push(string str) {
    heap.push_back(str);
    heapifyUp(heap.size() - 1);
}

void shp_priority_queue::pop() {
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapifyDown(0);
}

string shp_priority_queue::top() const {
    return heap[0];
}

int shp_priority_queue::size() const {
    return heap.size();
}

bool shp_priority_queue::empty() const {
    return heap.size() == 0;
}

void shp_priority_queue::heapifyUp(int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (heap[parent] > heap[index]) {
        string temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        heapifyUp(parent);
    }

}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
void shp_priority_queue::heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        string temp = heap[smallest];
        heap[smallest] = heap[index];
        heap[index] = temp;
        heapifyDown(smallest);
    }
}
#pragma clang diagnostic pop
