#include "Splaytree.h"

Splaytree::Splaytree() {

}

void Splaytree::insert(int data) {

    if(root == nullptr){
        root = new Node(data, nullptr);
        return;
    }

    Node* current = root;

    while(true){
        //Less than
        if(data < current -> data) {
            if (current->left == nullptr) {
                current->left = new Node(data, current);
                bringToTop(current -> left);
                return;
            }
            else {
                current = current->left;
            }
        }
        //Greater than
        if(data > current -> data) {
            if (current->right == nullptr) {
                current->right = new Node(data, current);
                bringToTop(current -> right);
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
            bringToTop(current);
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

void Splaytree::bringToTop(Node *x) {

    Node* p = x -> parent;

    if(x -> isRoot()){
        return;
    }
    Node* g = p -> parent;

    //to do a zig action, the x must be the left child and the p is the root
    if(x -> isLeftChild() && p -> isRoot()){
        zig(x, p, g);
    }
    //to do a zag action, x must be the right child and the p is the root
    else if(x -> isRightChild() && p ->isRoot()){
        zag(x, p, g);
    }
    //to do a zig zig action, x must be the left child and p is a left child
    else if(x -> isLeftChild() && p -> isLeftChild()){
        zigZig(x, p, g);
    }
    //to do zig zag action, x must be the left child but p must be the right child
    else if(x -> isLeftChild() && p -> isRightChild()){
        zigZag(x, p, g);
    }
    //to do zag zag action x must be the right child iand p must be right child
    else if( x -> isRightChild() && p -> isRightChild()){
        zagZag(x, p, g);
    }
    //zag zig action, x must be right child and p must be left child
    else if(x -> isRightChild() && p -> isLeftChild()){
        zagZig(x, p, g);
    }

    bringToTop(x);

}





