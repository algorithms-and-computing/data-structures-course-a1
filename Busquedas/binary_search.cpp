#include <iostream>

using namespace std;

int main () {
    int n, x;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    cin >> x;

    int first=0, last=n-1, mid=n/2;
    char c;
    while(x != arr[mid] && first <= last){
        if(x > arr[mid]) {
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
        mid = (last - first) / 2 + first;
    }

    if(x == arr[mid]) cout << mid;
    else cout << "-1";

    return 0;
}
