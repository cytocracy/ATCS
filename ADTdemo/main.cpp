#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

//queue<ElemType> reverseQueue(queue<ElemType> q) {
//    stack<ElemType> s;
//    while (!q.empty()) {
//        s.push(q.front());
//        q.pop();
//    }
//    while (!s.empty()) {
//        q.push(s.top());
//        s.pop();
//    }
//    return q;
//}
//
//set<ElemType> union(set<ElemType> set1, set<ElemType> set2) {
//    set<ElemType> result;
//    for (auto it = set1.begin(); it != set1.end(); it++) {
//        result.insert(*it);
//    }
//    for (auto it = set2.begin(); it != set2.end(); it++) {
//        result.insert(*it);
//    }
//    return result;
//}


void removeEvens(stack<int> &numStack){
    stack<int> temp;
    while(!numStack.empty()){
        if(numStack.top() % 2 == 0){
            numStack.pop();
        }else{
            temp.push(numStack.top());
            numStack.pop();
        }
    }
    while(!temp.empty()){
        numStack.push(temp.top());
        temp.pop();
    }
}

void assignTask(queue<string> &taskQueue, set<string> &currentTasks){
    int size = taskQueue.size();
    for(int i=0; i<size; i++){
        string task = taskQueue.front();
        if(currentTasks.count(task) == 0){
            currentTasks.insert(task);
            taskQueue.pop();
            break;
        } else {
            taskQueue.pop();
            taskQueue.push(task);
        }
    }
}

map<string, set<string>> getCorrectClubMap(map<string, set<string>> const &origMap){
    map<string, set<string>> result;
    for(auto it = origMap.begin(); it != origMap.end(); it++){
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
            result[*it2].insert(it->first);
        }
    }
    return result;
}

int main() {
//    cout << "Hello, ADTs!" << endl;
//
//    cout << "QUEUE" << endl;
//    queue<string> q;
//    q.push("Leila");
//    q.push("Nic");
//    q.push("Ben");
//
//    while(!q.empty()){
//        cout << q.front() << endl;
//        q.pop();
//    }
//
//    cout << "STACK" << endl;
//
//    stack<string> s;
//    s.push("Paul");
//    s.push("Jerry");
//    s.push("Aidan");
//
//    while (!s.empty()) {
//        cout << s.top() << endl;
//        s.pop();
//    }
//
//    cout << "SET" << endl;
//
//    set<string> names;
//    names.insert("Lucy");
//    names.insert("Paul");
//    names.insert("Armin");
//    names.insert("Lucy");
//    names.erase("Paul");
//    names.insert("Jerry");
//    if(names.count("Armin"))
//        cout << "Armin is in the set" << endl;
//    if(names.count("Paul"))
//        cout << "Paul is in the set" << endl;
//    set<string>::iterator itr = names.begin();
//    while (itr != names.end()){
//        cout << *itr << endl;
//        itr++;
//    }
//
//    cout << "MAP" << endl;
//    map<string, double> moneyMap;
//    moneyMap.insert({"Ayaan", 20.00});
//    moneyMap.insert({"Leila", 85.00});
//    moneyMap.insert({"Aarav", 0.50});
//
//    map<string, double>::iterator moneyItr = moneyMap.begin();
//    while (moneyItr != moneyMap.end()) {
//        cout << moneyItr->first << " has " << moneyItr->second << endl;
//        moneyItr++;
//    }
//
//    if (moneyMap.count("Leila"))
//        cout << moneyMap.at("Leila") << endl;
//
//    cout << moneyMap["Ayaan"] << endl;
//    moneyMap["Aarav"] += 10.00;
//
//    moneyMap.erase("Ayaan");
//
//    cout << "REVERSE QUEUE" << endl;
  stack<int> test;
  test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    removeEvens(test);
    while(!test.empty()){
        cout << test.top() << endl;
        test.pop();
    }

//    map<string, set<string>> clubMap;
//    clubMap["Chess"].insert("Aidan");
//    clubMap["Chess"].insert("Armin");
//    clubMap["SHPTV"].insert("Armin");
//    clubMap["SHPTV"].insert("Ben");
//    clubMap["Robotics"];
//    map<string, set<string>> correctClubMap = getCorrectClubMap(clubMap);
//    for(auto it = correctClubMap.begin(); it != correctClubMap.end(); it++){
//        cout << it->first << ": ";
//        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
//            cout << *it2 << " ";
//        }
//        cout << endl;
//    }

//    queue<string> taskQueue;
//    taskQueue.push("A");
//    taskQueue.push("B");
//    taskQueue.push("C");
//    taskQueue.push("D");
//
//    set<string> currentTasks;
//    currentTasks.insert("B");
//    currentTasks.insert("X");
//    currentTasks.insert("Y");
//    currentTasks.insert("A");
//    currentTasks.insert("C");
//    currentTasks.insert("D");
//
//    assignTask(taskQueue, currentTasks);
//    while(!taskQueue.empty()){
//        cout << taskQueue.front() << endl;
//        taskQueue.pop();
//    }
//    cout << endl;
//    for(auto it = currentTasks.begin(); it != currentTasks.end(); it++){
//        cout << *it << endl;
//    }

    return 0;
}
