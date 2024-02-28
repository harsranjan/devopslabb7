#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> operandStack;

    for (char ch : expression) {
        if (isdigit(ch)) {
            // If the character is a digit, convert it to an integer and push onto the stack
            operandStack.push(ch - '0');
        } else {
            // If the character is an operator, pop two operands from the stack,
            // perform the operation, and push the result back onto the stack.
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (ch) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                default:
                    cerr << "Invalid operator: " << ch << endl;
                    return -1; // Error
            }
        }
    }

    // The result of the expression will be at the top of the stack
    return operandStack.top();
}

int main() {
    string expression;
    cout << "Enter a postfix expression: ";
    getline(cin, expression);

    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;

    return 0;
}
