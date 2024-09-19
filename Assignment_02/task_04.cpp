// Write a C++ class that is derived from the Progression class to produce a progression where each value is the square root of the previous value.(Note that you can no longer represent each value with an integer.)You should include a default constructor that starts with 65, 536 as the first value and a parametric constructor that starts with a specified(double) number as the first value.
#include <iostream>
#include <cmath>
using namespace std;

class Progression
{
protected:
    double current;

public:
    Progression(double start = 0.0) : current(start) {}

    virtual double nextValue()
    {
        return ++current;
    }

    void printProgression(int n)
    {
        cout << current;
        for (int i = 1; i < n; i++)
        {
            cout << " " << nextValue();
        }
        cout << endl;
    }
};

class SqrtProgression : public Progression
{
public:
    SqrtProgression() : Progression(65536.0) {}

    SqrtProgression(double start) : Progression(start) {}

    virtual double nextValue() override
    {
        current = sqrt(current);
        return current;
    }
};

int main()
{
    int numTerms;
    cout << "\n\tEnter the number of terms you want to print: ";
    cin >> numTerms;

    // Testing the default constructor
    cout << "\n\tDefault Square Root Progression (starting with 65,536):" << endl;
    SqrtProgression defaultProg;
    defaultProg.printProgression(numTerms); 

    int userValue;
    cout << "\n\tEnter a value for custom progression: ";
    cin >> userValue;

    // Testing the parametric constructor
    cout << "\n\tCustom Square Root Progression (starting with "<<userValue<<"): " << endl;
    SqrtProgression customProg(userValue);
    customProg.printProgression(numTerms); 
    return 0;
}