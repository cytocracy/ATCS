#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    cout << "Hello, ADTs!" << endl;
    queue<string> q;
    q.push("Leila");
    q.push("Nic");
    q.push("Ben");

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    stack<string> s;
    s.push("Paul");
    s.push("Jerry");
    s.push("Aidan");

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
