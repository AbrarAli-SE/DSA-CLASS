// Write a C++ program that has a Polygon interface that has abstract functions, area(), and perimeter(). Implement classes for Triangle, Quadrilateral, Pentagon, Hexagon, and Octagon, which implement this interface, with the obvious meanings for the area() and perimeter() functions. Also implement classes, IsoscelesTriangle, EquilateralTriangle, Rectangle, and Square, which have the appropriate inheritance relationships. Finally, write a simple user interface that allows users to create polygons of the various types, input their geometric dimensions, and then output their area and perimeter. For extra effort, allow users to input polygons by specifying their vertex coordinates and be able to test if two such polygons are similar.
#include <iostream>
#include <cmath>
using namespace std;

class Polygon {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Polygon() {}
};

class Triangle : public Polygon {
protected:
    double a, b, c;

public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double perimeter() const override {
        return a + b + c;
    }
};

class Quadrilateral : public Polygon {
protected:
    double a, b, c, d;

public:
    Quadrilateral(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

    double perimeter() const override {
        return a + b + c + d;
    }
};

class Pentagon : public Polygon {
    double side;

public:
    Pentagon(double side) : side(side) {}

    double area() const override {
        // Formula: (1/4) * sqrt(5 * (5 + 2 * sqrt(5))) * side^2
        return 1.720477401 * side * side;  // Approximated value
    }

    double perimeter() const override {
        return 5 * side;
    }
};

class Hexagon : public Polygon {
    double side;

public:
    Hexagon(double side) : side(side) {}

    double area() const override {
        // Formula: (3 * sqrt(3) / 2) * side^2
        return 2.598076211 * side * side;  // Approximated value
    }

    double perimeter() const override {
        return 6 * side;
    }
};

class Octagon : public Polygon {
    double side;

public:
    Octagon(double side) : side(side) {}

    double area() const override {
        // Formula: 2 * (1 + sqrt(2)) * side^2
        return 4.828427125 * side * side;  // Approximated value
    }

    double perimeter() const override {
        return 8 * side;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double base, double side) : Triangle(side, side, base) {}

    double area() const override {
        double s = perimeter() / 2;
        double h = sqrt(a * a - (b / 2) * (b / 2));
        return (b * h) / 2;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side) : Triangle(side, side, side) {}

    double area() const override {
        // Formula: (sqrt(3) / 4) * side^2
        return 0.433012701 * a * a;  // Approximated value
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double width, double height) : Quadrilateral(width, width, height, height) {}

    double area() const override {
        return a * d;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
};

int main() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\nSelect a polygon type:\n";
        cout << "1. Isosceles Triangle\n";
        cout << "2. Equilateral Triangle\n";
        cout << "3. Rectangle\n";
        cout << "4. Square\n";
        cout << "5. Pentagon\n";
        cout << "6. Hexagon\n";
        cout << "7. Octagon\n";
        cout << "8. Exit\n";
        cin >> choice;

        Polygon* poly = nullptr;
        double a, b, c, d;

        switch (choice) {
            case 1:
                cout << "Enter base and side: ";
                cin >> b >> a;
                poly = new IsoscelesTriangle(b, a);
                break;
            case 2:
                cout << "Enter side length: ";
                cin >> a;
                poly = new EquilateralTriangle(a);
                break;
            case 3:
                cout << "Enter width and height: ";
                cin >> a >> d;
                poly = new Rectangle(a, d);
                break;
            case 4:
                cout << "Enter side length: ";
                cin >> a;
                poly = new Square(a);
                break;
            case 5:
                cout << "Enter side length: ";
                cin >> a;
                poly = new Pentagon(a);
                break;
            case 6:
                cout << "Enter side length: ";
                cin >> a;
                poly = new Hexagon(a);
                break;
            case 7:
                cout << "Enter side length: ";
                cin >> a;
                poly = new Octagon(a);
                break;
            case 8:
                running = false;
                continue;
            default:
                cout << "Invalid choice!\n";
                continue;
        }

        if (poly) {
            cout << "Area: " << poly->area() << endl;
            cout << "Perimeter: " << poly->perimeter() << endl;
            delete poly;
        }
    }

    return 0;
}
