#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// you'll need this somewhere; it should go in the private section of your class
// if you opt to do it that way
struct Node {
    string name;
    int num;
    Node *next;
};

// just a suggestion: I found it useful to have this function
// returns a pointer to the Node containing that name, or nullptr 
// if that Pokemon is not in the list anywhere
Node* search(string name);

int main() {
    cout << "Hello world" << endl;

    return 0;
}