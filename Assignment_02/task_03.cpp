//Write a C++ class that is derived from the Progression class to produce a progression where each value is the absolute value of the difference between the previous two values.You should include a default constructor that starts with 2 and 200 as the first two values and a parametric constructor that starts with a specified pair of numbers as the first two values.
//progression1.cpp
#include <iostream>
using namespace std;

class Progression
{
protected:
    long first; // First value of the progression
    long cur;   // Current value of the progression

public:
    // Constructor to initialize the first value
    Progression(long f = 0) : first(f), cur(f) {}

    // Function to print the first n values of the progression
    void printProgression(int n)
    {
        cur = first;
        cout << cur;
        for (int i = 1; i < n; ++i)
        {
            cur = nextValue();
            cout << ' ' << cur;
        }
        cout << endl;
    }

    // Function to get the next value of the progression
    virtual long nextValue()
    {
        return ++cur;
    }
};

int main()
{
    Progression prog(1);
    prog.printProgression(10); // Prints the first 10 values of the progression starting from 1

    return 0;
}
