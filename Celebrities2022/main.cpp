#include <iostream>
#include <chrono>
#include "Celebrity.h"

using namespace std;

int main() {

    Celebrity c = Celebrity("Lamont Quattlebaum", "bald,dean of students,married to Wendy");

    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    while(chrono::duration_cast<chrono::seconds>(end-start).count() < 10){
        cout << endl << "Clue: " << c.getClue() << endl;
        string input;
        cout << "Enter your guess:";
//        cin.ignore();

        getline(cin, input);
        if (input == c.getName()){
            cout << "Good" << endl;
            break;
        }
        else
            cout << "Bad" << endl;

        end = chrono::high_resolution_clock::now();
    }

    cout << "GAME OVER!" <<  endl;
    return 0;
}