#include <iostream>
#include "Splaytree.h"

int main() {
    
    //Testing 
    Splaytree test;

    test.insert(10);
    test.insert(7);
    test.insert(15);
    test.insert(1);
    test.insert(9);
    test.insert(13);
    test.insert(20);
    test.insert(-1);
    test.insert(30);

    std::cout << "Tree created level order " << std::endl;
    test.levelOrder();
    test.search(15);
    std::cout << "After searching for 15 " << std::endl;
    test.levelOrder();

//    test.insert((5));
//    test.insert((3));
//    test.insert((4));
//    test.insert((6));
//    test.insert((1));
//
//    test.search(3);

    return 0;
}
