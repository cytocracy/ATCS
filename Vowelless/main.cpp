#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isVowel(char ch);

string makeVowelless(string str)
{
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = toupper(str[i]);
        if (!isVowel(ch) && isalpha(ch))
            result += ch;
    }
    return result;
}

bool isVowel(char ch)
{
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int main()
{
    srand(time(0));
    vector<string> phrases;
    phrases.push_back("Sacred Heart Preparatory");
    phrases.push_back("Ayaan Govil");
    phrases.push_back("Aarav Chandrasekar");
    phrases.push_back("Leila Nawas");

    cout << "Welcome to Vowelless!" << endl;
    cout << "How many times do you want to play? ";
    int numTimes;
    cin >> numTimes;
    cin.ignore();
    for (int i = 0; i < numTimes; i++)
    {
        int index = rand() % phrases.size();
        string answer = phrases[index];
        string clue = makeVowelless(answer);
        cout << "Here's your clue: " << clue << endl;
        cout << "What's your guess? ";
        string guess;
        getline(cin, guess);
        if (guess == answer)
            cout << "Correct!" << endl;
        else
            cout << "Wrong! The correct answer was " << answer << "." << endl;
        cout << endl;
    }
    return 0;
}
