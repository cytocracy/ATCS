#include <iostream>
#include <fstream>
#include "shphashtable.h"

using namespace std;


int main() {
    cout << "Hello, Movie Reviews!" << endl;
    shphashtable reviews(10007);
    // load review data here, probably in a function

    reviews.printStats();

    // prompt user for new review, parse it, output predicted rating

    return 0;
}