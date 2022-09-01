#include <iostream>
#include <chrono>
#include <fstream>
#include <algorithm>
#include "Celebrity.h"

using namespace std;

vector<Celebrity> loadCelebs(){
    ifstream f("celebrities.txt");
    string line;
    vector<Celebrity> celebrities;

    while(!f.eof()){
        getline(f, line);
        string name = line.substr(0, line.find(":"));
        line.erase(0, line.find(":") + 1);
        Celebrity c = Celebrity(name, line);
        celebrities.push_back(c);
    }
    return celebrities;
}

int main() {
    srand(time(0));
    bool playing = true;

    cout << endl << endl<< "Welcome to the Celebrity Game!" << endl;

    vector<Celebrity> celebrities_list = loadCelebs();
    int num_celebs = celebrities_list.size();
    vector<Celebrity> celebrities;

    while(playing){

        celebrities.clear();
        copy(celebrities_list.begin(), celebrities_list.end(), back_inserter(celebrities));

        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

        int index = rand() % celebrities.size();
        Celebrity random_celeb = celebrities[index];

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

        cout << endl << "GAME OVER!" <<  endl;
        if(celebrities.size() != 0) cout << "The answer was " << random_celeb.getName() << endl;
        cout << "You scored " << score << " out of " << num_celebs << "." << endl;

        cout << endl << "Would you like to play again? (y/n)" << endl;
        string input;
        getline(cin, input);
        if(input != "y") playing = false;
    }

    return 0;
}