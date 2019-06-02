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

void CP3_MinStack::push(int data){
    if(mainStack.size() == 0){
        mainStack.push(data);
        minStack.push(data);
    }else{
        mainStack.push(data);
        if(data <= minStack.top()) minStack.push(data);
    }
}

int CP3_MinStack::pop(){
    int p = mainStack.top();
    mainStack.pop();
    if(p == minStack.top()) minStack.pop();
    return p;
}

int CP3_MinStack::getMin(){
    if(minStack.size()>0){
        return minStack.top();
    }else{
        return -1;
    }
}

void CP3_SetOfStack::push(int data){
    int size = this->stack.size();

    if(size <= this->stack_size){
        this->stack.push_back(data);
    }else{
        this->stacksCount = size / this->stack_size;
        this->stack.push_back(data);
    }

}

int CP3_SetOfStack::pop(){
    if(this->stack.size() == 0) return -1;
    int value = this->stack.back();
    this->stack.pop_back();
    return value;
}

int CP3_SetOfStack::getStacksCount(){
    return stacksCount;
}

int CP3_SetOfStack::popAt(int stack_id){
    int val;
    std::vector<int>::iterator pop_loc = this->stack.begin();
    if(stack_id > stacksCount || this->stack.size() == 0) return -1;
    if(stack_id == 0 && stack.size() <= stack_size){
        val = this->stack.back();
        this->stacksCount = stack.size() / this->stack_size;
        return val;
    }else if(stack_id == 0){
        pop_loc = pop_loc + stack_size -1;
        val = *pop_loc;
        this->stack.erase(pop_loc);
        this->stacksCount = stack.size() / this->stack_size;
        return val;
    }
    if(this->stack.size() - (stack_id*stack_size) > 10){
        pop_loc = pop_loc + 10 + (stack_id*stack_size) -1;
        val = *pop_loc;
        this->stack.erase(pop_loc);
        this->stacksCount = stack.size() / this->stack_size;
        return val;
    }else{
        val = this->stack.back();
        this->stack.pop_back();
        this->stacksCount = stack.size() / this->stack_size;
        return val;
    }

}
