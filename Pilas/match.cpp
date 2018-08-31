#include <iostream>
#include <string.h>

using namespace std;

char stack[10000];
int itop=-1;

void push(char c) {
    stack[++itop] = c;
}

char top() {
    return stack[itop];
}

void pop() {
    itop--;
}

int empty() {
    return itop < 0 ? 1 : 0;
}

int main() {
    string phrase;
    int wrong=0;

    cin >> phrase;
    for(int i=0; i<phrase.length(); i++) {
        if(phrase[i] == '{') push('}');
        if(phrase[i] == '(') push(')');

        if(phrase[i] == '}' && (empty() || top() == ')'))
            wrong = 1;
        else pop();

        if(phrase[i] == ')' && (empty() || top() == '}'))
            wrong = 1;
        else pop();
    }

    if(wrong || !empty()) cout << "error";
    else cout << "ok";

    return 0;
}
