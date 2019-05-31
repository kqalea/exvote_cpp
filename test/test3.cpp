/*
 * test3.cpp
 *
 *  Created on: May 31, 2019
 *      Author: kqalea
 */


#include"../src/cp3.hpp"
#include"catch.hpp"

TEST_CASE("cp3 MuliStack"){
    CP3_Stack *stack = new CP3_Stack();
    std::vector<int> target = {11,12,13,21,22,23,31,32,33};

    stack->push(1, 11);
    stack->push(2, 21);
    stack->push(3, 31);
    stack->push(1, 12);
    stack->push(2, 22);
    stack->push(3, 32);
    stack->push(1, 13);
    stack->push(2, 23);
    stack->push(3, 33);

    std::vector<int> answer = stack->returnArray();
    REQUIRE(std::equal(target.begin(),target.end(), answer.begin()));
    for(auto x: answer){
        std::cout << x << ' ' ;
    }
    std::cout << std::endl;

    for(int y=1; y<=3; y++){
        for(int i=1; i<=3; i++){
            std::cout <<stack->pop(i) << ' ';
        }
    }
    std::cout << std::endl;
}

TEST_CASE("cp3 minStack"){
    CP3_MinStack stack;
    stack.push(10);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(6);
    stack.push(6);
    stack.push(11);
    std::vector<int> target = {6,6,7,10};
    std::vector<int> answer;
    int tmp;
    int min;
    for(int i=0;i<7;i++){
        min = stack.getMin();
        tmp = stack.pop();
        if(min == tmp) answer.push_back(min);
    }
    REQUIRE(std::equal(target.begin(),target.end(), answer.begin()));
}
