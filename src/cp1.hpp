/*
 * cp1.hpp
 *
 *  Created on: May 23, 2019
 *      Author: kqalea
 */

#ifndef SRC_CP1_HPP_
#define SRC_CP1_HPP_

#include<vector>
#include<stdint.h>
#include<string>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<iostream>

using namespace std;

class CP1 {
public:
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


#endif /* SRC_CP1_HPP_ */
