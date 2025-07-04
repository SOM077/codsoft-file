#include <iostream>
using namespace std;

int main() {
    char operators;
    float num1, num2;

    cout << "Simple Calculator\n";
    
    cout << "Choose an operator (+, -, *, /): ";
    cin >> operators;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "\nCalculating...\n";

    switch(operators) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;

        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;

        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;

        case '/':
            if (num2 == 0) {
                cout << "Error: You can't divide by zero!" << endl;
            } else {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            }
            break;

        default:
            cout << " Oops! Invalid operator. Please use +, -, * or /." << endl;
    }

    cout << "\nThanks for using the calculator! " << endl;
    return 0;
}