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

