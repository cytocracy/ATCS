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
    for (Term t : other.terms){
        add(t);
    }
}

void Poly::multiply(double c) {
    for (int i=0; i<terms.size(); i++) {
        terms[i].coeff *= c;
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

void Poly::add(Poly::Term term)
{
    if (term.exp > terms[0].exp)
        terms.insert(terms.begin(), term);
    else
    {
        for (int i = 0; i < terms.size(); i++)
        {
            if (terms[i].exp < term.exp)
            {
                terms.insert(terms.begin() + i, term);
                return;
            } else if (terms[i].exp == term.exp){
                terms[i].coeff += term.coeff;
                return;
            }
        }
        terms.push_back(term);
    }
}

const Poly &Poly::operator+=(const Poly &rhs){
    add(rhs);
    return *this;
}