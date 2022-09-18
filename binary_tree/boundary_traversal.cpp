#include <bits/stdtr1c++.h>
using namespace std;
class TreeNode {
public:
  int data;
  TreeNode *leftChild;
  TreeNode *rightChild;
  TreeNode(int v) {
    this->data = v;
    this->leftChild = NULL;
    this->rightChild = NULL;
  }
};
void leftNonLeaves(TreeNode *root) {
  if (root == NULL)
    return;
  if (root->leftChild != NULL) {
    cout << root->data << " ";
    leftNonLeaves(root->leftChild);
  } else if (root->rightChild != NULL) {
    cout << root->data << " ";
    leftNonLeaves(root->rightChild);
  }
}

void leftLeaves(TreeNode *root) {
  if (root == NULL)
    return;
  if(!root->leftChild && !root->rightChild){
    cout<<root->data <<" ";
    return ;
  }
  leftLeaves(root->leftChild) ;
  leftLeaves(root->rightChild);
}

void rightNonLeaves(TreeNode *root) {
  if (root == NULL)
    return;
  if (root->rightChild) {
    cout << root->data << " ";
    rightNonLeaves(root->rightChild);
  } else if (root->leftChild) {
    cout << root->data << " ";
    rightNonLeaves(root->leftChild);
  }
}

void rightLeaves(TreeNode *root) {
  if (root == NULL)
    return;
  if(!root->leftChild && !root->rightChild){
    cout<<root->data<<" ";
    return;
  }
  rightLeaves(root->leftChild);
  rightLeaves(root->rightChild);
  
}

void boundary_tree(TreeNode *root) {
  if (root == NULL)
    return;
  cout << root->data << " ";
  // lb non leaves
  leftNonLeaves(root->leftChild);
  // lb leave
  leftLeaves(root->leftChild);
  // // rb non leaves
  rightNonLeaves(root->rightChild);
  // // rb leave
  rightLeaves(root->rightChild);
}

int main() {
  int n;
  cin >> n;
  TreeNode *tree[n];
  for (int i = 0; i < n; i++) {
    tree[i] = new TreeNode(-1);
  }
  for (int i = 0; i < n; i++) {
    int value, left, right;
    cin >> value >> left >> right;
    tree[i]->data = value;

    if (left != -1) {
      tree[i]->leftChild = tree[left];
    }
    if (right != -1) {
      tree[i]->rightChild = tree[right];
    }
  }
  boundary_tree(tree[0]);
  // printTree(tree[0], 0);

  cout << endl;
}

/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1


*/
