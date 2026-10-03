// making a binary tree ofc , using nodes and pointers

#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
      int data;
      Node* left;
      Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    };
};

static int index = -1; // to actually use it vlaue consistently

Node* build(vector<int> preOrder){
    index++;
    if(preOrder[index] == -1) return NULL;
    Node* root = new Node(preOrder[index]); // contains data , left = null , rigth = null
    root->left = build(preOrder);
    root->right = build(preOrder);
    return root;
};

// 1. preOrder tarversal 

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
};

// 2. inOrder traversal

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
};

// 3. postOrder traversal

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
};
int main()
{
    vector<int> preOrder = {1,2,-1,-1,3,-1,-1}; 
    Node* root = build(preOrder);
    postOrder(root);
    return 0;
}