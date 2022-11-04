#include <iostream>
#include <queue>

using namespace std;

struct Student {
    string name;
    int grade;
    Student(string n, int g){
        name = n;
        grade = g;
    }

    bool operator < (const Student& rhs) const {
        return this->grade < rhs.grade;
    }
};

int main() {
    cout << "Hello, Priority Queues!" << endl;
    priority_queue<Student> students;
    students.push(Student("Leila", 12));
    students.push(Student("Lucy", 12));
    students.push(Student("Ayaan", 12));
    students.push(Student("Theo", 11));
    students.push(Student("Jerry", 12));

    while (!students.empty()) {
        cout << students.top().name << endl;
        students.pop();
    }

    return 0;
}
