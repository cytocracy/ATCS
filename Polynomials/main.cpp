#include <iostream>

using namespace std;


int main() {
    cout << "hi";
    Poly p(3,7);
    Poly q(2,5);
    p.add(q);
    string output = p.tostring();
    cout << output << endl;
    p.multiply(2);
    cout << p.tostring() << endl;
    cout << p.eval(3) << endl;
    return 0;
}