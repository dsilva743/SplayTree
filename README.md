# Splay tree data structure implemented in C++
Contributions by: Dominic Silva, Chris Lawler, Matthew Hayes, and Mubariz Saeed.

# Overview
The data structure implemented in this C++ program is called a splay tree. A splay tree is a self-balancing binary search tree that rotates a certain direction depending on 
what value we are searching for. This data structure is programmed with the basic functions of any binary search tree (inserting, deleting, searching), but the main difference
that distincts this binary search tree from other types is the splaying function. This function searches for a certain value stored in a node by rotating the tree in a certain 
direction. In other words, setting each visited node as the root node and making the proper arrangements until the node we are searching for is the root node. With this
important function description in mind, there are many types of rotations that will occur based on the location of the node in question. The rotation types are zig,
zig-zig, zig-zag, and zag-zag. These types of rotation are implemented in this program and will be described in greater detail in this README.md file.

# What is included in this repository
The files included in this repository are as follows:
- Splaytree.cpp
- Splaytree.h
- main.cpp

The Splaytree.cpp file includes the definitions for each function and constructor associated with this algorithm. The Splaytree.h file is a header file that declares the node class and its functions. The main.cpp file is where each function (with their respective parameters) is called and executed.

# Basic functions 
Any binary search tree includes their basic functions to serve their foundational purpose. These functions include the search, insert, and delete function.

- The search function is responsible for performing the search of a certain node/value in a binary search tree. The current node will start at the root node of the binary search tree and traverse down by going left or right depending on which the value of our node. For example, if the current node is the number 15 and we wanted to search for the number 9, then the search function would have to traverse left since 9 is less than 15. If the current node after the previous node holds the number 7, then the search function would have to traverse right since 9 is greater than 7. This process continues until the current node is equal to the value we are searching for.

- The insert function is responsible for inserting a new value and creating a new node for said value. To achieve this, the same process from the search function is performed again, where specific traversals are made based on the value of the current node and the value of the number being inserted. When enough traversals have occured to the point where a leaf is reached (a node with no children), then the function will create a new node to hold the inserted value and will either be created on the left side or the right side of the parent node depending on what the inserted number is.

- The delete function is responsible for deleting a certain node specified by the program. Once again, the same process is performed for traversing the binary search tree and when the certain node is reached, that node will be delared null and other nodes will be moved around to accomodate this deletion.

Now that the basic functions of a binary search tree are explained, the functions mentioned previously that are unique to splay trees will be explained next.

# Advanced functions
What makes a splay tree distinct from other types of trees is the splay function and its different types stated previously. The four types of splaying will be described in this section of the README.

- The zig function is responsible for rotating the tree to the right. If a user searches for a node that is a left child of the root node, then the tree will be rotated to the right from the root node so that the left child becomes the root node.

- The zag function is responsible for rotating the tree to the left. If a user searches for a node that is a right child of the root node, then the tree will be rotated to the left from the root node so that the right child becomes the root node.

- The zig zag function is responsible for creating a rotation to the right followed by a rotation to the left. If the user searches for a node that is the left child of the right child of a root node, then the tree will be rotated to to the right from the right child node and then rotated to the left from the root node so that the searched node becomes the root node.

- The zag zig function is responsible for creating a rotation to the left followed by a rotation to the right. If the user searches for a node that is the right child of the left child of a root node, then the tree will be rotated to to the left from the left child node and then rotated to the right from the root node so that the searched node becomes the root node.

- The zig zig function is responsible for performing a zig followed by another zig (two right rotations). This function exists because there might be a time when the node that is being searches has a parent as well as a grandparent. This function exists to accomodate this scenario.

- The zag zag function is responsible for performing a zag followed by another zag (two left rotations). This function exists because there might be a time when the node that is being searches has a parent as well as a grandparent. This function exists to accomodate this scenario.

# Pros and Cons

Pros:
- Unlike other binary search trees (AVL trees, Red-Black trees), extra information is not stored in memory which makes the algorithm more efficient.
- More frequently-accessed nodes will be closer to the root node, meaning that the time to access these resources will be quick. Think of it as a type of cache.

Cons:
- The time complexity for roughly balanced trees would be linear O(n).

# Compilation and Execution
The program will be compiled using this command line:
```
g++ std=c++11 main.cpp Splaytree.cpp -o splay
```
The program will be executed using this command line:
```
./splay
```

# Special Thanks
This splay tree data structure and GitHub repository was developed by Dominic Silva, Chris Lawler, Matt Hayes, and Mubariz Saeed. A thank you would like to be given
to the professor and teaching assistants of the CSC 212: Data Structures and Algorithms course at the University of Rhode Island for professing us about time complexity, stacks/queues, iteration/recursion, sorting algorithms, binary search trees, and more. We hope you enjoy using this program!
