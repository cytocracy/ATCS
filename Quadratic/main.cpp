#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<double> quadratic(int a, int b, int c);

int main()
{
    vector<double> answers = quadratic(1, 7, 12);
    double answer1 = answers[0];
    double answer2 = answers[1];
    cout << "Answers: " << answer1 << " " << answer2 << endl;
    return 0;
}

vector<double> quadratic(int a, int b, int c)
{
    vector<double> x;

    double num1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a) * -1;
    double num2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a) * -1;

    x.push_back(num1);
    x.push_back(num2);

    return x;
}