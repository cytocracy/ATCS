#include <iostream>
#include "shpvector.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
     shpvector<int> vec;
     vec.push_back(46);
     vec.push_back(69);
     vec.push_back(-5);
     for (int i = 0; i < vec.size(); i++) {
         cout << vec.at(i) << endl;
     }
    return 0;
}