#include <bits/stdtr1c++.h>
using namespace std;
class TreeNode
{
public:
  int data;
  TreeNode *leftChild;
  TreeNode *rightChild;
  TreeNode(int v)
  {
    this->data = v;
    this->leftChild = NULL;
    this->rightChild = NULL;
  }
};
void printSpace(int level)
{
  for (int i = 0; i < level; i++)
  {
    cout << " ";
  }
  cout << endl;
}

void printTree(TreeNode *tree, int level)
{
  if (tree == NULL)
  {
    return;
  }
  if (tree->leftChild == NULL && tree->rightChild == NULL)
  {
    cout << tree->data << endl;
    return;
  }
  else
  {
    cout << endl;
    printSpace(level);
    cout << "Root : " << tree->data << endl;
  }
  if (tree->leftChild)
  {
    printSpace(level);
    cout << "Left: ";
    printTree(tree->leftChild, level + 1);
  }
  if (tree->rightChild)
  {
    printSpace(level);
    cout << "right: ";
    printTree(tree->rightChild, level + 1);
  }
}

void levleOrderTraverse(TreeNode *root)
{
  if (root == NULL)
    return;
  queue<TreeNode *> q;
  stack<int> s;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    TreeNode *curr = q.front();

    q.pop();
    if (curr != NULL)
    {
      cout << curr->data << " ";
      if (curr->leftChild)
        q.push(curr->leftChild);
      if (curr->rightChild)
        q.push(curr->rightChild);
    }
    else
    {
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
  }
}

void levelOrderReverse(TreeNode *root)
{
  if (root == NULL)
    return;
  queue<TreeNode *> q;
  stack<int>s;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *curr = q.front();
    q.pop();
    if (curr != NULL)
    {
      s.push(curr->data);
       if (curr->rightChild)
        q.push(curr->rightChild);
      if (curr->leftChild)
        q.push(curr->leftChild);
     
    }


  }
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
}



void reverseOrderTraverse(TreeNode *root)
{
  if (root == NULL)
    return;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {

    TreeNode *curr = q.front();
    q.pop();
    if (curr != NULL)
    {
      cout << curr->data << " ";
      if (curr->rightChild)
        q.push(curr->rightChild);
      if (curr->leftChild)
        q.push(curr->leftChild);
    }
  }
}

void avgTraversing(TreeNode *root)
{
  if (root == NULL)
    return;
  queue<TreeNode *> q;

  q.push(root);
  while (!q.empty())
  {
    double qlen = q.size(), row = 0;
    for (int i = 0; i < qlen; i++)
    {
      TreeNode *curr = q.front();
      q.pop();
      row += curr->data;
      if (curr->leftChild)
        q.push(curr->leftChild);
      if (curr->rightChild)
        q.push(curr->rightChild);
    }
    cout << fixed << setprecision(2) << row / qlen << endl;
  }
}

int main()
{
  int n;
  cin >> n;
  TreeNode *tree[n];
  for (int i = 0; i < n; i++)
  {
    tree[i] = new TreeNode(-1);
  }
  for (int i = 0; i < n; i++)
  {
    int value, left, right;
    cin >> value >> left >> right;
    tree[i]->data = value;

    if (left != -1)
    {
      tree[i]->leftChild = tree[left];
    }
    if (right != -1)
    {
      tree[i]->rightChild = tree[right];
    }
  }

  levleOrderTraverse(tree[0]);
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


9
0 10 20
10 30 40
20 5 6
30 -1 -1
40 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1


*/
