#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
struct Tree {
  Tree (const T &v) : value(v), left(nullptr), right(nullptr) {};

  T value;
  Tree *left;
  Tree *right;
};

template <typename T>
Tree<T>* readTree() {
  T value;
  cout << "Node value: ";
  cin >> value;
  Tree<T> *node = new Tree<T>(value);

  int has_child;
  cout << "Has " << value << " left child? (1|0) ";
  cin >> has_child;
  if(has_child) node->left = readTree<T>();

  cout << "Has " << value << " right child? (1|0) ";
  cin >> has_child;
  if(has_child) node->right = readTree<T>();

  return node;
}

template <typename T>
vector<T> traverseTree(Tree<T> * root) {
  vector<T> result;
  queue<Tree<T> *> nodes;
  
  if(root) nodes.push(root);

  while(!nodes.empty()) {
    Tree<T> *node = nodes.front();
    nodes.pop();

    result.push_back(node->value);
    if(node->left) nodes.push(node->left);
    if(node->right) nodes.push(node->right);
  }

  return result;
}

int main() {
  Tree<int> *root = readTree<int>();
  vector<int> elements = traverseTree<int>(root);

  for (int i = 0; i < elements.size(); ++i)
    cout << elements[i] << ' ';

  return 0;
}