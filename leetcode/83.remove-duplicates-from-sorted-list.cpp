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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head;
    while (cur && cur->next) {
      if (cur->val == cur->next->val)
        cur->next = cur->next->next;
      else
        cur = cur->next;
    }

    return head;

    // ListNode dummy;
    // ListNode *tail = &dummy;
    // while (head) {
    //   int nextVal = head->next ? head->next->val : head->val + 1;
    //   if (head->val != nextVal) {
    //     tail->next = head;
    //     tail = tail->next;
    //   }
    //   head = head->next;
    // }
    // return dummy.next;
  }
};
// @leet end
