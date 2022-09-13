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

void testSetIntersection() {

}

void testFriends() {
    map<string, set<string>> friends;
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