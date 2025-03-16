#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T add(const T &a, const T &b) {
    return a + b;
}

template <typename T>
T subtract(const T &a, const T &b) {
    return a - b;
}

template <typename T>
T multiply(const T &a, const T &b) {
    return a * b;
}

template <typename T>
T divide(const T &a, const T &b) {
    if (b == 0) {
        throw invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}

int main() {
   
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    Swap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    cout << "Addition: " << add(x, y) << endl;
    cout << "Subtraction: " << subtract(x, y) << endl;
    cout << "Multiplication: " << multiply(x, y) << endl;
    try {
        cout << "Division: " << divide(x, y) << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    return 0;
}
