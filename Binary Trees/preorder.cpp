#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Tree {
  Tree (const T &v) : value(v), left(nullptr), right(nullptr) {};

  T value;
  Tree *left, *right;
};

template <typename T>
Tree<T> * readTree() {
  T value;
  cout << "Node value: ";
  cin >> value;

  Tree<T> *node = new Tree<T>(value);

  char has_child;
  cout << "Has "<< value << " left child? (y/n) ";
  cin >> has_child;
  if(has_child == 'y') node->left = readTree<T>();

  cout << "Has "<< value << " right child? (y/n) ";
  cin >> has_child;
  if(has_child == 'y') node->right = readTree<T>();

  return node;
}

template <typename T>
vector<T> preOrder(Tree<T> *node) {
  vector<T> result, left, right;

  result.push_back(node->value);

  if(node->left) {
    left = preOrder(node->left);
    result.insert(result.begin() + 1, left.begin(), left.end());
  }

  if(node->right) {
    right = preOrder(node->right);
    result.insert(result.begin() + result.size(), right.begin(), right.end());
  }


  return result;
}

int main() {
  Tree<int> *root;
  root = readTree<int>();

  vector<int> result = preOrder<int>(root);

  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << ' ';
  }

  return 0;
}