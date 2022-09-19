#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
using namespace std;


struct MarkovModel {
    map<string, map<char, int>> model;
    int order;
    MarkovModel(int order){ this->order = order; }
    void add(string s) {
        for (int i = 0; i < s.size(); i++) {
            string key = s.substr(i, order);
            char c = s[i + order];
            model[key][c]++;
        }
    }
    char next(string s) {
        map<char, int> m = model[s];
        int r = rand() % m.size();
        for (auto it = m.begin(); it != m.end(); it++) {
            r -= it->second;
            if (r < 0) {
                return it->first;
            }
        }
        return ' ';
    }
};

MarkovModel createModel(string filname, int level){
    if
}

int main() {
    srand(time(0));
    cout << "Hello, Markov Chain!" << endl;
    cout << "Enter level (1-10): ";
    int level;
    cin >> level;
    cout << "Enter file name: ";
    string filename;
    cin >> filename;
    // finish this up



    return 0;
}
