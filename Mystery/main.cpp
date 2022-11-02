#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    unordered_set<string> students;
    students.insert("Ben");
    students.insert("Theo");
    students.insert("Armin");
    students.insert("Nic");
    students.erase("Armin");

    for(auto it = students.begin(); it != students.end(); it++)
        cout << *it << endl;



    return 0;
}
