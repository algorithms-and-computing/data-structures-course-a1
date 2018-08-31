#include <iostream>

using namespace std;

int sumDigits(int n) {
    if(!n) return 0;

    return n%10 + sumDigits(n/10);
}

int main() {
    int n;
    cin >> n;

    cout << sumDigits(n);

    return 0;
}
