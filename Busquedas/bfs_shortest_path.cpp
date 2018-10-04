#include <iostream>
#include <queue>

using namespace std;

struct Pos {
  int i, j, steps;

  Pos (int i, int j, int s) {
    this->i = i;
    this->j = j;
    this->steps = s;
  }
};

int map[1002][1002];
Pos start = Pos(0,0,0), goal = Pos(0,0,0);

int findGoal() {
  queue<Pos> posToVisit;
  posToVisit.push(start);

  while(!posToVisit.empty()) {
    Pos curr = posToVisit.front();
    posToVisit.pop();

    if(map[curr.i][curr.j]) continue;
    map[curr.i][curr.j] = 1;

    if(curr.i == goal.i && curr.j == goal.j) return curr.steps;
    
    Pos next = curr;
    next.steps++;
    next.i++;
    if(!map[next.i][next.j]) posToVisit.push(next);

    next = curr;
    next.steps++;
    next.i--;
    if(!map[next.i][next.j]) posToVisit.push(next);

    next = curr;
    next.steps++;
    next.j++;
    if(!map[next.i][next.j]) posToVisit.push(next);

    next = curr;
    next.steps++;
    next.j--;
    if(!map[next.i][next.j]) posToVisit.push(next);
  }

  return 0;
}

int main() {
  int i, j;
  cin >> i >> j;
  start.i = i+1;
  start.j = ++j;

  cin >> i >> j;
  goal.i = i+1;
  goal.j = j+1;

  for (int i = 0; i < 1001; ++i){
    map[i][0]++;
    map[0][i]++;
    map[i][1001]++;
    map[1001][i]++;
  }

  cout << findGoal();

  return 0;
}