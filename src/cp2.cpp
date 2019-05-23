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

