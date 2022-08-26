//
// Created by Theo Parker on 8/25/2022.
//
#include <iostream>
#include <vector>

using namespace std;

#ifndef CELEBRITIES_CELEBRITY_H
#define CELEBRITIES_CELEBRITY_H


class Celebrity {
public:
    Celebrity(string name, string clues);
    string getName();
    string genClue();
    ~Celebrity();
private:
    vector<string> clues;
    string name;

};


#endif //CELEBRITIES_CELEBRITY_H
