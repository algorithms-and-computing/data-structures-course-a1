#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getFields(const string& version) {
  vector<int> fields;
  string buff = "";

  for (auto c:version) {
    if(c != '.') buff+=c; else
    if(c == '.' && buff != "") { fields.push_back(stoi(buff)); buff = "";}
  }
  if(buff != "") fields.push_back(stoi(buff));

  return fields;
}

int main() {
  string v1, v2;
  cin >> v1 >> v2;

  vector<int> f1 = getFields(v1), f2 = getFields(v2);
  vector<int>::iterator it1 = f1.begin(), it2 = f2.begin();
  
  while(it1 != f1.end() && it2 != f2.end() && *it1 >= *it2) { it1++; it2++; }
  if(it1 == f1.end() || *it1 > *it2) cout << 1;
  else cout << -1;

  return 0;
}