/*
 * test5.cpp
 *
 *  Created on: Jul 19, 2019
 *      Author: kqalea
 */




#include"catch.hpp"
#include"../src/cp5.hpp"

TEST_CASE("Bit_Insert"){

    std::bitset<32> source("1000000000");
    std::bitset<32> target("10011");
    int start = 2;
    int end = 6;
    CP5 cp5;
    std::bitset<64> answer = cp5.bitInsertion(source, target, start, end);

    std::cout << answer.to_string() << "\n";

}
