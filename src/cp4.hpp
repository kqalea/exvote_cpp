/*
 * cp4.hpp
 *
 *  Created on: Jun 5, 2019
 *      Author: kqalea
 */

#ifndef SRC_CP4_HPP_
#define SRC_CP4_HPP_

#include<vector>
#include<string>
#include<iostream>
#include<bitset>
#include<deque>
#include<stack>

typedef struct node{
    std::string name;
    int val;
    node *left = nullptr;
    node *right = nullptr;
}node;

class CP4_Tree{
    node root;
};

class CP4_Graph{
private:
    bool directed = false;
    int nodes;
    std::vector<bool> *visit_record;
    std::vector<std::vector<int>> listOfnodes;
public:
    void BFS(int i);
    void DFS(int i);
};


class CP4{
public:
    void inOrderTraversal(node* target);
    void preOrderTraversal(node* target);
    void postOrderTraversal(node* target);
    void visit(node* target);
};




#endif /* SRC_CP4_HPP_ */
