

#include "shphashtable.h"
#include <string>
#include <iostream>

using namespace std;

shphashtable::shphashtable(int numBuckets) {
    table = new Node*[numBuckets];
}

shphashtable::~shphashtable() {

}

bool shphashtable::contains(string str) const {
    return false;
}

void shphashtable::put(string str, int score) {

}

void shphashtable::printStats() const {

}
