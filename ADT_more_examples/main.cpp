#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


bool checkBalance(string str){
    stack<char> s;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else if(ch == ')'){
            if(s.empty() || s.top() != '('){
                return false;
            }
            s.pop();
        }
        else if(ch == '}'){
            if(s.empty() || s.top() != '{'){
                return false;
            }
            s.pop();
        }
        else if(ch == ']'){
            if(s.empty() || s.top() != '['){
                return false;
            }
            s.pop();
        }
    }
}

void testCheckBalance() {
    if(checkBalance("if (num < 0) {x=3;} else {y=(x + num);}"))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
}

void testLetterFrequency() {
    ifstream f("file.txt");
    char ch;
    map<char, int> freq;
    while(f >> ch){
        ch = toupper(ch);
        freq[ch]++;
    }
    for(auto it = freq.begin(); it != freq.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    f.close();
}

template <typename ElemType>
set<ElemType> intersection(set<ElemType> s1, set<ElemType> s2){
    set<ElemType> s;
    for(ElemType x: s1){
        if(s2.count(x)>0){
            s.insert(x);
        }
    }
    return s;
}

void testSetIntersection() {
    set<string> a;
    a.insert("Theodore");
    a.insert("Aarav");
    a.insert("Aidan");
    a.insert("Jerry");
    set<string> b;
    b.insert("Aidan");
    b.insert("Ben");
    b.insert("Leila");
    set<string> c = intersection(a, b);
    for(string x : c){
        cout << x << endl;
    }
}

void testFriends() {
    map<string, set<string>> friends;
    cin.ignore();
    string line;
    getline(cin, line);
    while (!line.empty()){
        int index = line.find(" ");
        string first = line.substr(0, index);
        string second = line.substr(index+1);
        friends[first].insert(second);
        friends[second].insert(first);
        getline(cin, line);
    }
    for(auto it = friends.begin(); it != friends.end(); it++){
        cout << it->first << " : ";
        for (string str : it->second){
            cout << str << " ";
        }
        cout << endl;
    }
}
int main() {
    cout << "Hooray for ADTs!" << endl;
    cout << "Choice? ";
    int choice;
    cin >> choice;
    if (choice == 0)
        testCheckBalance();
    else if (choice == 1)
        testLetterFrequency();
    else if (choice == 2)
        testSetIntersection();
    else if (choice == 3)
        testFriends();
    return 0;
}