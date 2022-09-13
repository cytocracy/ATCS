#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// you'll need this somewhere; it should go in the private section of your class
// if you opt to do it that way
struct Node {
    string name;
    int num;
    Node *next;

    Node(string name, int num){
        this->name = name;
        this->num = num;
        next = nullptr;
    }

    Node(){}

};

Node* search(string name, Node* list){
    Node* current = list;
    while(current != nullptr){
        if(current->name == name)
            return current;
        current = current->next;
    }
    return nullptr;
}

void removeNode(Node* node, Node* list){
    Node* current = list;
    while(current != nullptr){
        if(current->next == node){
            current->next = node->next;
            delete node;
            return;
        }
        current = current->next;
    }
}

Node* loadPokemon(string filename){
    ifstream file;
    file.open(filename);
    Node* list = nullptr;
    while(!file.eof()){
        string name;
        int num;

        file >> num;
        getline(file, name);
        name = name.substr(1);
        Node* temp = new Node(name, num);
        temp->next = list;
        list = temp;
    }
    file.close();
    return list;
}

void printList(Node* list){
    Node* temp = list;
    while(temp != nullptr){
        cout << temp->name << " " << temp->num << endl;
        temp = temp->next;
    }
}

int main() {

    bool running = true;

    cout << "Enter the name of a Pokemon file: ";
    string filename;
    cin >> filename;

    Node* pokemon = loadPokemon(filename);

    while(running){
        cout << "1. I want to add a new Pokemon to my collection.\n"
             << "2. I want to remove a Pokemon from my collection.\n"
             << "3. I want to lookup a Pokemon in my collection.\n"
             << "4. I want to save changes.\n"
             << "5. Quit.\n";

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if(choice == 1){
            cout << "Enter the name of the Pokemon you want to add: ";
            string name;
            cin >> name;
            cout << "Enter the number of the Pokemon you want to add: ";
            int num;
            cin >> num;

            Node* userPokemon = search(name, pokemon);
            if(userPokemon != nullptr){
                userPokemon->num += num;
            } else {
                Node* temp = new Node(name, num);
                temp->next = pokemon;
                pokemon = temp;
            }
        }
        else if(choice == 2){
            cout << "Enter the name of the Pokemon you want to remove: ";
            string name;
            cin >> name;
            cout << "Enter the number of the Pokemon you want to remove: ";
            int num;
            cin >> num;

            Node* userPokemon = search(name, pokemon);
            if(userPokemon != nullptr){
                userPokemon->num -= num;
                if(userPokemon->num <= 0){
                    removeNode(userPokemon, pokemon);
                    cout << "You have no more " << name << "s." << endl;
                } else {
                    cout << "You now have " << userPokemon->num << " " << name << "s." << endl;
                }
            } else {
                cout << "You don't have any " << name << "s." << endl;
            }
        }
        else if(choice == 3){
            cout << "Enter the name of the Pokemon you want to lookup: ";
            string name;
            cin >> name;

            Node* temp = search(name, pokemon);
            if(temp != nullptr){
                cout << "You have " << temp->num << " " << name << "s." << endl;
            }
            else{
                cout << "Could not find " << name << endl;
            }
        }
        else if(choice == 4){
            cout << "Enter the name of the file you want to save to: ";
            string filename;
            cin >> filename;

            ofstream file;
            file.open(filename);
            Node* temp = pokemon;
            while(temp != nullptr){
                file << temp->num << " " << temp->name << endl;
                temp = temp->next;
            }
            file.close();
        }
        else if(choice == 5){
            running = false;
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    }
    cout << "Goodbye!\n";
    return 0;
}