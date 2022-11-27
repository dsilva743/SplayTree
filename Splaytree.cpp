#include <iostream>
#include <queue>
#include "Splaytree.h"

Splaytree::Splaytree() {
    root = nullptr;
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
//                bringToTop(current -> left);
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
//                bringToTop(current -> right);
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

void Splaytree::bringToTop(Node* x) {

    Node* p = x -> parent;

    if(x -> isRoot()){
        root = x;
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
    //to do a zig-zig action, x must be the left child and p is a left child
    else if(x -> isLeftChild() && p -> isLeftChild()){
        zigZig(x, p, g);
    }
    //to do zig-zag action, x must be the left child but p must be the right child
    else if(x -> isLeftChild() && p -> isRightChild()){
        zigZag(x, p, g);
    }
    //to do zag-zag action x must be the right child iand p must be right child
    else if( x -> isRightChild() && p -> isRightChild()){
        zagZag(x, p, g);
    }
    //to do zag-zig action, x must be right child and p must be left child
    else if(x -> isRightChild() && p -> isLeftChild()){
        zagZig(x, p, g);
    }

    bringToTop(x);

}

//Zig rotation (Right rotation)
void Splaytree::zig(Node* x, Node* p, Node* g){
    std::cout << "zig" << std::endl;
    Node* child = x -> right;
    x -> setRightChild(p);
    x -> parent = nullptr;
    p -> setLeftChild(child);

}

//Zag rotation (Left rotation)
void Splaytree::zag(Node* x, Node* p, Node* g){
    std::cout << "zag " << x -> data << " " << p -> data << std::endl;
    Node* child = x -> left;
    x -> setLeftChild(p);
    x -> parent = nullptr;
    p -> setRightChild(child);
}

//Zig-zag (Zig followed by zag)
void Splaytree::zigZag(Node *x, Node *p, Node *g) {
    std::cout << "zig zag" << std::endl;
    Node* top = g -> parent;
    bool leftOfTop = g -> isLeftChild();

    zig(x, p, nullptr);
    g ->setRightChild(x);

    zag(x, g, nullptr);

    if(top != nullptr){
        if(leftOfTop){
            top ->setLeftChild(x);
        }
        else{
            top ->setRightChild(x);
        }
    }
}

//Zag-zig (Zag followed by zig)
void Splaytree::zagZig(Node *x, Node *p, Node *g) {
   std::cout << "zag zig" << std::endl;
    Node* top = g -> parent;
    bool leftOfTop = g -> isLeftChild();

    zag(x, p, nullptr);
    g ->setLeftChild(x);

    zig(x, g, nullptr);


    if(top != nullptr){
        if(leftOfTop){
            top ->setLeftChild(x);
        }
        else{
            top ->setRightChild(x);
        }
    }
}

//Zig-zig (two right rotations)
void Splaytree::zigZig(Node *x, Node *p, Node *g) {
    std::cout << " zig zig" << std::endl;
    Node* top = g -> parent;
    bool leftOfTop = g -> isLeftChild();
    zig(p,g,nullptr);
    zig(x, p,nullptr);

    if(top != nullptr){
        if(leftOfTop){
            top ->setLeftChild(x);
        }
        else{
            top ->setRightChild(x);
        }
    }

}

//Zag-zag (two left rotations)
void Splaytree::zagZag(Node *x, Node *p, Node *g) {
    std::cout << " zag zag" << std::endl;
    Node* top = g -> parent;
    bool leftOfTop = g -> isLeftChild();
    zag(p,g,nullptr);
    zag(x, p,nullptr);

    if(top != nullptr){
        if(leftOfTop){
            top ->setLeftChild(x);
        }
        else{
            top ->setRightChild(x);
        }
    }
}

void Splaytree::inOrder() {
    inOrder(root);
    std::cout << std::endl;

}
void Splaytree::inOrder(Node* curr){
    if(curr == nullptr){
        return;
    }
    else{
        inOrder(curr -> left);
        std::cout << " " << curr -> data;
        inOrder(curr -> right);
    }
}

void Splaytree::levelOrder() {
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        std::cout << curr -> data << " ";

        if(curr -> left != nullptr){
            q.push(curr -> left);
        }

        if(curr -> right != nullptr){
            q.push(curr -> right);
        }
    }
    std::cout << std::endl;
}





