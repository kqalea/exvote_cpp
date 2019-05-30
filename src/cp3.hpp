/*
 * cp3.hpp
 *
 *  Created on: 2019年5月30日
 *      Author: kqalea
 */

#ifndef SRC_CP3_HPP_
#define SRC_CP3_HPP_


#include<vector>

class CP3_Stack{
public:
    std::vector<int> array;
    int session1_size=0;
    int session1_head=0;
    int session1_tail=0;
    int session2_size=0;
    int session2_head=0;
    int session2_tail=0;
    int session3_size=0;
    int session3_head=0;
    int session3_tail=0;
    CP3_Stack();
    ~CP3_Stack();
    void push(int session_id, int data);
    int pop(int session_id);
};




#endif /* SRC_CP3_HPP_ */
