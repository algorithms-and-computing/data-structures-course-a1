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
    int n;
    cin >> n;

    while(n>0) {
        push(n&1);  // n % 2
        n >>= 1;    // n /= 2   (n = n >> 1)
    }

    while(!empty()) {
        cout << top();
        pop();
    }

    return 0;
}
