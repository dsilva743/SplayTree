#ifndef TERM_PROJECT_SPLAYTREE_H
#define TERM_PROJECT_SPLAYTREE_H

class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
            left = nullptr;
            right = nullptr;
        }

};


class Splaytree {

    private:
        Node* root = nullptr;

    public:
        Splaytree();
        void insert(int data);
        bool search(int data);
    //    void inOrder();
    //    void levelOrder();


};


#endif //TERM_PROJECT_SPLAYTREE_H
