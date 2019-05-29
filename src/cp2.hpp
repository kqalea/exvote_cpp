/*
 * cp2.hpp
 *
 *  Created on: May 23, 2019
 *      Author: kqalea
 */

#ifndef SRC_CP2_HPP_
#define SRC_CP2_HPP_

#include<list>
#include<cmath>
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
    CP2_Node* toTail();
};

class CP2{
public:
    long addLists(list<int>& l1, list<int>& l2);
    void deleteDups(list<int>& linkedlist);
    void partitionList(list<int>& list, int x);
    bool deleteNode(CP2_Node* node);
    bool isPalindrome(list<int>& list);
    forward_list<int>::iterator nThToLast(forward_list<int>& flist, int k);
    CP2_Node* findIntersection(CP2_Node* list1, CP2_Node* list2);
};


#endif /* SRC_CP2_HPP_ */
