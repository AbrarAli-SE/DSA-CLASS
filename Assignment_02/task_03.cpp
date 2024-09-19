//Write a C++ class that is derived from the Progression class to produce a progression where each value is the absolute value of the difference between the previous two values.You should include a default constructor that starts with 2 and 200 as the first two values and a parametric constructor that starts with a specified pair of numbers as the first two values.
#include<iostream> 
using namespace std;

class Progression
{
protected:
    long long current; // The current value of the progression

public:
    Progression(long long start = 0) : current(start) {}

    // Function to return the next value of the progression
    virtual long long nextValue()
    {
        return ++current;
    }

    // Function to print the progression (n values)
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
class AbsDiffProgression : public Progression
{
private:
    long long prev; // Previous value in the progression

    // Function to manually calculate the absolute value of a number
    long long abs(long long x)
    {
        return (x < 0) ? -x : x;
    }

public:
    // Default constructor: starts with 2 and 200
    AbsDiffProgression() : Progression(200), prev(2) {}

    // Parametric constructor: starts with the provided pair of numbers
    AbsDiffProgression(long long first, long long second) : Progression(second), prev(first) {}

    // Overriding the nextValue() function to implement the progression logic
    virtual long long nextValue() override
    {
        long long temp = current;
        current = abs(current - prev); // Manually calculate the absolute difference
        prev = temp;                   // Update the previous value
        return current;
    }
};
int main()
{
    // Testing the default constructor
    cout << "Default Progression (starting with 2 and 200):" << endl;
    AbsDiffProgression defaultProg;
    defaultProg.printProgression(10); // Print the first 10 terms of the progression

    // Testing the parametric constructor
    cout << "Custom Progression (starting with 5 and 15):" << endl;
    AbsDiffProgression customProg(5, 15);
    customProg.printProgression(10); // Print the first 10 terms of the progression

    return 0;
}
