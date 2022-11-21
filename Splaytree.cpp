#include "Splaytree.h"


void Splaytree::insert(int data) {

    if(root == nullptr){
        root = new Node(data);
        return;
    }
    Node* current = root;
    while(true){
        if(data < current -> data){
            if(current -> left == nullptr){
                current -> left = new Node(data);
                return;
            }
            else{
                current = current -> left;
            }
        }
    }
}


