#include"../src/cp1.hpp"
#include"catch.hpp"

CP1 cp1;

TEST_CASE("cp1 isUniqueChars"){
    string str1 = "hello world";
    string str2 = "abcdefgh";
    REQUIRE(!cp1.isUniqueChars(str1));
    REQUIRE(cp1.isUniqueChars(str2));
}

TEST_CASE("cp1 isPermutation"){
    string str1 = "aabbccdd";
    string str2 = "bdcaabcd";
    string str3 = "areyouok";
    string str4 = "koareasd";
    REQUIRE(cp1.isPermutation(str1, str2));
    REQUIRE(!cp1.isPermutation(str3, str4));
    REQUIRE(cp1.isPermutation_2(str1, str2));
    REQUIRE(!cp1.isPermutation_2(str3, str4));
}

TEST_CASE("cp1 replaceSpaces"){
    string str1 = "Hi How Are You";
    string str2 = "Hi%20How%20Are%20You";
    string str3 = cp1.replaceSpaces(str1);
    REQUIRE(str3.compare(str2) == 0);
}

TEST_CASE("cp1 isPermutationOfPalindrome") {
    string str1 = "aabbccdd";
    string str2 = "abcdefgh";
    REQUIRE(cp1.isPermutationOfPalindrome(str1));
    REQUIRE(!cp1.isPermutationOfPalindrome(str2));
}


TEST_CASE("cp1 isOneEditAway"){
    string str1 = "pale";
    string str2 = "ple";
    string str3 = "pales";
    string str4 = "bale";
    string str5 = "bake";
    REQUIRE(cp1.isOneEditAway(str1, str2));
    REQUIRE(cp1.isOneEditAway(str3, str1));
    REQUIRE(cp1.isOneEditAway(str1, str4));
    REQUIRE(!cp1.isOneEditAway(str1, str5));
}

TEST_CASE("cp1 strCompress"){
    string str1 = "aabcccccaaa";
    string str2 = "2a1b5c3a";
    string str3 = cp1.strCompress(str1);
    REQUIRE(str2.compare(str3) == 0);
}

TEST_CASE("cp1 matrixRotate"){
    vector<vector<int>> fourbyfour = { { 1, 2, 3, 4},
                                       { 5, 6, 7, 8},
                                       { 9,10,11,12},
                                       {13,14,15,16} };
    vector<vector<int>> answer = { {13, 9, 5, 1},
                                   {14,10, 6, 2},
                                   {15,11, 7, 3},
                                   {16,12, 8, 4}};

    cp1.matrixRotate(fourbyfour);
    bool err = false;
    int x = answer.size();
    int y = answer[0].size();
    for(int i=0; i < x; ++i){
        if(err) break;
        for(int j=0; j < y; ++j){
            if(fourbyfour[i][j] != answer[i][j]){
                err = true;
                break;
            }
        }
    }
    REQUIRE(!err);
}

TEST_CASE("cp1 setZeroMatrix"){
    vector<vector<int>> target = { { 1, 1, 1, 0},
                                   { 1, 1, 1, 1},
                                   { 1, 0, 1, 1},
                                   { 1, 1, 0, 1} };

    vector<vector<int>> answer = { { 0, 0, 0, 0},
                                   { 1, 0, 0, 0},
                                   { 0, 0, 0, 0},
                                   { 0, 0, 0, 0} };
    cp1.setZeroMatrix(target);
    bool err = false;
    for(int i=0; i<target.size(); i++){
        for(int j=0; j<target[0].size(); j++){
            if(target[i][j] != answer[i][j]){
                err = true;
                break;
            }
        }
        if(err) break;
    }
    REQUIRE(!err);
}


TEST_CASE("cp1 isSubString"){
    string str1 = "abcdefg";
    string str2 = "cdefgab";
    REQUIRE(cp1.isSubString(str1, str2));
}
