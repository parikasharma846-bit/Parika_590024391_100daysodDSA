#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int countLeafNodes(Node* root) {
    if (root == NULL)
        return 0;
    
    if (root->left == NULL && root->right == NULL)
        return 1;
    
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}