#include <iostream>
#include "shphashtable.h"
using namespace std;


int main() {
    cout << "Let's experiment a little bit..." << endl;

    shphashtable ourTable(11);
    ourTable.put("Armin", 4);
    ourTable.put("Aarav", 1);
    ourTable.put("Lucy", 0);
    ourTable.put("Lucy", 3);

    cout << ourTable.getAverageScore("Lucy") << endl;

    ourTable.printStats();

    return 0;
}