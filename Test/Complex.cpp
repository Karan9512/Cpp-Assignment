#include <iostream>

class Complex {
private:
    int real;
    int imag;

public:
    // Constructor
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overload postfix ++ (c1++)
    Complex operator++(int) {
        Complex temp = *this; // Store the current value
        real++; // Increment the real part
        imag++; // Increment the imaginary part
        return temp; // Return the old value
    }

    // Overload prefix ++ (++c1)
    Complex operator++() {
        real++; // Increment the real part
        imag++; // Increment the imaginary part
        return *this; // Return the updated value
    }

    // Overload + operator (Complex + int)
    Complex operator+(int value) {
        return Complex(real + value, imag);
    }

    // Overload + operator (int + Complex)
    friend Complex operator+(int value, const Complex& c) {
        return Complex(c.real + value, c.imag);
    }

    // Overload << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

int main() {
    Complex c1(10, 20);
    
    // Postfix increment
    Complex c2 = c1++;
    std::cout << "c1 after postfix increment: " << c1 << std::endl; // c1 should be (11, 21)
    std::cout << "c2 (old value of c1): " << c2 << std::endl; // c2 should be (10, 20)

    // Prefix increment
    Complex c3 = ++c1;
    std::cout << "c1 after prefix increment: " << c1 << std::endl; // c1 should be (12, 22)
    std::cout << "c3 (new value of c1): " << c3 << std::endl; // c3 should be (12, 22)

    // Adding Complex and integer
    Complex c4 = c1 + 5;
    std::cout << "c4 (c1 + 5): " << c4 << std::endl; // c4 should be (17, 22)

    // Adding integer and Complex
    Complex c5 = 5 + c1;
    std::cout << "c5 (5 + c1): " << c5 << std::endl; // c5 should be (17, 22)

    return 0;
}
