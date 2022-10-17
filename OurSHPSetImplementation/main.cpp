#include <iostream>
#include "shpset.h"
#include <vector>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    shpset<string> students;
    students.insert("Jerry");
    students.insert("Lucy");
    students.insert("Aarav");
    students.insert("Ben");
    students.erase("Lucy");
    students.erase("Aarav");
    students.insert("Aarav");
    students.insert("Armin");

//    for (string name : students)
//        cout << name << endl;

    vector<string> vec = students.getVector();
    for (string name : vec)
        cout << name << endl;
    cout << "There are " << students.size() << " students." << endl;
    if(students.contains("Ben"))
        cout << "Ben is in the set." << endl;

    return 0;
}
