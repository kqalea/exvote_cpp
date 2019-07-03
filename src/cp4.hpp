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
#include<list>
#include<algorithm>

typedef struct node{
    std::string name;
    int val;
    node *left = nullptr;
    node *right = nullptr;
    node *parent = nullptr;
}node;

class CP4_Tree{
public:
    node *root;
};

class CP4_Graph{
private:
    bool directed = false;


public:
    void BFS(int i);
    void DFS(int i);
    int topoVisit(int node, std::vector<int>& result);
    void addEdge(std::vector<int> &nodes);
    bool BFS_FindPath(int start, int end);
    std::vector<bool> *visit_record;
    std::vector<bool> *tempRecord;
    int nodes = 0;
    std::vector<std::vector<int>> listOfnodes;

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
    node* inOrderSucc(node* n);
    std::vector<int> DFS_Topological(CP4_Graph &graph);
    node* CommonAncestor(node* root, int val_left, int val_right);
    std::vector<std::vector<int>> allSequences(node* n);
};




#endif /* SRC_CP4_HPP_ */
