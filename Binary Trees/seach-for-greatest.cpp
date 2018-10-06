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

// Only for int, float, char, struct/class with overload >
template <typename T>
T findGreatest(Tree<T> *node) {
  T greatest=node->value, gleft, gright;

  if(node->left) {
    gleft = findGreatest(node->left);
    if(gleft > greatest) greatest = gleft;
  }

  if(node->right) {
    gright = findGreatest(node->right);
    if(gright > greatest) greatest = gright; 
  }

  return greatest;
}

int main() {
  Tree<char> *root;
  root = readTree<char>();

  cout << findGreatest<char>(root);

  return 0;
}