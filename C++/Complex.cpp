#include <iostream>
using namespace std;

// Class Template for Complex Numbers
template <class T>
class Complex {
    T real, imag;   // real and imaginary parts

public:
    // Constructor
    Complex(T r = 0, T i = 0) {
        real = r;
        imag = i;
    }

    // Function to input complex number
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    // Function to display complex number
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }

    // Addition of two complex numbers
    Complex operator + (const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction of two complex numbers
    Complex operator - (const Complex &c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication of two complex numbers
    Complex operator * (const Complex &c) const {
        return Complex((real * c.real - imag * c.imag),
                       (real * c.imag + imag * c.real));
    }
};

int main() {
    cout << "=== Complex Number Operations ===\n";

    Complex<double> c1, c2, result;

    cout << "\nEnter first complex number:\n";
    c1.input();

    cout << "\nEnter second complex number:\n";
    c2.input();

    cout << "\nFirst number: ";
    c1.display();
    cout << "\nSecond number: ";
    c2.display();
    cout << "\n";

    // Perform operations
    result = c1 + c2;
    cout << "\nAddition: ";
    result.display();

    result = c1 - c2;
    cout << "\nSubtraction: ";
    result.display();

    result = c1 * c2;
    cout << "\nMultiplication: ";
    result.display();

    cout << "\n";

    return 0;
}
