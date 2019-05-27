/*
 * cp2.hpp
 *
 *  Created on: May 23, 2019
 *      Author: kqalea
 */

#ifndef SRC_CP2_HPP_
#define SRC_CP2_HPP_

#include<list>
#include<forward_list>
#include<unordered_set>
#include<iostream>

using namespace std;

class CP2_Node{

public:
    int value = 0;
    CP2_Node *perv_node;
    CP2_Node *next_node;
    CP2_Node();
    ~CP2_Node();
};

class CP2{
public:
    void deleteDups(list<int>& linkedlist);
    bool deleteNode(CP2_Node* node);
    forward_list<int>::iterator nThToLast(forward_list<int>& flist, int k);
};


#endif /* SRC_CP2_HPP_ */
