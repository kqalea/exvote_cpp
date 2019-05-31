/*
 * cp3.hpp
 *
 *  Created on: May 30, 2019
 *      Author: kqalea
 */

#ifndef SRC_CP3_HPP_
#define SRC_CP3_HPP_


#include<vector>
#include<algorithm>
#include<iostream>

class CP3_Stack{
public:
    CP3_Stack();
    ~CP3_Stack();
    void push(int session_id, int data);
    int pop(int session_id);
    std::vector<int> returnArray();
private:
    std::vector<int> array;
    int session1_size=0;
    int session2_size=0;
    int session3_size=0;
};




#endif /* SRC_CP3_HPP_ */
