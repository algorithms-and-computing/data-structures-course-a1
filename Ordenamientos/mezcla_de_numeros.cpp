#include <iostream>

using namespace std;

int arrN[1000];
int arrM[1000];
int arrR[2000];

int main() {
    int n, m, i, in=0, im=0;

    cin >> n >> m;
    for(i=0;i<n;i++) cin >> arrN[i];
    for(i=0;i<m;i++) cin >> arrM[i];

    for(i=0;i<n+m;i++){
        if(im == m || (in < n && arrN[in] < arrM[im])){
            arrR[i] = arrN[in++];
        }
        else {
            arrR[i] = arrM[im++];
        }
    }

    i=0;
    while(im < m && in < n){
        if(arrN[in] < arrM[im]){
            arrR[i++] = arrN[in++];
        }
        else {
            arrR[i++] = arrM[im++];
        }
    }
    while(im < m) arrR[i++] = arrM[im++];
    while(in < n) arrR[i++] = arrN[in++];

    return 0;
}
