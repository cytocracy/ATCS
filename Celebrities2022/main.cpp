#include <iostream>
#include <chrono>

using namespace std;

int main() {

    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    while(chrono::duration_cast<chrono::seconds>(end-start).count() < 10){
        cout << "CLUE" << endl;
        string input;
        cout << "Enter your guess: ";
        getline(cin, input);
        if (input == "Theo")
            cout << "Good" << endl;
        else
            cout << "Bad" << endl;

        end = chrono::high_resolution_clock::now();
    }

    cout << "GAME OVER!" <<  endl;
    return 0;
}