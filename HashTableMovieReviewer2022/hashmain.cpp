#include <iostream>
#include "shphashtable.h"
using namespace std;

int main() {
    cout << "Hello, Hash Table!" << endl;
    shphashtable names(17);



    names.printStats();

    return 0;
}