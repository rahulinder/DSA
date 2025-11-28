#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
bool isBST(Node* root, int minVal, int maxVal) {
    if (root == nullptr)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main() {
    Node* root = new Node(15);
    root->left = new Node(6);
    root->right = new Node(18);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "It is a BST\n";
    else
        cout << "Not a BST\n";
}