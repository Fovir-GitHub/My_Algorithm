#include <algorithm>
#include <iostream>

struct ListNode
{
    int        val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

// class Solution
// {
// public:
//     ListNode * addTwoNumbers(ListNode * l1, ListNode * l2)
//     {
//         ListNode * root = new ListNode;
//         ListNode * current = root;
//         int add_number = 0;
//         int next_add_number = 0;

//         while (l1 && l2)
//         {
//             add_number = l1->val + l2->val + next_add_number;
//             next_add_number = add_number / 10;

//             ListNode * new_node = new ListNode(add_number % 10);
//             current->next = new_node;
//             current = current->next;
//             l1 = l1->next;
//             l2 = l2->next;
//         }

//         while (l1)
//         {
//             add_number = l1->val + next_add_number;
//             next_add_number = add_number / 10;

//             ListNode * new_node = new ListNode(add_number % 10);
//             current->next = new_node;
//             current = current->next;
//             l1 = l1->next;
//         }

//         while (l2)
//         {
//             add_number = l2->val + next_add_number;
//             next_add_number = add_number / 10;

//             ListNode * new_node = new ListNode(add_number % 10);
//             current->next = new_node;
//             current = current->next;
//             l2 = l2->next;
//         }

//         if (next_add_number)
//             current->next = new ListNode(next_add_number);

//         return root->next;
//     }
// };

class Solution
{
public:
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2)
    {
        ListNode * root            = new ListNode;
        ListNode * current         = root;
        int        add_number      = 0;
        int        next_add_number = 0;

        while (l1 || l2 || next_add_number)
        {
            int digit1 = (l1 ? l1->val : 0);
            int digit2 = (l2 ? l2->val : 0);

            add_number      = digit1 + digit2 + next_add_number;
            next_add_number = add_number / 10;

            ListNode * new_node = new ListNode(add_number % 10);
            current->next       = new_node;
            current             = current->next;

            l1 = (l1 ? l1->next : nullptr);
            l2 = (l2 ? l2->next : nullptr);
        }

        return root->next;
    }
};