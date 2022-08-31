#include <iostream>
#include <chrono>
#include <fstream>
#include "Celebrity.h"

using namespace std;


int main() {

    ifstream f("celebrities.txt");
    string line;
    vector<Celebrity> celebrities;

    while(!f.eof()){
        getline(f, line);
        string name = line.substr(0, line.find(":"));
        line.erase(0, line.find(":") + 1);
        Celebrity c = Celebrity(name, line);
        cout << name <<endl;
        celebrities.push_back(c);
    }


    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    //choose random celeb

    int index = rand() % celebrities.size();
    Celebrity random_celeb = celebrities[index];
    celebrities.erase(celebrities.begin() + index);
    cout << random_celeb.getName() << endl;

    int score = 0;

    while(chrono::duration_cast<chrono::seconds>(end-start).count() < 60){


        cout << endl << "Clue: " << random_celeb.getClue() << endl;
        string input;
        cout << "Enter your guess:";

        getline(cin, input);
        if (input == random_celeb.getName()){
            cout << "Correct!" << endl;
            score++;
            celebrities.erase(celebrities.begin() + index);
            if(celebrities.size() == 0) break;
            index = rand() % celebrities.size();
            random_celeb = celebrities[index];

        }
        else
            cout << "Incorrect." << endl;

        end = chrono::high_resolution_clock::now();
    }

    cout << "GAME OVER!" <<  endl;
    cout << "You scored " << score << " out of " << celebrities.size() << "." << endl;
    return 0;
}