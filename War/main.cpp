#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;


void handleWar() {
    cout << "WAR!" << endl;
}

int main() {
    srand(time(0));
    cout << "Let's play War!" << endl;
    vector<int> deck;
    for (int i = 0; i < 52; i++)
        deck.push_back(i);
    queue<int> handA;
    queue<int> handB;
    while(!deck.empty()){
        int index = rand() % deck.size();
        handA.push(deck[index]);
        deck.erase(deck.begin() + index);
        index = rand() % deck.size();
        handB.push(deck[index]);
        deck.erase(deck.begin() + index);
    }
    while(!handA.empty() && !handB.empty()){
        cout << handA.size() << " " << handB.size() << endl;
        int cardA = handA.front();
        int cardB = handB.front();
        handA.pop();
        handB.pop();
        if(cardA % 13 > cardB % 13){
            handA.push(cardA);
            handA.push(cardB);
        } else if (cardB % 13 > cardA % 13){
            handB.push(cardB);
            handB.push(cardA);
        } else handleWar();
    }
    if(handA.empty()) cout << "Player B wins!" << endl;
    else cout << "Player A wins!" << endl;
    return 0;
}
