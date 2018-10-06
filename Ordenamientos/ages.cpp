/* Problem Description
 *
 * Given the ages of n people, calculate how many people
 * are in a given age range. (You will need to do this many times).
 *
 * Input:
 *  0 < n < 10^8, the number of people.
 *  0 < q < 10^9, amount of queries to calculate amount of people in a range [min, max]
 *  q lines, with a pair of min and max age values, separated by blank:
 *    0 <= min_age <= 110
 *    min_age <= max_age <= 110
 *
 * Output:
 *  q lines with the amount of people in the given range.
 * 
 **/

#include <iostream>

using namespace std;

int main(){
    int n, queries, min_age, max_age, people=0;
    cin >> n;

    int ages_count[110], age;
    for(int i = 0; i < n; i++) {
        cin >> age;
        ages_count[age]++;
    }

    cin >> queries;
    for(int i = 0; i < queries; i++) {
        cin >> min_age >> max_age;

        people = 0;
        for(age = min_age; age <= max_age; age++) people += ages_count[age];

        cout << people << ' ';
    }

    return 0;
}
