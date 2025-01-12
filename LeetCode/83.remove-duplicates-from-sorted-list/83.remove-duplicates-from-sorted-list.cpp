/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// struct ListNode
// {
//     int val;
//     ListNode * next;
//     ListNode()
//         : val(0)
//         , next(nullptr)
//     {
//     }
//     ListNode(int x)
//         : val(x)
//         , next(nullptr)
//     {
//     }
//     ListNode(int x, ListNode * next)
//         : val(x)
//         , next(next)
//     {
//     }
// };

class Solution
{
public:
    ListNode * deleteDuplicates(ListNode * head)
    {
        ListNode * current = head;
        ListNode * iter;

        for (; current; current = current->next)
        {
            int number = current->val;
            for (iter = current->next; iter; iter = iter->next)
                if (iter->val != number)
                    break;
            current->next = iter;
        }

        return head;
    }
};
// @lc code=end
