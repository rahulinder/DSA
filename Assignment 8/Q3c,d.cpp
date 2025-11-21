#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void createnode(Node* root, int ele) {
    Node* parent = nullptr;
    Node* curr = root;
    while (curr != nullptr) {
        parent = curr;
        if (ele < curr->data)
            curr = curr->left;
        else if (ele > curr->data)
            curr = curr->right;
        else
            return;
    }
    Node* newNode = new Node(ele);
    if (ele < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

int maxDepth(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (root == nullptr)
        return 0;
    if (root->left == nullptr)
        return 1 + minDepth(root->right);
    if (root->right == nullptr)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = new Node(15);
    createnode(root, 6);
    createnode(root, 18);
    createnode(root, 3);
    createnode(root, 7);
    createnode(root, 17);
    createnode(root, 20);
    createnode(root, 2);
    createnode(root, 4);
    createnode(root, 13);
    createnode(root, 9);

    cout << "Maximum Depth of BST: " << maxDepth(root) << endl;
    cout << "Minimum Depth of BST: " << minDepth(root) << endl;

    return 0;
}
