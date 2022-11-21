#include "Splaytree.h"

Splaytree::Splaytree() {

}

void Splaytree::insert(int data) {

    if(root == nullptr){
        root = new Node(data);
        return;
    }

    Node* current = root;

    while(true){
        //Less than
        if(data < current -> data) {
            if (current->left == nullptr) {
                current->left = new Node(data);
                return;
            }
            else {
                current = current->left;
            }
        }
        //Greater than
        if(data > current -> data) {
            if (current->right == nullptr) {
                current->right = new Node(data);
                return;
            }
            else {
                current = current->right;
            }
        }
    }
}


bool Splaytree::search(int data) {

    Node* current = root;

    while(current != nullptr) {

        if(data == current -> data){
            return true;
        }
        //Less than
        if (data < current -> data) {
            current = current->left;
        }
        //Greater than
        else if(data > current -> data){
            current = current -> right;
        }
    }
    return false;
}





