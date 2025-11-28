#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void levelOrder(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main() {
    // Create BST manually
    Node* root = new Node(15);
    root->left = new Node(6);
    root->right = new Node(18);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(17);
    root->right->right = new Node(20);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right->right = new Node(13);
    root->left->right->right->left = new Node(9);

    cout << "Level Order Traversal: ";
    levelOrder(root);
    return 0;
}