//
// Created by Kevin Morris on 11/16/22.
//

#include "LoudDog.h"

LoudDog::LoudDog(string name) : Dog(name) {
}

string LoudDog::speak() const {
    return Dog::speak() + " " + Dog::speak();
}
