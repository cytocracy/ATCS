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
    int pos = init_clues.find(",");
    string clue;
    while(pos != -1) {
        clue = init_clues.substr(0, pos);
        clues.push_back(clue);
        init_clues.erase(0, pos + 1);
        pos = init_clues.find(",");
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
        int index = rand() % clues.size();
        string clue = clues[index];
        clues.erase(clues.begin() + index);
        return clue;
    }
}

Celebrity::~Celebrity() {
    //destructor
}
