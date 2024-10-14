#include <iostream>
#include <vector>

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
        return 0;
    }
}

int main() {
    int num_operations;

    cout << "enter the number of operations: ";
    cin >> num_operations;

    vector<char> operations(num_operations);
    vector<double> numbers(num_operations + 1);

    cout << "enter the operations (+, -, *, /):\n";
    for (int i = 0; i < num_operations; ++i) {
        cout << "operation " << i + 1 << ": ";
        cin >> operations[i];
        if (operations[i] != '+' && operations[i] != '-' && operations[i] != '*' && operations[i] != '/') {
            cout << "error: invalid operation!" << endl;
            return 1;
        }
    }

    cout << "enter the numbers:\n";
    for (int i = 0; i <= num_operations; ++i) {
        cout << "number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    vector<double> new_numbers;
    vector<char> new_operations;

    new_numbers.push_back(numbers[0]);

    for (int i = 0; i < num_operations; ++i) {
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