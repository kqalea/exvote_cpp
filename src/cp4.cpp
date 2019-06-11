/*
 * cp4.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: kqalea
 */

#include"cp4.hpp"


void CP4::visit(node* target){
    std::cout << target->val;
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
    visit_record = new std::vector<bool>(nodes, false);
    std::deque<int> queue;

    visit_record->at(i) = true;
    queue.push_back(i);
    std::cout << "BFS!!!!" << std::endl;
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
    visit_record = new std::vector<bool>(nodes, false);
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


bool CP4_Graph::BFS_FindPath(int start, int end){
    std::vector<int>::iterator it;
    visit_record = new std::vector<bool>(nodes, false);
    std::deque<int> queue;

    visit_record->at(start) = true;
    queue.push_back(start);
    while(!queue.empty()){
        start = queue.front();
        std::cout << start << " ";
        queue.pop_front();
        for(it = listOfnodes[start].begin(); it != listOfnodes[start].end(); ++it){
            if(visit_record->at(*it) == 0){
                if(*it == end) return true;
                visit_record->at(*it) = true;
                queue.push_back(*it);
            }
        }
    }
    return false;
}

void CP4_Graph::addEdge(std::vector<int> &nodes){

    listOfnodes.push_back(nodes);
    this->nodes++;
}

CP4_Tree CP4::createMinimalBST(std::vector<int> &arr){
    CP4_Tree tree;
    tree.root = createMinimalBST(arr, 0, arr.size()-1);
    return tree;
}

node* CP4::createMinimalBST(std::vector<int> &arr, int start, int end){
    if(end < start) return nullptr;
    node *root = new node;
    int mid = (start+end)/2;
    root->val = arr[mid];
    root->left = createMinimalBST(arr, start, mid-1);
    root->right = createMinimalBST(arr, mid + 1, end);
    return root;
}
