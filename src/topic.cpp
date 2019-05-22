/*
 * topic.cpp
 *
 *  Created on: May 7, 2019
 *      Author: kqalea
 */

#include "topic.hpp"
#include <unordered_map>

vector<int32_t> Topic::twoSum(vector<int32_t> &numbers, int target) {
    unordered_map<int32_t, int32_t> table;
    vector<int32_t> result(2);
    int complement = 0;
    for (int32_t i = 0; i < (int32_t) numbers.size(); i++) {
        complement = target - numbers[i];
        if (table.count(complement) > 0) {
            result[0] = i;
            result[1] = table[complement];
            return result;
        }
        table.insert( { numbers[i], i });
    }
    throw invalid_argument("No Solution");
}

bool Topic::isUniqueChars(string& str){
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


bool Topic::isPermutation(string& str1, string& str2){
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

bool Topic::isPermutation_2(string& str1, string& str2){
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

bool Topic::isPermutationOfPalindrome(string& str){
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

bool Topic::isOneEditAway(string& str1, string& str2){
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

string Topic::replaceSpaces(string& str){
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


