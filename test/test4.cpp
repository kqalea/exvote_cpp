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

TEST_CASE("CP4 CommonAncestor"){
    CP4 cp4;
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9};
    CP4_Tree tree = cp4.createMinimalBST(arr);
    node* answer = cp4.CommonAncestor(tree.root, 6, 9);

    REQUIRE(answer->val == 7);

}

TEST_CASE("CP4 BST_Sequences"){
    CP4 cp4;
    std::vector<int> arr = {1,2,3,4,5};
    CP4_Tree tree = cp4.createMinimalBST(arr);

    std::cout <<"BST_Sqeunces" <<std::endl;
    std::cout << "-------------------------\n";
    std::vector<std::vector<int>> answer2 = cp4.allSequences(tree.root);
    for(std::vector<std::vector<int>>::iterator it = answer2.begin(); it!= answer2.end(); ++it){
        std::vector<int> v = *it;
        for(std::vector<int>::iterator it2 = v.begin(); it2 != v.end(); ++it2){
            std::cout << *it2;
        }
        std::cout <<"\n";
    }


}

TEST_CASE("CP4 containsTree"){
    CP4 cp4;
    std::vector<int> arr;
    for(int i=0; i<10000; i++){
        arr.push_back(i);
    }
    CP4_Tree tree = cp4.createMinimalBST(arr);
    node* target = tree.root->left->left->right->left;
    std::cout << "val=" << target->val << "\n";

    REQUIRE(cp4.containsTree(tree.root, target));


}


void setup(std::vector<int>& arr, node* n){
    if(n != nullptr){
        arr.push_back(n->val);
        setup(arr, n->left);
        setup(arr, n->right);
    }
}

TEST_CASE("CP4 RandomNode"){
    CP4_TreeNode root(10);
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine randomEngine = std::default_random_engine(seed);
    std::uniform_int_distribution<int> dist(0, 20);
    int rand;

    std::vector<int> arr;
    for(int i=0;i<10;++i){
        arr.push_back(dist(randomEngine));
    }
    std::sort(arr.begin(), arr.end());
    CP4 cp4;
    CP4_Tree tree = cp4.createMinimalBST(arr);
    std::vector<int> target;
    setup(target, tree.root);
    CP4_TreeNode treeNode(target[0]);
    for(auto it = target.begin()+1; it != target.end(); ++it){
        treeNode.InsertInOrder(*it);
        std::cout << *it << "\n";
    }
    auto seed2 = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine randomEngine2 = std::default_random_engine(seed2);
    std::uniform_int_distribution<int> dist2(0, treeNode.size-1);

    std::cout << treeNode.getRandomNode(dist2(randomEngine2))->data << "\n";
    std::cout << treeNode.getRandomNode(dist2(randomEngine2))->data << "\n";
    std::cout << treeNode.getRandomNode(dist2(randomEngine2))->data << "\n";
    std::cout << treeNode.getRandomNode(dist2(randomEngine2))->data << "\n";
    std::cout << treeNode.getRandomNode(dist2(randomEngine2))->data << "\n";


}

TEST_CASE("CP4 PathOfSum"){
    node *root;
    node* tmp = new node;
    tmp->val = 10;
    root = tmp;
    tmp = new node;
    tmp->val = 5;
    root->left = tmp;
    tmp = new node;
    tmp->val = -3;
    root->right = tmp;
    tmp = new node;
    tmp->val = 3;
    root->left->left = tmp;
    tmp = new node;
    tmp->val = 2;
    root->left->right = tmp;
    tmp = new node;
    tmp->val = 11;
    root->right->right = tmp;
    tmp = new node;
    tmp->val = 3;
    root->left->left->left = tmp;
    tmp = new node;
    tmp->val = -2;
    root->left->left->right = tmp;
    tmp = new node;
    tmp->val = 1;
    root->left->right->right = tmp;

    CP4_PathOfSum ps;
    REQUIRE(ps.pathSum(root, 8) == 3);

}
