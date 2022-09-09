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


Node* loadPokemon(string filename){
    ifstream file;
    file.open(filename);
    Node* list = nullptr;
    while(!file.eof()){
        string name;
        int num;

        file >> num;
        getline(file, name);
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

void addNewPokemon(Node* &list, string name, int num){
    Node* newpoke = new Node(name, num);
    newpoke->next = list;
    list = newpoke;
}

int main() {

    bool running = true;

    cout << "Enter the name of a Pokemon file: ";
    string filename;
    cin >> filename;


    Node* pokemon = loadPokemon(filename);


    ofstream f("pokemon.txt");


    cout << "Hello world" << endl;

    printList(pokemon);

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
            cout << "Enter the name of the Pokemon: ";
            string name;
            cin >> name;
            cout << "Enter the number of the Pokemon: ";
            int num;
            cin >> num;
            addNewPokemon(pokemon, name, num);
            cout << "Pokemon added!" << endl;
        } else if (choice == 2){
            cout << "Enter the name of the Pokemon: ";
            string name;
            cin >> name;
            Node* temp = search(name, pokemon);
            if(temp != nullptr){
                cout << "Pokemon removed!" << endl;
            } else {
                cout << "Pokemon not found!" << endl;
            }
        } else if (choice == 3){

        } else if (choice == 4){

        } else if (choice == 5){
            running = false;
        } else {
            cout << "Invalid choice. Try again.\n";
        }





    }

    cout << "Goodbye!\n";

    return 0;
}