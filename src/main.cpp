/*
 * main.cpp
 *
 *  Created on: May 6, 2019
 *      Author: kqalea
 */

#define CATCH_CONFIG_RUNNER

#include"topic.hpp"
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

TEST_CASE("Topic isUniqueChars"){
    string str1 = "hello world";
    string str2 = "abcdefgh";
    REQUIRE(!topic.isUniqueChars(str1));
    REQUIRE(topic.isUniqueChars(str2));
}

TEST_CASE("Topic isPermutation"){
    string str1 = "aabbccdd";
    string str2 = "bdcaabcd";
    string str3 = "areyouok";
    string str4 = "koareasd";
    REQUIRE(topic.isPermutation(str1, str2));
    REQUIRE(!topic.isPermutation(str3, str4));
    REQUIRE(topic.isPermutation_2(str1, str2));
    REQUIRE(!topic.isPermutation_2(str3, str4));
}

TEST_CASE("Topic replaceSpaces"){
    string str1 = "Hi How Are You";
    string str2 = "Hi%20How%20Are%20You";
    string str3 = topic.replaceSpaces(str1);
    REQUIRE(str3.compare(str2) == 0);
}

TEST_CASE("Topic isPermutationOfPalindrome") {
    string str1 = "aabbccdd";
    string str2 = "abcdefgh";
    REQUIRE(topic.isPermutationOfPalindrome(str1));
    REQUIRE(!topic.isPermutationOfPalindrome(str2));
}


TEST_CASE("Topic isOneEditAway"){
    string str1 = "pale";
    string str2 = "ple";
    string str3 = "pales";
    string str4 = "bale";
    string str5 = "bake";
    REQUIRE(topic.isOneEditAway(str1, str2));
    REQUIRE(topic.isOneEditAway(str3, str1));
    REQUIRE(topic.isOneEditAway(str1, str4));
    REQUIRE(!topic.isOneEditAway(str1, str5));
}

TEST_CASE("Topic strCompress"){
    string str1 = "aabcccccaaa";
    string str2 = "2a1b5c3a";
    string str3 = topic.strCompress(str1);
    REQUIRE(str2.compare(str3) == 0);
}

int main(int argc, char* argv[]){

    int result = Catch::Session().run(argc, argv);
    return result;
}
