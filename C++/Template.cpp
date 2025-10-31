#include <iostream>
using namespace std;

// Class Template
template <class T>
class Calculator {
    T num1, num2;
public:
    Calculator(T n1, T n2) {
        num1 = n1;
        num2 = n2;
    }

    void displayResults() {
        cout << "Numbers: " << num1 << " and " << num2 << endl;
        cout << "Addition: " << num1 + num2 << endl;
        cout << "Subtraction: " << num1 - num2 << endl;
        cout << "Multiplication: " << num1 * num2 << endl;
        cout << "Division: " << num1 / num2 << endl;
    }
};

int main() {
    Calculator<int> intCalc(10, 5);
    Calculator<double> doubleCalc(7.5, 2.5);

    cout << "Integer results:\n";
    intCalc.displayResults();

    cout << "\nDouble results:\n";
    doubleCalc.displayResults();

    return 0;
}
