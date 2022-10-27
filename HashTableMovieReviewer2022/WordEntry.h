
#ifndef HASHTABLEMOVIEREVIEWER_WORDENTRY_H
#define HASHTABLEMOVIEREVIEWER_WORDENTRY_H
#include <string>

using namespace std;

class WordEntry {
public:
    WordEntry(string str, int score);
    string getWord() const;
    double getAvgScore() const;
    void addScore(int score);

private:

};


#endif //HASHTABLEMOVIEREVIEWER_WORDENTRY_H
