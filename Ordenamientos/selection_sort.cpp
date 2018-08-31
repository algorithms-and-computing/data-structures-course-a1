#include <iostream>

using namespace std;

int arr[1000000];

int main() {
    int n, menor, i, j, aux;

    cin >> n;
    for(i=0;i<n;i++) cin >> arr[i];

    for(i=0;i<n;i++){
        menor = i;
        for(j=i;j<n;j++){
            if(arr[menor] > arr[j]) {
                menor = j;
            }
        }
        aux = arr[i];
        arr[i] = arr[menor];
        arr[menor] = aux;
    }

    for(i=0;i<n;i++) cout << arr[i] << ' ';

    return 0;
}
