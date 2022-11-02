

#include "shphashtable.h"
#include <string>
#include <iostream>

using namespace std;

shphashtable::shphashtable(int numBuckets) {
    table = new Node*[numBuckets];
    size = numBuckets;
    for (int i=0; i<size; i++)
        table[i] = nullptr;
}

shphashtable::~shphashtable() {
    for (int i=0; i<size; i++){
        while(table[i]){
            Node* save = table[i];
            table[i] = table[i]->next;
            delete save;
        }
    }
    delete[] table;
}

bool shphashtable::contains(string str) const {
    return getPointer(str);
}

void shphashtable::put(string str, int score) {
    Node* ptr = getPointer(str);
    if (ptr) ptr->value.addScore(score);
    else {
        WordEntry entry(str, score);
        Node* temp = new Node;
        temp->value = entry;
        int index = getHashCode(str);
        temp->next = table[index];
        table[index] = temp;
    }
}

void shphashtable::printStats() const {
    int usedBuckets = 0;
    int emptyBuckets = 0;
    int longestChain = 0;
    int totalChainLength = 0;
    int numCollisions = 0;
    for (int i=0; i<size; i++){
        if (table[i]){
            usedBuckets++;
            int chainLength = 0;
            Node* ptr = table[i];
            while(ptr){
                chainLength++;
                ptr = ptr->next;
            }
            if (chainLength > longestChain) longestChain = chainLength;
            totalChainLength += chainLength;
            numCollisions += chainLength - 1;
        }
        else emptyBuckets++;
    }
    cout << "Used buckets: " << usedBuckets << endl;
    cout << "Empty buckets: " << emptyBuckets << endl;
    cout << "Longest chain: " << longestChain << endl;
    cout << "Average chain length: " << 1.0 * totalChainLength / usedBuckets << endl;
    cout << "Number of collisions: " << numCollisions << endl;
}



double shphashtable::getAverageScore(string str) const {
    Node* ptr = getPointer(str);
    if (ptr) return ptr->value.getAvgScore();
    else return 2.0;
}

int shphashtable::getHashCode(string str) const {
    hash<string> hashFn;
    return hashFn(str) % size;
}

shphashtable::Node *shphashtable::getPointer(string str) const {
    Node* ptr = table[getHashCode(str)];
    while (ptr != nullptr) {
        if (ptr->value.getWord() == str) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}
