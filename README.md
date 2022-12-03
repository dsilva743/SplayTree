# Splay tree data structure implemented in C++
Contributions by: Dominic Silva, Chris Lawler, Matthew Hayes, and Mubariz Saeed.

# Overview
The data structure implemented in this C++ program is called a splay tree. A splay tree is a self-balancing binary tree that rotates a certain direction depending on 
what value we are searching for. This data structure is programmed with the basic functions of any binary tree (inserting, deleting, searching), but the main difference
that distincts this binary tree from other types is the splaying function. This function searches for a certain value stored in a node by rotating the tree in a certain 
direction. In other words, setting each visited node as the root node and making the proper arrangements until the node we are searching for is the root node. With this
important function description in mind, there are many types of rotations that will occur based on the location of the node in question. The rotation types are zig,
zig-zig, zig-zag, and zag-zag. These types of rotation are implemented in this program and will be described in greater detail in this README.md file.

# What is included in this repository
