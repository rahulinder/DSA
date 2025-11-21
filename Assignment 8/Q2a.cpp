Node* search_rec(Node* root, int val) {
    if (root == nullptr || root->data == val) {
        if (root) {
            cout << "Element " << val << " found in the BST." << endl;
        } else {
            cout << "Element " << val << " not found in the BST." << endl;
        }
        return root;
    }

    else if (val < root->data) {
        return search_rec(root->left, val);
    }
    else { 
        return search_rec(root->right, val);
    }
}


Node* search_loop(Node* root, int val) {
    Node* temp=root;
    while(temp!=nullptr){
    if (temp->data == val) {
    cout << "Element " << val << " found in the BST." << endl;
        return temp;
    }
    else if (val < temp->data) {
       temp=temp->left;
    }
    else { 
       temp=temp->right;
        }
    }
    cout<<"Element not found:("<<endl;
    return nullptr;
}