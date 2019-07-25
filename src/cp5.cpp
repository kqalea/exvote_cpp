/*
 * cp5.cpp
 *
 *  Created on: Jul 19, 2019
 *      Author: kqalea
 */

#include"cp5.hpp"

std::bitset<64> CP5::bitInsertion(std::bitset<32> source, std::bitset<32> target, int start, int end){

    int count = 0;
    for(int x = start; x <= end; ++x){
        source[x] = target[count];
        count++;
    }
    std::bitset<64> answer(source.to_string());

    return answer;

}
