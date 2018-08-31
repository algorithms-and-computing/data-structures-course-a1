#include <iostream>

using namespace std;

int queue[10], start=0, last=0;

void push(int num) {
    queue[last++] = num;
}

int front() {
    return queue[start];
}

void pop() {
    start++;
}

int main() {
    int n, type, people, seats=0;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> type >> people;
        if(type==1) push(people);
        else {
            seats += people;
            while(front() <= seats) {
                cout << start << ' ';
                seats -= front();
                pop();
            }
        }
    }

    return 0;
}
