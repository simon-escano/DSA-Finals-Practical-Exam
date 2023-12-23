#include <iostream>
#include <string>
#include "arraystack.h"
using namespace std;

bool is_palindrome(string str){
    Stack* stack = new ArrayStack();
    for (char c : str) {
        stack->push(c);
    }
    for (char c : str) {
        if (c != stack->top()) {
            return false;
        }
        stack->pop();
    }
    return true;
}

int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;
    if(is_palindrome(str)) {
        cout << "The string is a palindrome!" << endl;
    } else {
        cout << "The string is not a palindrome!" << endl;
    }
    return 0;
}