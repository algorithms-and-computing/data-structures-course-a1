#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> list;

    list.push_back(5);
    list.push_back(7);
    list.push_back(10);

    list[1] = 11;

    cout << list[1] << endl;

    list.erase(list.begin(), list.begin() + 3);

    cout << list.size() << endl;

    list.resize(100, 0);
}