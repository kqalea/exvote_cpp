/*
 * cp3.cpp
 *
 *  Created on: May 30, 2019
 *      Author: kqalea
 */


#include"cp3.hpp"

CP3_Stack::CP3_Stack(){

}

CP3_Stack::~CP3_Stack(){
    this->array.clear();
}

void CP3_Stack::push(int session_id, int data){
    std::vector<int>::iterator insert_loc = array.begin();
    switch(session_id){
        case 1:
            insert_loc = insert_loc + session1_size;
            array.insert(insert_loc, data);
            this->session1_size +=1;
            break;
        case 2:
            insert_loc = insert_loc + session1_size + session2_size;
            array.insert(insert_loc, data);
            this->session2_size +=1;
            break;
        case 3:
            insert_loc = insert_loc + session1_size + session2_size + session3_size;
            array.insert(insert_loc, data);
            this->session3_size +=1;
            break;
        default:
            break;
    }
}

int CP3_Stack::pop(int session_id){
    int value = -1;
    std::vector<int>::iterator erase_loc = array.begin();
    switch(session_id){
        case 1:
            if(session1_size > 0){
               erase_loc = erase_loc + session1_size -1;
               value = *erase_loc;
               this->session1_size--;
               array.erase(erase_loc);
            }
            break;
        case 2:
            if(session2_size > 0){
                erase_loc = erase_loc + session1_size + session2_size -1;
                value = *erase_loc;
                this->session2_size--;
                array.erase(erase_loc);
            }
            break;
        case 3:
            if(session3_size > 0){
                erase_loc = erase_loc + session1_size + session2_size + session3_size -1;
                value = *erase_loc;
                this->session3_size--;
                array.erase(erase_loc);
            }
            break;
        default:
            break;
    }

    return value;

}

std::vector<int> CP3_Stack::returnArray(){
    return array;
}
