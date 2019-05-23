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
