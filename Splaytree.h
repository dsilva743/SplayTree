#ifndef TERMPROJECT_SPLAYTREE_H
#define TERMPROJECT_SPLAYTREE_H


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


class Splaytree{

    private:
        Node* root;


    public:
        Splaytree();
        void insert(int data);
    //    bool search(int data);
    //    void inOrder();
    //    void levelOrder();

};


#endif //TERMPROJECT_SPLAYTREE_H
