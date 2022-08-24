#include "Poly.h"
#include <string>
#include <cmath>

using namespace std;

Poly::Poly() {}
Poly::Poly(double c, int e) {
    Term t;
    t.coeff = c;
    t.exp = e;
    terms.push_back(t);
}

void Poly::add(Poly other) {
    
}

void Poly::multiply(double c) {
    for (Term t: terms){
        t.coeff *= c;
    }
}
double Poly::eval(int x) const {
    double result = 0;
    for (Term t: terms){
        result += t.coeff * pow(x, t.exp);
    }
    return result;
}
string Poly::tostring() const {
    string result = "";
    for (Term t: terms)
        result += to_string(t.coeff) + "x^" + to_string(t.exp) + " + ";
    return result.substr(0, result.length() - 3);
}
Poly::~Poly() {
    //we're done
}