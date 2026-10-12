// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

#include <bits/stdc++.h>
using namespace std;

// @leet start
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
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *curr = head;
    ListNode *temp = reverseList(curr->next);
    curr->next->next = curr;
    curr->next = nullptr;
    return temp;

    //   ListNode *curr = head;
    //   ListNode *prev = nullptr;
    //
    //   while (curr) {
    //     ListNode *temp = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = temp;
    //   }
    //
    //   return prev;
  }
};
// @leet end
