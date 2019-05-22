#include<vector>
#include<stdint.h>
#include<string>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<iostream>

using namespace std;
class Topic {
public:
    vector<int32_t> twoSum(vector<int32_t>& numbers, int target);
    //cp1
    bool isUniqueChars(string& str);
    bool isPermutation(string& str1, string& str2);
    bool isPermutation_2(string& str1, string& str2);
    bool isPermutationOfPalindrome(string& str);
    bool isOneEditAway(string& str1, string& str2);
    bool isSubString(string& str1, string& str2);
    void matrixRotate(vector<vector<int>>& matrix);
    void setZeroMatrix(vector<vector<int>>& matrix);
    string replaceSpaces(string& str);
    string strCompress(string& str);
};
