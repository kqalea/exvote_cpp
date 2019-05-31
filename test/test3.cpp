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
    for(auto x: answer){
        std::cout << x << ' ' ;
    }
    std::cout << std::endl;

    REQUIRE(std::equal(target.begin(),target.end(), answer.begin()));

}
