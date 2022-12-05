#include <iostream>
#include "Splaytree.h"

int menu(){
    //prints the menu and gets the user input for menu options and returns it
    //will only return valid options
    int choice = 0;

    while(choice < 1 || choice > 4){
        std::cout << "1. Insert Number" << std::endl;
        std::cout << "2. Search for number" << std::endl;
        std::cout << "3. Print level order" << std::endl;
        std::cout << "4. Quit" << std::endl;

        std::cin >> choice;
    }
    return choice;
}

int main() {

    Splaytree tree;
    int choice = 0;

    while(choice != 4){
        choice = menu();

        if(choice == 1){
            //insert number
            std::cout << "Enter a number: ";
            int num;
            std::cin >> num;
            tree.insert(num);
        }
        else if( choice == 2){
            //search number
            std::cout << "Enter a number to search for: ";
            int num;
            std::cin >> num;
            bool results = tree.search(num);
            std::cout << "Result: " << results << std::endl;


        }
        else if(choice == 3){
            //tree level order
            std::cout << "------ Level Order ------"<< std::endl;
            tree.levelOrder();
            std::cout << "-------------------------" << std::endl;
        }
        else{
            std::cout << "Goodbye" << std::endl;
        }
    }


    return 0;
}
