#include <iostream>

using namespace std;

int stack[10], itop=-1;

void push(int num) {
    stack[++itop] = num;
}

int top() {
    return stack[itop];
}

void pop() {
    itop--;
}

int empty() {
    return itop < 0 ? 1 : 0;
}

int main() {
    cout << empty();
    push(1);
    cout << empty();
    return 0;
}
