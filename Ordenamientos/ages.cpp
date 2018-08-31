#include <iostream>

using namespace std;

int main(){
    int n, k, i, a, b, count=0;
    cin >> n;

    int arr[110], age;
    for(i=0; i<n; i++) {
        cin >> age;
        arr[age]++;
    }

    cin >> k;
    for(int h=0; h<k; h++) {
        cin >> a >> b;

        count=0;
        for(i=a; i<=b; i++) count+=arr[i];

        cout << count << ' ';
    }

    return 0;
}
