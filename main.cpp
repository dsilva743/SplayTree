#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Splaytree.h"


void readFile(std::vector<double> &number, std::string &fileName){

    std::ifstream inFile(fileName);
    std::string line;

    while (std::getline(inFile, line)) {
        std::vector <double> temp;
        std::istringstream stream(line);
        double val;
        while(stream >> val) {
            number.push_back(val);
        }
    }
}


int menu(){
    //prints the menu and gets the user input for menu options and returns it
    //will only return valid options
    int choice = 0;

    while(choice < 1 || choice > 5){
        std::cout << "1. Insert Number" << std::endl;
        std::cout << "2. Search for number" << std::endl;
        std::cout << "3. Print level order" << std::endl;
        std::cout << "4. Read numbers from file" << std::endl;
        std::cout << "5. Quit" << std::endl;

        std::cin >> choice;
    }
    return choice;
}



int main(int argc, char *argv[]){

    std::string file_name(argv[1]);
    std::vector<double> number;
    readFile(number, file_name);

    Splaytree tree;
    int choice = 0;

    while(choice != 5){
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
        else if(choice == 4){
            //read numbers from file
            for(auto num : number){
                tree.insert(num);
            }
        }
        else{
            std::cout << "Goodbye" << std::endl;
        }

    }
    return 0;
}
