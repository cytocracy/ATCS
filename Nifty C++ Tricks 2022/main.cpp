#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
#include <thread>
#include <algorithm>
#include <chrono>
#include "LoudDog.h"
using namespace std;

void showBitwise();
void showUnsigned();
void showContinue();
void showDefaultParameters();
void showInheritance();
void showStringStream();
void showLambda();
void showThreads();

int main() {
    cout << "Nifty C++ Tricks" << endl;
    int choice;
    while (choice != 9) {
        cout << endl;
        cout << "1) bitwise and/or" << endl;
        cout << "2) short, long, unsigned" << endl;
        cout << "3) continue" << endl;
        cout << "4) default parameters" << endl;
        cout << "5) inheritance" << endl;
        cout << "6) string stream" << endl;
        cout << "7) lambda functions" << endl;
        cout << "8) threads" << endl;
        cout << "9) QUIT" << endl;

        choice = -1;
        while (choice < 1 || choice > 9) {
            cout << "Enter your choice: ";
            cin >> choice;
        }
        cin.ignore();
        cout << endl;
        if (choice == 1)
            showBitwise();
        else if (choice == 2)
            showUnsigned();
        else if (choice == 3)
            showContinue();
        else if (choice == 4)
            showDefaultParameters();
        else if (choice == 5)
            showInheritance();
        else if (choice == 6)
            showStringStream();
        else if (choice == 7)
            showLambda();
        else if (choice == 8)
            showThreads();
        else // if (choice == 9)
            break;
    }
    cout << "Have a nice day!" << endl;
    return 0;
}

void showBitwise() {
    int x = 25; // 11001 in binary
    int y = 20; // 10100 in binary
    cout << "25 bitwise and 20 is " << (x & y) << endl;
    cout << "25 bitwise or 20 IS " << (x | y) << endl;
}
void showUnsigned() {
    int a = 27;
    short b = 27;
    long c = 27;
    unsigned int d = 27;
    unsigned short e = 27;
    unsigned long f = 27;

    cout << "a is " << sizeof(a) << " bytes." << endl;
    cout << "b is " << sizeof(b) << " bytes." << endl;
    cout << "c is " << sizeof(c) << " bytes." << endl;
    cout << "d is " << sizeof(d) << " bytes." << endl;
    cout << "e is " << sizeof(e) << " bytes." << endl;
    cout << "f is " << sizeof(f) << " bytes." << endl;
    cout << endl;
    cout << "a's range is [" << numeric_limits<int>::min() << "," << numeric_limits<int>::max() << "]." << endl;
    cout << "b's range is [" << numeric_limits<short>::min() << "," << numeric_limits<short>::max() << "]." << endl;
    cout << "c's range is [" << numeric_limits<long>::min() << "," << numeric_limits<long>::max() << "]." << endl;
    cout << "d's range is [" << numeric_limits<unsigned int>::min() << "," << numeric_limits<unsigned int>::max() << "]." << endl;
    cout << "e's range is [" << numeric_limits<unsigned short>::min() << "," << numeric_limits<unsigned short>::max() << "]." << endl;
    cout << "f's range is [" << numeric_limits<unsigned long>::min() << "," << numeric_limits<unsigned long>::max() << "]." << endl;

}
void showContinue() {
    vector<int> nums;
    // 100 random numbers in the range [0,999]
    for (int i=0; i<100; i++) {
        nums.push_back(rand() % 1000);
    }

    int count7 = 0;
    int count11 = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]<100)
            continue;
        if (nums[i] % 7 == 0)
            count7++;
        if (nums[i] % 11 == 0)
            count11++;
    }
    cout << "Ignoring numbers less than 100, there are " <<
            count7 << " multiples of seven and " <<
            count11 << " multiples of eleven." << endl;
}

int count(vector<int> vec, int val = 27) {
    int counter = 0;
    for (int num : vec)
        if (num == val)
            counter++;
    return counter;
}

void showDefaultParameters() {
    vector<int> nums;
    // 1000 random numbers in the range [0,99]
    for (int i=0; i<1000; i++) {
        nums.push_back(rand() % 100);
    }
    cout << "There are " << count(nums, 50) << " 50's in the vector." << endl;
    cout << "There are " << count(nums) << " 27's in the vector." << endl;
}

void showInheritance() {
    Dog dog1("Snoopy");
    LoudDog dog2("Clifford");

    cout << dog1.getName() << " says " << dog1.speak() << "." << endl;
    cout << dog2.getName() << " says " << dog2.speak() << "." << endl;
}

void showStringStream() {
    cout << "Enter a sentence: ";
    string line;
    getline(cin, line);
    stringstream lineStream(line);
    vector<string> words;
    string word;
    while (lineStream >> word)
        words.push_back(word);

    for (int i=0; i<words.size(); i++)
        cout << i <<  ":" << words[i] << endl;
}

void printMe(int num) {
    cout << num << " ";
}
void printMeIfEven(int num) {
    if (num % 2 == 0)
        cout << num << " ";
}

int squareMe(int num) {
    return num * num;
}

void showLambda() {
    int nums[] = {2, 3, 4, 5, 7, 10};
    vector<int> vec(begin(nums), end(nums));

    for_each(vec.begin(), vec.end(), printMe);
    cout << endl;

    for_each(vec.begin(), vec.end(), printMeIfEven);
    cout << endl;

    vector<int> result;
    transform(vec.begin(), vec.end(), back_inserter(result), squareMe);

    for_each(result.begin(), result.end(), printMe);
    cout << endl;

    vector<int> anotherResult;
    transform(vec.begin(), vec.end(), back_inserter(anotherResult), [](int num) {return 2*num;});

    for_each(anotherResult.begin(), anotherResult.end(), printMe);
    cout << endl;
}
void doSomethingWithEvens() {
    vector<int> evens;
    for (int i=2; i<=20; i+=2)
        evens.push_back(i);
    for (int num : evens) {
        cout << num << "...";
        chrono::milliseconds pauseTime(rand()%10);
        this_thread::sleep_for(pauseTime);
    }
}

void doSomethingWithOdds() {
    vector<int> odds;
    for (int i=1; i<=19; i+=2)
        odds.push_back(i);
    for (int num : odds) {
        cout << num << "...";
        chrono::milliseconds pauseTime(rand()%10);
        this_thread::sleep_for(pauseTime);
    }
}

void showThreads() {
    thread first(doSomethingWithEvens);
    thread second(doSomethingWithOdds);

    first.join();
    second.join();
    cout << endl;
}
