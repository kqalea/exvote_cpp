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
#include<climits>


typedef struct node{
    std::string name;
    int val;
    node *left = nullptr;
    node *right = nullptr;
}node;

class CP4_Tree{
public:
    node *root;
};

class CP4_Graph{
private:
    bool directed = false;
    int nodes = 0;
    std::vector<bool> *visit_record;
    std::vector<std::vector<int>> listOfnodes;

public:
    void BFS(int i);
    void DFS(int i);
    void addEdge(std::vector<int> &nodes);
    bool BFS_FindPath(int start, int end);

};


class CP4{
public:
    void inOrderTraversal(node* target);
    void preOrderTraversal(node* target);
    void postOrderTraversal(node* target);
    void visit(node* target);
    bool checkBalanced(node* root);
    bool checkBST(node* root);
    bool checkBST(node* root, int min, int max);
    int checkHeight(node* root);
    std::vector<std::vector<int>> treeToList(CP4_Tree& tree);
    void treeToList(node* root, int level, std::vector<std::vector<int>> &arr);



    CP4_Tree createMinimalBST(std::vector<int> &arr);
    node* createMinimalBST(std::vector<int> &arr, int start, int end);
};




#endif /* SRC_CP4_HPP_ */
