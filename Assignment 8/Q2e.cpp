//In-order predecessor of a given node the BST 

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
void inorder(Node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
}
Node* Min(Node* root){
    if (root == nullptr) {
        cout << "The tree is empty. Min element not found." << endl;
        return nullptr;
    }
    Node* temp = root;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    
    cout << "Min element is " << temp->data << endl;
    return temp;
}
Node* Max(Node* root){
    if (root == nullptr) {
        cout << "The tree is empty. Max element not found." << endl;
        return nullptr;
    }
    Node* temp = root;
    while(temp->right != nullptr){
        temp = temp->right;
    }
    
    cout << "Max element is " << temp->data << endl;
    return temp;
}

Node* succ(Node* root, int ele){
    Node* successor = nullptr;
    Node* current = root;
    while (current != nullptr) {
        if (ele < current->data) {
            successor = current;  // potential successor
            current = current->left;
        } else if (ele > current->data) {
            current = current->right;
        } else {
            // Found the node
            if (current->right != nullptr) {
                successor = Min(current->right);
            }
            break;
        }
    }

    return successor;
}

Node* prede(Node* root, int ele){
    Node* predeccessor = nullptr;
    Node* current = root;
    while (current != nullptr) {
        if (ele < current->data) {
            current = current->left;
        } else if (ele > current->data) {
            predeccessor=current;
            current = current->right;
        } else {
            // Found the node
            if (current->left != nullptr) {
                predeccessor = Max(current->left);
            }
            break;
        }
    }

    return predeccessor;
}
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = new Node(16);
    root->left = new Node(8);
    root->right = new Node(25);
    root->right->right = new Node(42);
    root->right->right->right = new Node(62);
    root->right->right->right->left = new Node(49);
    root->right->right->right->left->right = new Node(58);
    inorder(root);
    cout<<endl<<succ(root,58)->data<<endl;
    cout<<endl<<prede(root,58)->data<<endl;
    deleteTree(root);
    
    return 0;
}