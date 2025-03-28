/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start

// struct ListNode
// {
//     int        val;
//     ListNode * next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode * next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode * reverse(ListNode * node)
    {
        ListNode * current  = node;
        ListNode * previous = nullptr;

        while (current)
        {
            ListNode * backup_next = current->next;
            current->next          = previous;
            previous               = current;
            current                = backup_next;
        }

        return previous;
    }

    bool isPalindrome(ListNode * head)
    {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * reversed_list = reverse(slow);

        for (; head && reversed_list;
             head = head->next, reversed_list = reversed_list->next)
            if (head->val != reversed_list->val)
                return false;

        return true;
    }
};
// @lc code=end
