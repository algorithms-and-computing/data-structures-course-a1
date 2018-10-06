/* Problem Description
 *
 * Given two ordered arrays, perform a merge to obtain a new array with
 * all the elements in both arrays ordered. (Order: Ascending)
 *
 * Input:
 *  0 < m < 10^6, first array lenght.
 *  0 < n < 10^6, seccond array lenght.
 *  m lines, follow by n lines containing the values in each array:
 *    0 <= values <= 2^32
 *
 * Output:
 *  Result array in a single line, separated by blank.
 *
 **/

#include <iostream>

using namespace std;

int main() {
  int m, n, in=0, im=0, i;

  cin >> m >> n;
  int first_arr[m], seccond_arr[n], result[m+n];

  // Read arrays
  for(i=0; i<m; i++) cin >> first_arr[i];
  for(i=0; i<n; i++) cin >> seccond_arr[i];

  // Do the merge while both arrays have elements
  // note: we use im as iterator for first_arr, in for seccond_arr, and i for result
  i=0;
  while(im < m && in < n){
    if(first_arr[im] < seccond_arr[in]) {
      result[i++] = first_arr[im++];
    }
    else {
      result[i++] = seccond_arr[in++];
    }
  }

  // At this point one of the arrays, so, we need to insert all elements left
  // note: as one of them is empty, only one while cicle will be performed
  while(im < m) result[i++] = first_arr[im++];
  while(in < n) result[i++] = seccond_arr[in++];

  return 0;
}
