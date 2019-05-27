/*
 * cp2.cpp
 *
 *  Created on: May 23, 2019
 *      Author: kqalea
 */

#include"cp2.hpp"

void CP2::deleteDups(list<int>& linkedlist){
    unordered_set<int> hashset ;
    list<int>::iterator curr = linkedlist.begin();
    while(curr != linkedlist.end()){
        if(hashset.count(*curr) > 0){
            linkedlist.erase(curr);
        }else{
            hashset.insert(*curr);
        }
        curr++;
    }
    hashset.clear();
}

forward_list<int>::iterator CP2::nThToLast(forward_list<int>& flist, int k){
    forward_list<int>::iterator p1 = flist.begin();
    forward_list<int>::iterator p2 = flist.begin();
    for(int i=0; i<k; ++i){
        if(p1 == flist.end()) return (forward_list<int>::iterator) nullptr;
        ++p1;
    }
    while(p1 != flist.end()){
        ++p1;
        ++p2;
    }
    return p2;
}

bool CP2::deleteNode(CP2_Node *node){
    if(node == nullptr || node->next_node == nullptr){
        return false;
    }
    CP2_Node *tmp_node = node->next_node;
    node->value = tmp_node->value;
    node->next_node = tmp_node->next_node;
    node->next_node->perv_node = node;
    delete tmp_node;
    return true;
}

CP2_Node::CP2_Node(){
    this->next_node = nullptr;
    this->perv_node = nullptr;
}

CP2_Node::~CP2_Node(){
    this->next_node = nullptr;
    this->perv_node = nullptr;
}
