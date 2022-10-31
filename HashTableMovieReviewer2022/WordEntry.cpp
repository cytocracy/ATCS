
#include "WordEntry.h"
using namespace std;

WordEntry::WordEntry(string str, int score) {
    word = str;
    sumScores = score;
    numScores = 1;
}

string WordEntry::getWord() const {
    return word;
}

double WordEntry::getAvgScore() const {
    return 1.0 * sumScores / numScores;
}

void WordEntry::addScore(int score) {
    sumScores += score;
    numScores++;
}

WordEntry::WordEntry() {
    word = "";
    sumScores = 0;
    numScores = 0;

}
