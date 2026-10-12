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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy;
    ListNode *tail = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
      int a = l1 ? l1->val : 0;
      int b = l2 ? l2->val : 0;
      int s = a + b + carry;
      ListNode *newNode = new ListNode(s % 10);
      carry = s / 10;

      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
      tail->next = newNode;
      tail = tail->next;
    }

    return dummy.next;
  }
};
// @leet end
