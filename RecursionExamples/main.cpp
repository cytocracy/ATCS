#include <iostream>

using namespace std;

int fibonacci(int num){
    if(num < 2) return num;
    return fibonacci(num-1)+fibonacci(num-2);
}

int power(int base, int exp){
    if(exp == 0) return 1;
    return base*power(base, exp-1);
}

bool isPalindrome(string str){
    if(str.length() < 2) return true;
    if(str[0] != str[str.length()-1]) return false;
    return isPalindrome(str.substr(1, str.length()-2));
}

int countAs(string str){
    if(str.length() == 0) return 0;
    if(tolower(str[0]) == 'a') return 1+countAs(str.substr(1));
    return countAs(str.substr(1));
}

int c(int n, int r){
    if (r==0 || n==r) return 1;
    return c(n-1, r-1) + c(n-1, r);
}

string numStars(int num){
    if(num == 0) return "";
    return "*"+numStars(num-1);
}

void moveTower(int numDisks, char source, char dest, char temp){
    if (numDisks == 0) return;
    moveTower(numDisks-1, source, temp, dest);
    cout << numStars(numDisks) << " from " << source << " to " << dest << endl;
    moveTower(numDisks-1, temp, dest, source);

}


int main() {
    cout << "Hello, Recursion!" << endl;
    cout << fibonacci(7) << endl;
    cout << power(3, 4) << endl;
    if(isPalindrome("racecar")) cout << "That's a palindrome!" << endl;
    cout << countAs("Aarav Chandrasekar") << endl;
    cout << c(8,5) << endl;
    moveTower(5, 'A', 'C', 'B');
    return 0;
}
