/*
 * test2.cpp
 *
 *  Created on: May 23, 2019
 *      Author: kqale
 */
#include"../src/cp2.hpp"
#include"catch.hpp"

CP2 cp2;

TEST_CASE("cp2 deleteDups"){
    list<int> target = {1,1,2,2,3,3,4,4,5,5};
    list<int> answer = {1,2,3,4,5};
    cp2.deleteDups(target);
    bool err = false;
    if(target.size() != answer.size()){
        err = true;
    }else{
        list<int>::iterator t = target.begin();
        list<int>::iterator a = answer.begin();
        while(t != target.end() && a != answer.end()){
            if(*t != *a){
                err = true;
                break;
            }
            ++t;
            ++a;
        }
    }
    REQUIRE(!err);
}

TEST_CASE("cp2 nthToLast"){
    forward_list<int> flist = {1,2,3,4,5,6,7,8,9,10};
    forward_list<int>::iterator it = cp2.nThToLast(flist, 5);
    REQUIRE(*it == 6);
}


TEST_CASE("cp2 deleteNode"){
    CP2_Node *head = new CP2_Node;
    CP2_Node *head_bk = head;
    CP2_Node *target ;
    head->value = 1;
    for(int i=1; i<=10; ++i){
       CP2_Node *node = new CP2_Node;
       if(head->value == 1){
           head->next_node = node;
           head->next_node->perv_node = head;
           head = head->next_node;
       }else{
           head->value = i;
           head->next_node = node;
           head->next_node->perv_node = head;
           head = head->next_node;
       }
    }
    head = head_bk;
    while(head->next_node != nullptr){
        cout << head->value <<' ';
        head = head->next_node;
        if (head->value == 5){
            target = head;
        }
    }
    bool ans = cp2.deleteNode(target);
    cout << endl;
    head = head_bk;
    while(head->next_node != nullptr){
        cout << head->value <<' ';
        head = head->next_node;
    }
    cout << endl;
    REQUIRE(ans);
}
