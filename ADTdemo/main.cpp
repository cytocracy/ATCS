#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int main() {
    cout << "Hello, ADTs!" << endl;

    cout << "QUEUE" << endl;
    queue<string> q;
    q.push("Leila");
    q.push("Nic");
    q.push("Ben");

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    cout << "STACK" << endl;

    stack<string> s;
    s.push("Paul");
    s.push("Jerry");
    s.push("Aidan");

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    cout << "SET" << endl;

    set<string> names;
    names.insert("Lucy");
    names.insert("Paul");
    names.insert("Armin");
    names.insert("Lucy");
    names.erase("Paul");
    names.insert("Jerry");
    if(names.count("Armin"))
        cout << "Armin is in the set" << endl;
    if(names.count("Paul"))
        cout << "Paul is in the set" << endl;
    set<string>::iterator itr = names.begin();
    while (itr != names.end()){
        cout << *itr << endl;
        itr++;
    }

    cout << "MAP" << endl;
    map<string, double> moneyMap;
    moneyMap.insert({"Ayaan", 20.00});
    moneyMap.insert({"Leila", 85.00});
    moneyMap.insert({"Aarav", 0.50});

    map<string, double>::iterator moneyItr = moneyMap.begin();
    while (moneyItr != moneyMap.end()) {
        cout << moneyItr->first << " has " << moneyItr->second << endl;
        moneyItr++;
    }

    if (moneyMap.count("Leila"))
        cout << moneyMap.at("Leila") << endl;

    cout << moneyMap["Ayaan"] << endl;
    moneyMap["Aarav"] += 10.00;

    moneyMap.erase("Ayaan");


    return 0;
}
