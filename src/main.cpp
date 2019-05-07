/*
 * main.cpp
 *
 *  Created on: May 6, 2019
 *      Author: kqalea
 */

#define CATCH_CONFIG_RUNNER

#include<iostream>
#include<algorithm>
#include"topic.hpp"
#include"catch.hpp"

TEST_CASE("Topic TwoSum") {
    Topic topic;
    vector<int32_t> numbers { 1, 2, 3, 4 };
    int32_t target = 6;
    vector<int32_t> answer { 1, 3 };
    vector<int32_t> result;
    result = topic.twoSum(numbers, target);
    std::sort(result.begin(), result.end());
    REQUIRE(result == answer);
}

int main(int argc, char* argv[]){

    int result = Catch::Session().run(argc, argv);
    return result;
}
