#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert node into BST (iterative)
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
            return; // duplicate
    }

    Node* newNode = new Node(ele);
    if (ele < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* delnode(Node* root, int ele) {
    if (root == nullptr)
        return root;

    if (ele < root->data)
        root->left = delnode(root->left, ele);
    else if (ele > root->data)
        root->right = delnode(root->right, ele);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delnode(root->right, temp->data);
        }
    }
    return root;
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

    cout << "Inorder before deletion:\n";
    inorder(root);

    root = delnode(root, 2); // deleting leaf node
    cout << "\n\nInorder after deleting 2:\n";
    inorder(root);

    return 0;
}
