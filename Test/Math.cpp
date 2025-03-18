#include <iostream>
using namespace std;
class Math1 {
public:
    int Add(int a, int b) {
        return a + b;
    }

    int Sub(int a, int b) {
        return a - b;
    }

    // Example implementation for area of a rectangle
    virtual double CalArea() const {
        int length = 5;
        int width = 3;
        return length * width;
    }
};

class Math2 {
public:
    int Mul(int a, int b) {
        return a * b;
    }

    double Div(int a, int b) {
        if (b == 0) {
            std::cerr << "Cannot divide by zero" << std::endl;
            return 0; // Handle error as needed
        }
        return static_cast<double>(a) / b;
    }

    // Example implementation for area of a circle
    virtual double CalArea() const {
        double radius = 3;
        return 3.14 * radius * radius;
    }
};

class Calculator : public Math1, public Math2 {
public:
    // Change return type to double to match the return types of the parent classes
    double CalArea() const {
        int area1 = Math1::CalArea(); // Call CalArea from Math1
        double area2 = Math2::CalArea(); // Call CalArea from Math2
        std::cout << "Area from Math1 (Rectangle): " << area1 << std::endl;
        std::cout << "Area from Math2 (Circle): " << area2 << std::endl;
        return area1 + area2; // Return combined area if needed
    }
};

int main() {
    Calculator calc;

    std::cout << "Addition: " << calc.Add(5, 3) << std::endl;
    std::cout << "Subtraction: " << calc.Sub(5, 3) << std::endl;
    std::cout << "Multiplication: " << calc.Mul(5, 3) << std::endl;
    std::cout << "Division: " << calc.Div(5, 0) << std::endl; // Division by zero case

    calc.CalArea(); // Call CalArea from both Math1 and Math2

    return 0;
}
