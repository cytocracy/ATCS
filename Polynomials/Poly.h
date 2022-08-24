#include <vector>
#include <string>

#ifndef POLYNOMIALS_POLY_H
#define POLYNOMIALS_POLY_H

using namespace std;

class Poly {
    public:
        Poly();
        Poly(double c, int e);
        void add(Poly other);
        void multiply(double c);
        double eval(int x) const;
        string tostring() const;
        ~Poly();

        const Poly& operator += (const Poly& rhs);
    private:
        struct Term {
            double coeff;
            int exp;
        };
        vector<Term> terms;
        void add(Term term);
};

#endif //POLYNOMIALS_POLY_H