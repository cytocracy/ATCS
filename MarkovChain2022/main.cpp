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
    string init_seed(){
        string seed = model.begin()->first;
        for (auto it = model.begin(); it != model.end(); it++){
            if (it->second.size() > seed.size()) seed = it->first;
        }
//        cout << "Seed: " << seed << ":)" << endl;
        return seed;
    }

    void add(string s) {
        for (int i = 0; i < s.size(); i++) {
            string key = s.substr(i, order);
            char c = s[i + order];
            model[key][c]++;
        }

    }


    char next(string s) {
        map<char, int> m = model[s];
        int total = 0;
        for (auto e : m) {
            total += e.second;
        }
        if(total == 0) return ' ';
        int r = rand() % total;
        for (auto e : m) {
            r -= e.second;
            if (r <= 0) {
                return e.first;
            }
        }
        return ' ';
    }
};
//idk

MarkovModel createModel(string filename, int level){
    ifstream file(filename);
    string s;
    char ch;
    MarkovModel model(level);
    while (file >>noskipws>> ch) {
        s+=toupper(ch);
    }
    model.add(s);
    return model;
}

int main() {
    srand(time(0));
    cout << "Hello, Markov Chain!" << endl;
    cout << "Enter level (1-10): ";
    int level;
    cin >> level;
    cout << "Enter file name: ";
    cin.ignore();
    string filename;
    cin >> filename;
    // finish this up
    MarkovModel model = createModel(filename, level);
    string s = model.init_seed();
    for (int i = 0; i < 300; i++) {
        s += model.next(s.substr(i, level));
    }
    cout << s << endl;
    return 0;
}
