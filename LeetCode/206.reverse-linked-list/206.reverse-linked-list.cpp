/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode * reverseList(ListNode * head) {
        ListNode * previous = nullptr;

        while (head) {
            ListNode * backup_next = head->next;
            head->next = previous;
            previous = head;
            head = backup_next;
        }

        return previous;
    }

    // ListNode * reverseList(ListNode * head)
    // {
    //     if (!head || !head->next)
    //         return head;

    //     ListNode * previous          = nullptr;
    //     ListNode * next_reverse_node = reverseList(head->next);
    //     head->next->next             = head;
    //     head->next                   = previous;
    //     return next_reverse_node;
    // }
};
// @lc code=end
