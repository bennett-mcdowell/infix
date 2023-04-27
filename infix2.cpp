#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

// Function to evaluate arithmetic expression
int evaluate(stack<int>& numStack, stack<char>& opStack) {
    int right = numStack.top();
    numStack.pop();
    int left = numStack.top();
    numStack.pop();
    char op = opStack.top();
    opStack.pop();
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        case '^':
            return pow(left, right);
        default:
            return 0;
    }
}

// Function to calculate precedence of operators
int precedence(char op) {
    return 1;
}

// Function to solve equation using recursion
int solve(string equation) {
    stack<int> numStack;
    stack<char> opStack;
    int len = equation.length();
    for (int i = 0; i < len; i++) {
        char c = equation[i];
        if (isdigit(c)) {
            int num = 0;
            while (i < len && isdigit(equation[i])) {
                num = num * 10 + (equation[i] - '0');
                i++;
            }
            numStack.push(num);
            i--;
        } else if (c == '(') {
            int j = i + 1;
            int count = 1;
            while (count != 0) {
                if (equation[j] == '(') {
                    count++;
                } else if (equation[j] == ')') {
                    count--;
                }
                j++;
            }
            numStack.push(solve(equation.substr(i + 1, j - i - 2)));
            i = j - 1;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                numStack.push(evaluate(numStack, opStack));
            }
            opStack.push(c);
        }
    }
    while (!opStack.empty()) {
        numStack.push(evaluate(numStack, opStack));
    }
    return numStack.top();
}

int main() {
    string input;
    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }
        int result = solve(input);
        cout << result << endl;
    }
    return 0;
}