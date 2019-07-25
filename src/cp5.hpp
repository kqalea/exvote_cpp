/*
 * cp5.hpp
 *
 *  Created on: Jul 19, 2019
 *      Author: kqalea
 */

#ifndef SRC_CP5_HPP_
#define SRC_CP5_HPP_


#include<bitset>
#include<iostream>


class CP5{
public:

    std::bitset<64> bitInsertion(std::bitset<32> source, std::bitset<32> target, int start, int end);


};


#endif /* SRC_CP5_HPP_ */
