#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* arr;        
    int size;     

public:
    
    Array(int s) : size(s) {
        arr = new T[size]; 
    }

   
    ~Array() {
        delete[] arr;
    }

   
    void setElement(int index, T value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        } else {
            cout << "Index out of bounds!" << endl;
        }
    }

   
    T getElement(int index) const {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            cout << "Index out of bounds!" << endl;
            return T(); // Return default value of T
        }
    }

 
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    
    Array<int> intArray(5);
    intArray.setElement(0, 10);
    intArray.setElement(1, 20);
    intArray.setElement(2, 30);
    intArray.setElement(3, 40);
    intArray.setElement(4, 50);
    cout << "Integer Array: ";
    intArray.display();

   
    Array<float> floatArray(3);
    floatArray.setElement(0, 1.1f);
    floatArray.setElement(1, 2.2f);
    floatArray.setElement(2, 3.3f);
    cout << "Float Array: ";
    floatArray.display();


    Array<char> charArray(4);
    charArray.setElement(0, 'A');
    charArray.setElement(1, 'B');
    charArray.setElement(2, 'C');
    charArray.setElement(3, 'D');
    cout << "Character Array: ";
    charArray.display();

    return 0;
}
