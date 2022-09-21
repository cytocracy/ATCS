#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;


void handleWar( queue<int> &handA, queue<int> &handB, int cardA, int cardB) {
    cout << "There is a War!" << endl;
    stack<int> riskedCards;
    riskedCards.push(cardA);
    riskedCards.push(cardB);
    while(true){
        if(handA.empty()){
            while(!riskedCards.empty()){
                handB.push(riskedCards.top());
                riskedCards.pop();
            }
            return;
        }
        if(handB.empty()){
            while(!riskedCards.empty()){
                handA.push(riskedCards.top());
                riskedCards.pop();
            }
            return;
        }
        int howMany = 4;
        if(handA.size() < howMany)
            howMany = handA.size();
        else if(handB.size() < howMany)
            howMany = handB.size();

        cout << "There are " << howMany << " more cards at risk..." << endl;

        for(int i = 0; i < howMany-1; i++){
            riskedCards.push(handA.front());
            riskedCards.push(handB.front());
            handA.pop();
            handB.pop();
        }
        cardA = handA.front();
        cardB = handB.front();
        handA.pop();
        handB.pop();

        if(cardA % 13 > cardB % 13){
            handA.push(cardA);
            handA.push(cardB);
            while(!riskedCards.empty()){
                handA.push(riskedCards.top());
                riskedCards.pop();
            }
            return;
        } else if (cardA % 13 < cardB % 13){
            handB.push(cardB);
            handB.push(cardA);
            while(!riskedCards.empty()){
                handB.push(riskedCards.top());
                riskedCards.pop();
            }
            return;
        } else {
            riskedCards.push(cardA);
            riskedCards.push(cardB);
        }
    }
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
        } else handleWar(handA, handB, cardA, cardB);
    }
    if(handA.empty()) cout << "Player B wins!" << endl;
    else cout << "Player A wins!" << endl;
    return 0;
}
