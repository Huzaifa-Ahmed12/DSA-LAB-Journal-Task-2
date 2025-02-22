//Exerice 2.1 (a)

//#include<iostream>
//#include"stack.h"
//using namespace std;
//int main() {
//	Stack s;
//	int item;
//	for (int i = 0; i < 20; i++) {
//		s.Push(i);
//	
//	}
//	cout<<s.Peek();
//
//	return 0;
//}

//Exercise 2.1 (b)
//
//#include<iostream>
//#include<string>
//#include"stack.h"
//using namespace std;
//string reverseString(string str) {
//	Stack s;
//	for (char c : str) {
//		s.Push(c);
//	}
//	string reverseStr;
//	char temp;
//	while (!s.isEmpty()) {
//		s.Pop(temp);
//		reverseStr += temp;
//	}
//	return reverseStr;
//}
//int main() {
//	string input;
//	cout << "Enter a string: ";
//	getline(cin, input);
//	string reversed = reverseString(input);
//	cout << "The reversed string is: " << reversed << endl;
//	return 0;
//}


// Implementation of Stack using Dynamic Array and Class Template

//#include<iostream>
//#include "stack.h"
//using namespace std;
//int main() {
//	Stack<int> IntStack;
//	Stack<float> FloatStack;
//	int data;
//	float val;
//
//	IntStack.Push(23);
//	FloatStack.Push(22.7);
//
//	IntStack.Pop(data);
//	cout << data << endl;
//
//	FloatStack.Pop(val);
//	cout << val << endl;
//	return 0;
//}


// Exercise 2.2

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to check if parentheses are balanced
bool isValidParentheses(const string& expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) { // Operand
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        }
        else { // Operator
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int
        }
        else { // Operator
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
            case '+': s.push(val1 + val2); break;
            case '-': s.push(val1 - val2); break;
            case '*': s.push(val1 * val2); break;
            case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string expression;
    cout << "Enter a parenthesized expression: ";
    cin >> expression;
    cout << "Validity: " << (isValidParentheses(expression) ? "Valid" : "Invalid") << endl;

    cout << "\nEnter an infix expression: ";
    cin >> expression;
    string postfix = infixToPostfix(expression);
    cout << "Postfix Expression: " << postfix << endl;

    cout << "\nEnter a postfix expression: ";
    cin >> expression;
    cout << "Postfix Evaluation: " << evaluatePostfix(expression) << endl;

    return 0;
}