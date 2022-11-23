#ifndef TERM_PROJECT_SPLAYTREE_H
#define TERM_PROJECT_SPLAYTREE_H

class Node{

    public:
        int data;
        Node* left;
        Node* right;
        Node* parent;
        bool isLeftChild(){
            if(parent == nullptr){
                return false;
            }
            else{
                return parent -> left == this;
            }
        }
        bool isRightChild(){
            if(parent == nullptr){
                return false;
            }
            else{
                return parent -> right == this;
            }
        }

        bool isRoot(){
            return parent == nullptr;
        }

        Node(int d, Node* p){
            data = d;
            left = nullptr;
            right = nullptr;
            parent = p;
        }

};


class Splaytree {

    private:
        Node* root = nullptr;
        void bringToTop(Node* x);
        void zig(Node* x, Node* p, Node* g);
        void zigZig(Node* x, Node* p, Node* g);
        void zigZag(Node* x, Node* p, Node* g);
        void zag(Node* x, Node* p, Node* g);
        void zagZag(Node* x, Node* p, Node* g);
        void zagZig(Node* x, Node* p, Node* g);

    public:
        Splaytree();
        void insert(int data);
        bool search(int data);
    //    void inOrder();
    //    void levelOrder();


};


#endif //TERM_PROJECT_SPLAYTREE_H
