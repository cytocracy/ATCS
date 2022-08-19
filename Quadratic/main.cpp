#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<double> quadratic(int a, int b, int c);

int main()
{
    cout << endl
         << "Enter int a: ";
    int a, b, c;
    cin >> a;
    cin.ignore();

    cout << "int b: ";
    cin >> b;
    cin.ignore();

    cout << "int c: ";
    cin >> c;
    cin.ignore();

    vector<double> answers = quadratic(a, b, c);
    if (answers.size() == 0)
    {
        cout << endl
             << "None or non-real solutions" << endl;
        return 0;
    }
    double answer1 = answers[0];
    double answer2 = answers[1];
    cout << endl
         << "Answers: " << answer1 << ", " << answer2 << endl;
    return 0;
}

vector<double> quadratic(int a, int b, int c)
{
    vector<double> x;

    if (b * b - 4 * a * c < 0)
        return x;

    double num1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a) * -1;
    double num2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a) * -1;

    x.push_back(num1);
    x.push_back(num2);

    return x;
}