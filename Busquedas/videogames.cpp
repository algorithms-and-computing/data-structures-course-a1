#include <iostream>

using namespace std;

int main () {
  int n, k;
  cin >> n >> k;

  int store[n], pancho[k];
  for (int i = 0; i < n; ++i) cin >> store[i];
  for (int i = 0; i < k; ++i) cin >> pancho[i];

  int first, mid, last;
  for (int i = 0; i < k; ++i) {
    first = 0;
    last = n-1;
    mid = last / 2;

    while (pancho[i] != store[mid] && first <= last) {
      if (pancho[i] > store[mid]) first = mid + 1;
      else last = mid - 1;
      mid = (last + first) / 2;
    }

    if (pancho[i] == store[mid]) cout << mid << ' ';
    else cout << "-1 ";
  }
}