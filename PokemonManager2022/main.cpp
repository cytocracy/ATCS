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

// just a suggestion: I found it useful to have this function
// returns a pointer to the Node containing that name, or nullptr 
// if that Pokemon is not in the list anywhere
Node* search(string name);



Node* loadPokemon(){
    ifstream file;
    file.open("shortlist.txt");
    Node* list = nullptr;
    while(!file.eof()){
        string line;
        string name;
        int num;

        getline(file, name);
        num = stoi(name.substr(0,name.find(" ")));
        name = name.substr(name.find(" ")+1);

        cout << name << " " << num <<  endl;
        Node* temp = new Node(name, num);
        temp->next = list;
        list = temp;
    }
    file.close();
    return list;
}

int main() {

    Node* pokemon = loadPokemon();


    ofstream f("pokemon.txt");



    cout << "Hello world" << endl;

    return 0;
}