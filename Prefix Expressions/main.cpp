#include <iostream>
#include <string>
#include "arraystack.h"
using namespace std;

int main() {
    Stack* stack = new ArrayStack();
    int size;
    cout << "Enter number of inputs: ";
    cin >> size;
    string input[size];
    cout << "Enter expression: ";
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }
    for (int i = size - 1; i >= 0; i--) {
        int num;
        int a, b;
        switch (input[i][0]) {
            case '+':
    			a = stack->pop();
    			b = stack->pop();
    			stack->push(a + b);
    			break;
            case '-':
                a = stack->pop();
    			b = stack->pop();
    			stack->push(a - b);
    			break;
            case '*':
                a = stack->pop();
    			b = stack->pop();
    			stack->push(a * b);
    			break;
            case '/':
                a = stack->pop();
    			b = stack->pop();
    			stack->push(a / b);
    			break;
            default:
    			num = stoi(input[i]);
    			stack->push(num);
    			break;
        }
    }
    cout << "Answer is " << stack->pop() << endl;
    return 0;
}

int postfix_main() {
	Stack* stack = new ArrayStack();
    string input;
    do {
    	cout << "Enter: ";
    	cin >> input;
    	int num;
    	int a, b;
    	switch (input[0]) {
    		case '+':
    			a = stack->pop();
    			b = stack->pop();
    			stack->push(a + b);
    			break;
    		// add more cases for operations here
    		case 'x':
    			cout << "Answer is " << stack->pop() << endl;
    			break;
    		default: // number
    			num = stoi(input);
    			stack->push(num);
    			break;
		}
	} while (input != "x");
    return 0;
}