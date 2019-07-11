/*
 * cp4.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: kqalea
 */

#include"cp4.hpp"


void CP4::visit(node* target){
    std::cout << target->val << ", ";
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

std::vector<std::vector<int>> CP4::treeToList(CP4_Tree& tree){
   std::vector<std::vector<int>> arr;
   treeToList(tree.root, 0, arr);
   return arr;
}

void CP4::treeToList(node* root, int level, std::vector<std::vector<int>> &arr){
    if(root == nullptr) return;
    std::vector<int> tmp;
    if(arr.size() == level){
        tmp.push_back(root->val);
        arr.push_back(tmp);
    }else{
        arr[level].push_back(root->val);
    }
    treeToList(root->left, level+1, arr);
    treeToList(root->right, level+1, arr);
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
    if(root->left != nullptr) root->left->parent = root;
    root->right = createMinimalBST(arr, mid + 1, end);
    if(root->right != nullptr) root->right->parent = root;
    return root;
}

bool CP4::checkBalanced(node* root){
    int result = checkHeight(root);
    if(result == INT_MIN){
        return false;
    }else{
        return true;
    }
}

int CP4::checkHeight(node* root){
    if(root == nullptr) return -1;
    int leftHeight = checkHeight(root->left);
    if(leftHeight == INT_MIN) return INT_MIN;
    int rightHeight = checkHeight(root->right);
    if(rightHeight == INT_MIN) return INT_MIN;
    int hightdiff = std::abs(leftHeight - rightHeight);
    if(hightdiff > 1){
        return INT_MIN;
    }else{
        return std::max(leftHeight, rightHeight) +1;
    }
}

bool CP4::checkBST(node* root){
    return checkBST(root, INT_MIN, INT_MAX);
}

bool CP4::checkBST(node* root, int min, int max){
    if(root == nullptr) return true;
    if( (min != INT_MIN && root->val <= min ) || (max != INT_MAX && root-> val > max)){
        return false;
    }
    if( (!checkBST(root->left ,min, root->val)) || (!checkBST(root->right, root->val, max)) ) {
        return false;
    }
    return true;

}

node* CP4::inOrderSucc(node* n){
    if(n == nullptr) return nullptr;
    if(n->right != nullptr){
        n = n->right;
        while(n->left != nullptr){
            n = n->left;
        }
        return n;
    }else{
        node* q = n;
        node* x = q->parent;
        while(x != nullptr && x->left != q){
            q = x;
            x = x->parent;
        }
        return x;
    }
}


int CP4_Graph::topoVisit(int node, std::vector<int>& result){
    if(this->visit_record->at(node) == true) return 0;
    //if(this->tempRecord->at(node) == true) return -1;
    this->tempRecord->at(node) = true;
    for(std::vector<int>::iterator it = listOfnodes[node].begin(); it != listOfnodes[node].end(); ++it){
        if(*it < 0) continue;
        topoVisit((int)*it, result);
    }

    this->tempRecord->at(node) = false;
    this->visit_record->at(node) = true;
    result.insert(result.begin(),node);
    return 0;

}

std::vector<int> CP4::DFS_Topological(CP4_Graph &graph){

    graph.visit_record = new std::vector<bool>(graph.nodes, false);
    graph.tempRecord = new std::vector<bool>(graph.nodes, false);
    std::vector<int> result;
    int size = graph.nodes;
    int node = 0;
    if(graph.topoVisit(node, result) == 0){
        return result;
    }else{
        result.clear();
        return result;
    }
}

node* CP4::CommonAncestor(node* root, int val_left, int val_right){
    if(root == nullptr) return nullptr;
    if(root->val == val_left && root->val == val_right) return root;

    node* node_x = CommonAncestor(root->left, val_left, val_right);
    if(node_x != nullptr && node_x->val != val_left && node_x->val != val_right){
        return node_x;
    }

    node* node_y = CommonAncestor(root->right, val_left, val_right);
    if(node_y != nullptr && node_y->val != val_left && node_y->val != val_right){
        return node_y;
    }

    if(node_x != nullptr && node_y != nullptr){
        return root;
    }else if((root->val == val_left) || (root->val == val_right)){
        return root;
    }else{
        return node_x == nullptr ? node_y : node_x;
    }
}

std::vector<std::vector<int>> CP4::allSequences(node* n){

    if(n == nullptr){
        std::vector<std::vector<int>> v;
        std::vector<int> seq;
        v.push_back(seq);
        return v;
    }

    if(n->left == nullptr && n->right == nullptr){
        std::vector<int> seq;
        seq.push_back(n->val);
        std::vector<std::vector<int>> v;
        v.push_back(seq);
        return v;
    }

    std::vector<std::vector<int>> results, left, right;
    left = allSequences(n->left);
    right = allSequences(n->right);
    int size = left[0].size() + right[0].size() + 1;

    std::vector<bool>flags(left[0].size(), false);
    for(int k=0; k<right[0].size(); ++k){
        flags.push_back(true);
    }
    for(int i=0; i<left.size(); i++){
        for(int j=0; j<right.size(); j++){
            do{
                std::vector<int> tmp(size);
                tmp[0] = n->val;
                int l=0, r=0;
                for(int z=0; z<flags.size();z++){
                    tmp[z+1] = (flags[z]) ? right[j][r++] : left[i][l++];
                }
                results.push_back(tmp);
            }while(std::next_permutation(flags.begin(), flags.end()));
        }
    }
    return results;
}

bool matchTree(node* t1, node* t2){
    if(t1 == nullptr && t2 == nullptr){
        return true;
    }else if(t1 == nullptr || t2 == nullptr){
        return false;
    }else if(t1->val != t2->val){
        return false;
    }else{
        return matchTree(t1->left, t2->left);
    }
}

bool subtree(node* t1, node* t2){
    if(t1 == nullptr){
        return false;
    }else if(t1->val == t2->val && matchTree(t1, t2)){
        return true;
    }
    return subtree(t1->left,t2) || subtree(t1->right,t2);
}

bool CP4::containsTree(node* t1, node* t2){
    if(t2 == nullptr) return true;
    return subtree(t1, t2);
}

CP4_TreeNode* CP4_TreeNode::getRandomNode(int i){
    return getIthNode(i);
}

CP4_TreeNode* CP4_TreeNode::getIthNode(int i){
    int leftsize = this->leftNode == nullptr ? 0 : this->leftNode->size;
    if(i < leftsize){
        return leftNode->getIthNode(i);
    }else if(i == leftsize) {
        return this;
    }else{
        return rightNode->getIthNode(i-(leftsize+1));
    }
}

void CP4_TreeNode::InsertInOrder(int i){
    if(i <= this->data){
        if(this->leftNode == nullptr){
            this->leftNode = new CP4_TreeNode(i);
        }else{
            this->leftNode->InsertInOrder(i);
        }
    }else{
        if(this->rightNode == nullptr){
            this->rightNode = new CP4_TreeNode(i);
        }else{
            this->rightNode->InsertInOrder(i);
        }
    }
    this->size++;
}


