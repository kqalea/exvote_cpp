/*
 * test.cpp
 *
 *  Created on: May 23, 2019
 *      Author: kqalea
 */



#include "../src/topic.hpp"
#include"catch.hpp"

Topic topic;

TEST_CASE("Topic TwoSum") {
    vector<int32_t> numbers { 1, 2, 3, 4 };
    int32_t target = 6;
    vector<int32_t> answer { 1, 3 };
    vector<int32_t> result;
    result = topic.twoSum(numbers, target);
    std::sort(result.begin(), result.end());
    REQUIRE(result == answer);
}
