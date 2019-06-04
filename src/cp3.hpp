/*
 * cp3.hpp
 *
 *  Created on: May 30, 2019
 *      Author: kqalea
 */

#ifndef SRC_CP3_HPP_
#define SRC_CP3_HPP_


#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
#include<queue>

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


class CP3_MinStack{
public:
    void push(int data);
    int pop();
    int getMin();
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

};


class CP3_SetOfStack{
public:
    std::vector<int> stack;
    void push(int data);
    int pop();
    int popAt(int stack_id);
    int getStacksCount();

    int stacksCount = 0;
    const int stack_size = 10;

};
template<typename T>
class CP3_MyQueue{
public:
    int size(){return newstack.size() + oldstack.size();};
    void add(T data){newstack.push(data);};
    T peek(){
        shiftStacks();
         return oldstack.top();
    }
    T remove(){
        shiftStacks();
        T t = oldstack.top();
        oldstack.pop();
        return t;
    }
    void shiftStacks(){
        if(oldstack.empty()){
            while(!newstack.empty()){
               T t = newstack.top();
               oldstack.push(t);
               newstack.pop();
            }
        }
    }

private:
   std::stack<T> newstack;
   std::stack<T> oldstack;

};
template<typename c>
class CP3_SortStack{
public:
     std::stack<c> sortStack(std::stack<c> &input){
         std::stack<c> tmp_stack;
         while(!input.empty()){
             c tmp = input.top();
             input.pop();

             while(!tmp_stack.empty() && tmp_stack.top() > tmp){
                 input.push(tmp_stack.top());
                 tmp_stack.pop();
             }
             tmp_stack.push(tmp);
         }
         return tmp_stack;
     }
};

#define CP3_Dog (1)
#define CP3_Cat (2)

class CP3_Animal{
    typedef struct animal{
        int type = -1;
        int time = -1;
    };
private:
    std::queue<animal> dogs;
    std::queue<animal> cats;
    int time = 0;
public:
    void enqueue(int i);
    animal dequeueAny();
    animal dequeueCat();
    animal dequeueDog();
};

#endif /* SRC_CP3_HPP_ */
