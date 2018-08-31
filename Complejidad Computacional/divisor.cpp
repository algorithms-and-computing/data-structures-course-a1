#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n, root, count=0;
    cin >> n;

    root = sqrt(n);
    for(int i=1; i<=root; i++)
       if(n%i == 0) count+=2;

    if(n/root == root) count--;

    cout << root << endl;
    cout << count;

    return 0;
}
