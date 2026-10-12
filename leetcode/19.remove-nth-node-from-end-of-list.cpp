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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy;
    dummy.next = head;
    ListNode *tail = &dummy;

    int length = 0;
    while (tail) {
      tail = tail->next;
      length++;
    }

    ListNode *cur = &dummy;
    int gap = 0;
    while (gap < length - n - 1) {
      cur = cur->next;
      gap++;
    }
    cur->next = cur->next->next;
    // cout << cur->val << '\n';
    // cout << length << ' ' << gap << '\n';
    return dummy.next;
  }
};
// @leet end
