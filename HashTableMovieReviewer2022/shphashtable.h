

#ifndef HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
#define HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
#include <string>
using namespace std;

class shphashtable {

public:
    shphashtable(int numBuckets);
    ~shphashtable();
    bool contains(string str) const;
    void put(string str, int score);
    void printStats() const;

private:
    struct Node {
        string value;
        Node* next;
    };
    int size;
    Node** table;

};


#endif //HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
