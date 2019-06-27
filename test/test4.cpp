/*
 * test4.cpp
 *
 *  Created on: Jun 5, 2019
 *      Author: kqalea
 */


#include"catch.hpp"
#include"../src/cp4.hpp"

TEST_CASE("CP4 FindThePath"){
    CP4_Graph graph;
    std::vector<int> list = {1,2,3};
    graph.addEdge(list);//0

    list = {0,4,5,6};
    graph.addEdge(list);//1

    list = {0,5,6};
    graph.addEdge(list);//2

    list = {0,4};
    graph.addEdge(list);//3

    list = {0,1,3};
    graph.addEdge(list);//4

    list = {1,2};
    graph.addEdge(list);//5

    list = {1,2};
    graph.addEdge(list);//6
    graph.BFS(0);
    graph.DFS(0);
    std::cout << std::endl;
    REQUIRE(graph.BFS_FindPath(0,5));
    std::cout << std::endl;

}

TEST_CASE("CP4 Minimal Tree"){
    CP4 cp4;
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9};
    CP4_Tree tree = cp4.createMinimalBST(arr);
    cp4.inOrderTraversal(tree.root);
    std::cout << std::endl;
    cp4.postOrderTraversal(tree.root);
    std::cout << std::endl;
    cp4.preOrderTraversal(tree.root);
    std::cout << std::endl;
}

TEST_CASE("CP4 treeToListbyLevel"){
    CP4 cp4;
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9};
    CP4_Tree tree = cp4.createMinimalBST(arr);
    std::vector<std::vector<int>> list = cp4.treeToList(tree);
    for(auto x : list){
        for(auto y : x){
            std::cout << y <<" ";
        }
        std::cout << "\n";
    }

}

TEST_CASE("CP4 checkBalanced"){
    CP4 cp4;
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9};
    CP4_Tree tree = cp4.createMinimalBST(arr);
    REQUIRE(cp4.checkBalanced(tree.root));
    node* n = new node;
    tree.root->left->right->right->right = n;
    REQUIRE(!cp4.checkBalanced(tree.root));
}

TEST_CASE("CP4 checkBST"){
    CP4 cp4;
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9};
    CP4_Tree tree = cp4.createMinimalBST(arr);
    REQUIRE(cp4.checkBST(tree.root));
    node* n = new node;
    n->val = 100;
    tree.root->left->right->right->right = n;
    REQUIRE(!cp4.checkBST(tree.root));

}

TEST_CASE("CP4 inOrderSucc"){
    CP4 cp4;
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9};
    CP4_Tree tree = cp4.createMinimalBST(arr);
    node* target = tree.root->left->right;
    node* ans = cp4.inOrderSucc(target);
    REQUIRE(ans->val == 4);
    target = tree.root->left->right->right;
    ans = cp4.inOrderSucc(target);
    REQUIRE(ans->val == 5);
}

TEST_CASE("CP4 DFS_Topological"){
    CP4 cp4;
    CP4_Graph graph;
    std::vector<int> list = {1,2,3};
    graph.addEdge(list);//0
    list = {4,5,6};
    graph.addEdge(list);//1
    list = {6,7,8};
    graph.addEdge(list);//2
    list = {8,9,10};
    graph.addEdge(list);//3

    list = {-1};
    graph.addEdge(list);//4
    graph.addEdge(list);//5
    graph.addEdge(list);//6
    graph.addEdge(list);//7
    graph.addEdge(list);//8
    graph.addEdge(list);//9
    graph.addEdge(list);//10
    std::vector<int> answer = cp4.DFS_Topological(graph);
    std::cout << "TOPOLOGICAL!!\n";
    for(auto x : answer){
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}


