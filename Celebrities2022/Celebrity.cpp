//
// Created by Theo Parker on 8/25/2022.
//

#include "Celebrity.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

Celebrity::Celebrity(string init_name, string init_clues) {
    name = init_name;
//    istringstream f(init_clues);
//
    int pos = 0;
    string token;
    while((pos = init_clues.find(",")) != string::npos) {
        token = init_clues.substr(0, pos);
//        cout << token << endl;
        clues.push_back(token);
        init_clues.erase(0, pos + 1);

    }
    clues.push_back(init_clues);
}

string Celebrity::getName() {
    return name;
}

string Celebrity::getClue() {
    if(clues.size() == 0)
        return "No more clues";
    else {
        //choose a random clue
        int index = rand() % clues.size();
        string clue = clues[index];
        clues.begin() + index;
        clues.erase(clues.begin() + index);
        return clue;
    }
}

Celebrity::~Celebrity() {
    //destructor
}
