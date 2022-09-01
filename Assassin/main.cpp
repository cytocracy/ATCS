#include <iostream>

using namespace std;

struct DNode {
    string name;
    int numKills;
    DNode* next;
    DNode* prev;
};

DNode* buildList(){
    string name;
    getline(cin, name);
    DNode* start = new DNode;
    start->name = name;
    start->numKills = 0;
    start->next = nullptr;
    start->prev = nullptr;

    DNode* last = start;
    getline(cin, name);
    while (name != ""){
        start->prev = new DNode;
        start->prev->next = start;
        start = start->prev;
        start->name = name;
        start->numKills = 0;
        start->prev = nullptr;
        getline(cin, name);
    }
    start->prev = last;
    last->next = start;

    return start;
}

DNode* findNode(DNode* list, string who){
    DNode* save = list;
    list = list->next;
    while (list != save){
        if (list->name == who)
            return list;
        else list = list->next;
    }
    return list->name == who ? list : nullptr;
}



int main() {
    cout << "Welcome to Assassin!" << endl;
    cout << "Enter the names of the players, one per line." << endl;
    cout << "Enter a blank line to quit." << endl;
    DNode* head = buildList();
    while(head->next != head){
        cout << "Who died? ";
        string deadPerson;
        getline(cin, deadPerson);
        DNode* temp = findNode(head, deadPerson);
        if (temp == nullptr)
            cout << "There is no player named " << deadPerson << endl;
        else {
            temp->prev->numKills++;
            cout << deadPerson << " (" << temp->numKills << " kills) was killed by " << temp->prev->name << " (" << temp->prev->numKills << " kills)" << endl;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if(temp == head) head = head->next;
            delete temp;
        }
    }
    cout << "The winner is " << head->name << "!" << endl;

    return 0;
}
