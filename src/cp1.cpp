/*
 * cp1.cpp
 *
 *  Created on: May 23, 2019
 *      Author: kqalea
 */
#include "cp1.hpp"

bool CP1::isUniqueChars(string& str){
    bool char_set[128] = {0};
    for(int32_t i = 0; i < (int32_t)str.length(); i++){
        int val = str.c_str()[i];
        if(char_set[val]){
            return false;
        }
        char_set[val] = true;
    }
    return true;
}


bool CP1::isPermutation(string& str1, string& str2){
    if(str1.length()!=str2.length()){
        return false;
    }
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    if(str1.compare(str2) == 0){
        return true;
    }
    return false;
}

bool CP1::isPermutation_2(string& str1, string& str2){
    if(str1.length()!=str2.length()){
            return false;
    }
    int char_set[128] = {0};
    for(int32_t i=0; i < str1.length(); i++){
        int val = str1[i];
        char_set[val] += 1;
    }
    for(int32_t i=0; i < str2.length(); i++){
        int val = str2[i];
        char_set[val] -= 1;
        if(char_set[val] < 0){
            return false;
        }
    }
    return true;

}

bool CP1::isPermutationOfPalindrome(string& str){
    bitset<26> char_set;
    int ascii = 0;
    for(int32_t i = 0; i<str.length(); i++){
        ascii = str[i];
        ascii -= 97;
        char_set.flip(ascii);
    }
    if(char_set.none()){
        return true;
    }else if ((char_set.to_ulong() & char_set.to_ulong()-1) == 0 ){
        return true;
    }
    return false;
}

bool CP1::isOneEditAway(string& str1, string& str2){
    int diff = std::abs((int)str1.length() - (int)str2.length());
    if ( diff > 1){
        return false;
    }
    string *longstr;
    string *shortstr;
    int longidx = 0;
    int shortidx = 0;
    bool flag = false;

    if (str1.length() >= str2.length()){
        longstr = &str1;
        shortstr = &str2;
    }else{
        longstr = &str2;
        shortstr = &str1;
    }
    while(longidx < longstr->length() & shortidx < shortstr->length()){
        if(longstr->c_str()[longidx] != shortstr->c_str()[shortidx]){
            if(flag) return false;
            flag = true;
            if(diff == 0){
                shortidx++;
            }
        }else{
            shortidx++;
        }
        longidx++;
    }
    return true;

}

bool CP1::isSubString(string& str1, string& str2){
    string str3 = str1 + str1;
    std::size_t found = str3.find(str2);
    if(found != std::string::npos){
        return true;
    }
    return false;
}

void CP1::matrixRotate(vector<vector<int>>& matrix){

    int side_length = matrix.size();
    int x = 0;
    int y = side_length -1;
    while(x<y){
        for(int i = 0; i<(y-x); ++i){
            std::swap(matrix[x][x+i], matrix[x+i][y]);
            std::swap(matrix[x][x+i], matrix[y][y-i]);
            std::swap(matrix[x][x+i], matrix[y-i][x]);
        }
        ++x;
        --y;
    }
}

void CP1::setZeroMatrix(vector<vector<int>>& matrix){
    bool isCol;
    int row = matrix.size();
    int col = matrix[0].size();

    for(int i = 0; i < row; i++){
        if(matrix[i][0] == 0){
            isCol = true;
        }
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int j = 0; j < col; j++){
            matrix[0][j] = 0;
        }
    }

    if(isCol){
        for(int i = 0; i < row; i++){
            matrix[i][0] = 0;
        }
    }
}

string CP1::replaceSpaces(string& str){
    int space_index = 0;
    int char_index = 0;
    int space_count = 0;
    vector<char> v_str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            space_count++;
            space_index = i;
        }else{
            char_index = i;
        }
    }
    int index = space_count*2 + char_index + 1 ;
    v_str.resize(index);
    for(; char_index>=0; char_index--){
        if(str[char_index] == ' '){
            v_str[index -1] = '0';
            v_str[index -2] = '2';
            v_str[index -3] = '%';
            index -= 3;
        }else{
            v_str[index-1] = str[char_index];
            index--;
        }
    }
    string answer(v_str.begin(), v_str.end());
    return answer;

}

string CP1::strCompress(string& str){
    string target;
    int compressedSize = 0;
    int countConsecutive = 0;
    for(int i=0;i<str.length();i++){
        countConsecutive++;
        if(i+1 >= str.length() || str[i] != str[i+1]){
            target.append(std::to_string(countConsecutive));
            target.append(str, i, 1);
            compressedSize = target.length();
            countConsecutive = 0;
        }
        if(compressedSize >= str.length()){
            return str;
        }
    }
    return target;

}
