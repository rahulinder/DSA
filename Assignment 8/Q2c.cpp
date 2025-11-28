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