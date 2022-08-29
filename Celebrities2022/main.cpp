#include <iostream>
#include <chrono>
#include "Celebrity.h"

using namespace std;

int main() {

    Celebrity c = Celebrity("Lamont Quattlebaum", "bald,dean of students,married to Wendy");
    Celebrity c2 = Celebrity("Kevin Morris", "Leah's dad,Ryan's dad,teaches this class,SHP swim coach,does NYT crossword puzzle daily");
    Celebrity c3 = Celebrity("Oprah Winfrey", "famous talk show host,gave everyone a car");

    vector<Celebrity> celebrities;
    celebrities.push_back(c);
    celebrities.push_back(c2);
    celebrities.push_back(c3);


    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    //choose random celeb
    int index = rand() % celebrities.size();
    Celebrity random_celeb = celebrities[index];

    while(chrono::duration_cast<chrono::seconds>(end-start).count() < 10){
        cout << endl << "Clue: " << random_celeb.getClue() << endl;
        string input;
        cout << "Enter your guess:";
//        cin.ignore();

        getline(cin, input);
        if (input == random_celeb.getName()){
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