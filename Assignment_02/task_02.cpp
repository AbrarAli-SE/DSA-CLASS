//Design a class Line that implements a line, which is represented by the formula y = ax + b.Your class should store a and b as double member variables.Write a member function intersect(ℓ) that returns the x coordinate at which this line intersects line ℓ. If the two lines are parallel, then your function should throw an exception Parallel. Write a C++ program that creates a number of Line objects and tests each pair for intersection. Your program should print an appropriate error message for parallel lines
#include <iostream>
using namespace std;

class Line
{
private:
    double a, b;
public:
    Line(double a, double b){
        this->a=a;
        this->b=b;
    }

    bool intersect(const Line &other, double &x) const
    {
        if (this->a == other.a)
        {
            return false; // Lines are parallel
        }
        x = (other.b - this->b) / (this->a - other.a);
        return true; // Intersection found
    }
};

int main()
{
    Line line1(1, 2);
    Line line2(2, 3);
    Line line3(1, 5);
    Line line4(3, 1);

    Line lines[] = {line1, line2, line3, line4};

    // Test each pair for intersection
    for (int i = 0; i < 4; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            double x;
            if (lines[i].intersect(lines[j], x))
            {
                cout << "\tIntersection of line " << i+1 << " and line " << j+1 << " is at x = " << x << endl;
            }
            else
            {
                cout << "\tLine " << i+1 << " and line " << j+1 << " are parallel" << endl;
            }
        }
    }

    return 0;
}
