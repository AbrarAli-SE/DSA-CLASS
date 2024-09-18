#include <iostream>
using namespace std;

void testFunction1()
{
    while (false)
    {
        // Unreachable code because of false while condition
        cout << "\nUseless while loop" << endl;
    }
}

void testFunction2()
{
    if (false)
    {
        // Unreachable code because false condition in if statement
        cout << "\nThis if block will never run" << endl;
    }
}

void testFunction3()
{
    return; // This return will terminate the function

    // Unreachable code after return statement
    cout << "\nThis code will never be executed" << endl;
}

int main()
{
    testFunction1();
    testFunction2();
    testFunction3();
    //the compiler did't warn me the useless function that i call in the main 

    return 0;
}
