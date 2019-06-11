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
