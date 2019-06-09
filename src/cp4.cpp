/*
 * cp4.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: kqalea
 */

#include"cp4.hpp"


void CP4::visit(node* target){
    std::cout << target->val << std::endl;
}

void CP4::inOrderTraversal(node* target){

    if(target != nullptr){
        inOrderTraversal(target->left);
        visit(target);
        inOrderTraversal(target->right);
    }
}

void CP4::preOrderTraversal(node* target){
    if(target != nullptr){
        visit(target);
        preOrderTraversal(target->left);
        preOrderTraversal(target->right);
    }
}


void CP4::postOrderTraversal(node* target){
    if(target != nullptr){
        postOrderTraversal(target->left);
        postOrderTraversal(target->right);
        visit(target);
    }
}

void CP4_Graph::BFS(int i){
    std::vector<int>::iterator it;
    visit_record = new std::vector<bool>(nodes, 0);
    std::deque<int> queue;

    visit_record->at(i) = true;
    queue.push_back(i);

    while(!queue.empty()){
        i = queue.front();
        std::cout << i << " ";
        queue.pop_front();
        for(it = listOfnodes[i].begin(); it != listOfnodes[i].end(); ++it){
            if(visit_record->at(*it) == 0){
                visit_record->at(*it) = true;
                queue.push_back(*it);
            }
        }
    }
    visit_record->clear();
}

void CP4_Graph::DFS(int i){
    std::vector<int>::iterator it;
    visit_record = new std::vector<bool>(nodes, 0);
    std::stack<int> stack;
    visit_record->at(i) = true;
    stack.push(i);
    while(!stack.empty()){
        i = stack.top();
        std::cout << i << " ";
        stack.pop();
        for(it = listOfnodes[i].begin(); it != listOfnodes[i].end(); ++it){
            if(visit_record->at(*it) == 0){
                visit_record->at(*it) = true;
                stack.push(*it);
            }
        }

    }
    visit_record->clear();

}
