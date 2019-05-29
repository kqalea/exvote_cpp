/*
 * cp2.cpp
 *
 *  Created on: May 23, 2019
 *      Author: kqalea
 */

#include"cp2.hpp"

void CP2::deleteDups(list<int>& linkedlist) {
    unordered_set<int> hashset;
    list<int>::iterator curr = linkedlist.begin();
    while (curr != linkedlist.end()) {
        if (hashset.count(*curr) > 0) {
            linkedlist.erase(curr);
        } else {
            hashset.insert(*curr);
        }
        curr++;
    }
    hashset.clear();
}

forward_list<int>::iterator CP2::nThToLast(forward_list<int>& flist, int k) {
    forward_list<int>::iterator p1 = flist.begin();
    forward_list<int>::iterator p2 = flist.begin();
    for (int i = 0; i < k; ++i) {
        if (p1 == flist.end())
            return (forward_list<int>::iterator) nullptr;
        ++p1;
    }
    while (p1 != flist.end()) {
        ++p1;
        ++p2;
    }
    return p2;
}

bool CP2::deleteNode(CP2_Node *node) {
    if (node == nullptr || node->next_node == nullptr) {
        return false;
    }
    CP2_Node *tmp_node = node->next_node;
    node->value = tmp_node->value;
    node->next_node = tmp_node->next_node;
    node->next_node->perv_node = node;
    delete tmp_node;
    return true;
}

void CP2::partitionList(list<int>& list, int x) {
    std::list<int> left;
    std::list<int> right;

    for (auto i : list) {
        if (i < x) {
            left.push_back(i);
        } else {
            right.push_back(i);
        }
    }
    list.clear();
    left.merge(right);
    list = left;

}

long CP2::addLists(list<int> &l1, list<int> &l2) {
    int number1, number2 = 0;
    list<int>::iterator it1 = l1.begin();
    list<int>::iterator it2 = l2.begin();
    int digit1 = l1.size();
    int digit2 = l1.size();
    while (it1 != l1.end()) {
        int t = *it1;
        number1 = number1 + (t * std::pow(10, digit1 - 1));
        it1++;
        digit1--;
    }
    cout << number1 << endl;
    while (it2 != l2.end()) {
        int t = *it2;
        number2 = number2 + (t * std::pow(10, digit2 - 1));
        it2++;
        digit2--;
    }
    cout << number2 << endl;
    return (number1 + number2);
}

bool CP2::isPalindrome(list<int>& list) {
    std::list<int>::iterator head = list.begin();
    std::list<int>::reverse_iterator tail = list.rbegin();
    int count = 0;
    bool flag = true;
    if (list.size() % 2 == 0) {
        count = list.size() / 2;
    } else {
        count = (list.size() - 1) / 2;
    }
    for (int i = 0; i < count; ++i) {
        std::cout << *head << " & " << *tail << endl;
        if (*head != *tail) {
            flag = false;
            break;
        }
        head++;
        tail++;
    }
    return flag;
}

CP2_Node* CP2::findIntersection(CP2_Node* list1, CP2_Node* list2) {
    if (list1 == nullptr || list2 == nullptr)
        return nullptr;
    CP2_Node* list1_head = list1;
    CP2_Node* list1_tail ;
    CP2_Node* list2_head = list2;
    CP2_Node* list2_tail ;

    int list1_size = 1;
    int list2_size = 1;
    CP2_Node* walker1 = list1_head;
    CP2_Node* walker2 = list2_head;
    cout << "check1" << endl;
    while (walker1->next_node != nullptr) {
        list1_size++;
        walker1 = walker1->next_node;
        cout << list1_size << ' ';
        cout << walker1 << endl;
    }
    list1_tail = walker1;
    cout << "check2" << endl;
    while (walker2->next_node != nullptr) {
        list2_size++;
        walker2 = walker2->next_node;
        cout << list2_size << ' ';
        cout << walker2 << endl;
    }
    list2_tail = walker2;

    CP2_Node* target = nullptr;
    walker1 = list1_head;
    walker2 = list2_head;
    if (list1_size > list2_size) {
        for (int i = 0; i < (list1_size - list2_size); i++) {
            walker1 = walker1->next_node;
        }
        for (int y = 0; y < list2_size; y++) {
            if (walker1 == walker2) {
                break;
            }
            walker1 = walker1->next_node;
            walker2 = walker2->next_node;
        }
        if (walker1 == walker2) target = walker1;
    } else {
        for (int i = 0; i < (list2_size - list1_size); i++) {
            walker2 = walker2->next_node;
        }
        for (int y = 0; y < list1_size; y++) {
            if (walker1 == walker2) {
                break;
            }
            walker1 = walker1->next_node;
            walker2 = walker2->next_node;
        }
        if (walker1 == walker2) target = walker1;
    }
    return target;
}

CP2_Node* CP2::findBeginning(CP2_Node* head){
    CP2_Node* fast = head;
    CP2_Node* slow = head;

    while(fast->next_node != nullptr && slow->next_node != nullptr){
        slow = slow->next_node;
        fast = fast->next_node->next_node;
        if(slow == fast){
            break;
        }
    }
    if(fast == nullptr || fast->next_node == nullptr){
        return nullptr;
    }
    slow = head;
    while(slow != fast){
        slow = slow->next_node;
        fast = fast->next_node;
    }
    return fast;

}

CP2_Node::CP2_Node() {
    this->next_node = nullptr;
    this->perv_node = nullptr;
}

CP2_Node::~CP2_Node() {
    this->next_node = nullptr;
    this->perv_node = nullptr;
}

CP2_Node* CP2_Node::toTail() {
    CP2_Node* tail;
    while (this->next_node != nullptr) {
        tail = this->next_node;
    }
    return tail;
}
