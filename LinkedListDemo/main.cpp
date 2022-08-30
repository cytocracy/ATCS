#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

int sum(Node* list){
    int result = 0;
    Node* temp = list;
    while(temp != nullptr){
        result += temp->value;
        temp = temp->next;
    }
    return result;
}

int length(Node* list){
    int result = 0;
    Node* temp = list;
    while(temp != nullptr){
        result++;
        temp = temp->next;
    }
    return result;
}

int length2(Node* list) {
    int result = 0;
    for(Node* temp = list; temp!=nullptr; temp = temp->next)
        result++;
    return result;
}

int lengthR(Node* list) {
    if(list == nullptr)
        return 0;
    else
        return 1+ lengthR(list->next);
}

int countEvens(Node* list){
    int result = 0;
    for(Node* temp = list; temp!=nullptr; temp = temp->next){
        if(temp->value %2 == 0) result++;
    }
    return result;
}

void twiceAllValues(Node* list){
    for(Node* temp = list; temp!=nullptr; temp = temp->next){
        temp->value *= 2;
    }
}

void doubleTheList(Node* list){
    //

}

bool contains(Node* list, int value){
    Node* temp = list;
    while(temp != nullptr){
        if(temp->value == value)
            return true;
        temp = temp->next;
    }
    return false;
}

void deleteLast(Node* &list){
    if(list == nullptr)
        return;
    if(list->next == nullptr){
        delete list;
        list = nullptr;
        return;
    }
    Node*temp = list;
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void deleteDoubleDigits(Node* &list){
    while(list != nullptr && list->value >= 10){
        Node* save = list;
        list = list->next;
        delete save;
    }
    if(list == nullptr) return;
    Node* temp = list;
    while(temp->next !=nullptr){
        if (temp->next->value >=10){
            Node* save = temp->next;
            temp->next = save->next;
            delete save;
        } else {
            temp = temp->next;
        }
    }
}

void stutter(Node* list){
    Node* temp = list;
    while(temp != nullptr){
        Node* save = temp->next;
        temp->next = new Node;
        temp->next->value = temp->value;
        temp->next->next = save;
        temp = save;
    }
}

int main() {

    Node* head;
    head= nullptr;
    /*head = new Node;
    head->value = 27;
    head->next = new Node;
    head->next->value = 44;
    head->next->next = nullptr; */

    cout << "Hello, Linked Lists!" << endl;
    cout << "Enter integers, one per line. Enter a negative number to stop." << endl;
    int num;
    cin >> num;
    while(num >= 0) {
        Node* temp = head;
        head = new Node;
        head->value = num;
        head->next = temp;
        cin >> num;
    }
    cout << "The length of your list is " << length(head) << endl;
    cout << "There are " << countEvens(head) << " even numbers in the list." << endl;
    //twiceAllValues(head);
//    doubleTheList(head);
    if (contains(head, 27))
        cout << "There is a 27!" << endl;
//    deleteLast(head);
//    deleteDoubleDigits(head);
    stutter(head);
    cout << "The sum of the values in your linked list is " << sum(head) << endl;


    return 0;
}

