#include <iostream>

class Box {
private:
    double height;
    double width;

public:
    // Constructor
    Box(double h, double w) : height(h), width(w) {}

    // Method to calculate the area of the box
    double area() const {
        return height * width;
    }

    // Overload the > operator
    bool operator>(const Box& other) const {
        return this->area() > other.area();
    }

    // Overload the < operator
    bool operator<(const Box& other) const {
        return this->area() < other.area();
    }
};

int main() {
    Box b1(2, 5); // Box with height 2 and width 5
    Box b2(3, 5); // Box with height 3 and width 5

    // Compare the two boxes
    if (b1 > b2) {
        std::cout << "Box b1 is larger than Box b2." << std::endl;
    } else if (b1 < b2) {
        std::cout << "Box b1 is smaller than Box b2." << std::endl;
    } else {
        std::cout << "Box b1 is equal to Box b2." << std::endl;
    }

    return 0;
}
