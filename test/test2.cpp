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

TEST_CASE("cp2 partitionList"){
    list<int> target = {1,4,3,2,5,2};
    list<int> answer = {1,2,2,4,3,5};
    cp2.partitionList(target, 3);

    list<int>::iterator it1 = target.begin();
    list<int>::iterator it2 = answer.begin();
    bool flag = false;
    while(it1 != target.end()){
        if(*it1 != *it2){
            flag = true;
            break;
        }
        ++it1;
        ++it2;
    }
    REQUIRE(!flag);
}

TEST_CASE("cp2 addLists"){
    list<int> l1 = {9,7,8};
    list<int> l2 = {6,6,6};
    long ans = 978+666;
    long test= cp2.addLists(l1,l2);
    REQUIRE(ans == test);
}

TEST_CASE("cp2 isPalindrome"){
    list<int> target1 = {1,2,3,3,2,1};
    list<int> target2 = {1,2,3,4,3,2,1};
    list<int> target3 = {1,1,2,2,2,1,1,1};
    REQUIRE(cp2.isPalindrome(target1) == true);
    REQUIRE(cp2.isPalindrome(target2) == true);
    REQUIRE(cp2.isPalindrome(target3) == false);
}

TEST_CASE("cp2 findIntersection"){
    CP2_Node *head = new CP2_Node;
    CP2_Node *walker = head;
    CP2_Node *target;
    CP2_Node *test = new CP2_Node;
    CP2_Node *answer;
    for(int i=1;i<10;i++){
        CP2_Node *node = new CP2_Node;
        walker->next_node = node;
        walker->next_node->perv_node = walker;
        walker = walker->next_node;
        walker->value = i;
        if(i==5){
            target = walker;
            cout << "target " << target << endl;
        }
    }
    walker = test;
    for(int i=1;i<5;i++){
        CP2_Node *node = new CP2_Node;
        walker->next_node = node;
        walker->next_node->perv_node = walker;
        walker = walker->next_node;
        walker->value = i;
    }
    walker->next_node = target;
    answer = cp2.findIntersection(head, test);
    REQUIRE(answer == target);
}

TEST_CASE("cp2 findBeginning"){
    CP2_Node *head = new CP2_Node;
    CP2_Node *walker = head;
    CP2_Node *target;
    CP2_Node *answer;
    for(int i=1; i<8; i++){
        CP2_Node *node = new CP2_Node;
        walker->next_node = node;
        walker->next_node->perv_node = walker;
        walker = walker->next_node;
        walker->value = i;
        if(i == 3) target = walker;
    }
    walker->next_node = target;
    answer = cp2.findBeginning(head);
    REQUIRE(answer == target);
}

