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