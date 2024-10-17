#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

double calculate(double a, double b, char operation) {
    switch (operation) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b != 0) return a / b;
        else {
            cout << "error: division by zero!" << endl;
            exit(1);
        }
    default:
        cout << "invalid operation!" << endl;
        exit(1);
    }
}

void parseExpression(const string& expression, vector<double>& numbers, vector<char>& operations) {
    stringstream ss(expression);
    double number;
    char operation;

    ss >> number;
    numbers.push_back(number);

    while (ss >> operation) {
        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            cout << "error: invalid operation!" << endl;
            exit(1);
        }
        operations.push_back(operation);

        ss >> number;
        numbers.push_back(number);
    }
}

int main() {
    string expression;

    cout << "enter the expression: ";
    cin >> expression;

    vector<double> numbers;
    vector<char> operations;

    parseExpression(expression, numbers, operations);

    vector<double> new_numbers;
    vector<char> new_operations;

    new_numbers.push_back(numbers[0]);

    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == '*' || operations[i] == '/') {
            double result = calculate(new_numbers.back(), numbers[i + 1], operations[i]);
            new_numbers.back() = result;
        }
        else {
            new_numbers.push_back(numbers[i + 1]);
            new_operations.push_back(operations[i]);
        }
    }

    double result = new_numbers[0];
    for (int i = 0; i < new_operations.size(); ++i) {
        result = calculate(result, new_numbers[i + 1], new_operations[i]);
    }

    cout << "final result: " << result << endl;

    return 0;
}