#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct RoomAssignment {
    string number;
    string teacher;
};

vector<RoomAssignment> assignments;

void loadRooms(){
    ifstream f("rooms.txt");
    while (!f.eof()) {
        string num;
        string who;
        f >> num;
        getline(f, who);
        RoomAssignment ra;
        ra.number = num;
        ra.teacher = who.substr(1);
        assignments.push_back(ra);
    }
    f.close();
}

int getChoice() {
    cout << endl;
    cout << "1: Search by room" << endl;
    cout << "2: Search by teacher" << endl;
    cout << "3: Quit" << endl;

    while(true) {
        cout << "Your choice? ";
        int num;
        cin >> num;
        cin.ignore();
        if (num >= 1 && num <= 3) {
            return num;
        } else return 3;
    } 
}

void searchByRoom() {
    string num;
    cout << "Enter room number: ";
    getline(cin, num);
    bool found = false;
    for (RoomAssignment r : assignments) {
        if (r.number == num) {
            found = true;
            cout << r.teacher << " ";
        }
    }
    if (!found) {
        cout << "No teacher found" << endl;
    }
    cout << endl;
}

void searchByTeacher() {
    string who;
    cout << "Enter the name of a teacher: ";
    getline(cin, who);
    bool found = false;
    for (RoomAssignment r : assignments) {
        if (r.teacher == who) {
            found = true;
            cout << r.number << " ";
        }
    }
    if (!found) {
        cout << "No room found" << endl;
    }
    cout << endl;
}

int main() {
    loadRooms();

    cout << "Hello!" << endl;
    while (true) {
        int choice = getChoice();
        if(choice == 1) searchByRoom();
        else if(choice == 2) searchByTeacher();
        else break;
    }
    cout << "Goodbye!" << endl;
    return 0;
}
