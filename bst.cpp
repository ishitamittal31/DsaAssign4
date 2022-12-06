// ishita mittal 
//19105121

// 1. Take an array of numbers.
// 2. Use it to construct a Binary Search Tree (BST).
// 3. Write separate functions to insert a node in BST.
// 4. Write separate functions to delete a node from BST.


#include <bits/stdc++.h>
template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

BinaryTreeNode<int>* constructTree(int *input, int n) {
    if(n<=0){return NULL;}
    int m=((n-1)/2);
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(input[m]);
    root->left=constructTree(input, m);
    root->right=constructTree(input+m+1, n-1-m);
    return root;
}

BinaryTreeNode<int>* insertNode(BinaryTreeNode<int>* node, int key)
{
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(key);
    if (node == NULL)
        return newNode;
 
    if (key < node->data)
        node->left = insertNode(node->left, key);
    else
        node->right = insertNode(node->right, key);
 
    return node;
}
 
BinaryTreeNode<int>* minValueNode(BinaryTreeNode<int>* node)
{
    BinaryTreeNode<int>* current = node;

    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key)
{
    // base case
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    else {
        if (root->left == NULL and root->right == NULL)
            return NULL;
 
        else if (root->left == NULL) {
            BinaryTreeNode<int>* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BinaryTreeNode<int>* temp = root->left;
            free(root);
            return temp;
        }
 
        BinaryTreeNode<int>* temp = minValueNode(root->right);
 
        root->data = temp->data;
 
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
 
using namespace std;
int main() {
    int size;
    cin >> size;
    int* input = new int[size];
    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    BinaryTreeNode<int>* newNode = insertNode(root, 5);
    BinaryTreeNode<int>* deletingNode = deleteNode(root, 5);
    delete[] input;
}