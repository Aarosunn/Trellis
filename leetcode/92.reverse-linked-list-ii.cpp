// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode dummy(0, head);
    ListNode *prev = &dummy;
    ListNode *curr = head;

    int count = 1;
    while (curr && count < left) {
      prev = curr;
      curr = curr->next;
      ++count;
    }
    count = 0;
    ListNode *first = prev;
    ListNode *last = curr;
    while (curr && count < right - left + 1) {
      ListNode *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
      ++count;
    }
    last->next = curr;
    first->next = prev;

    return dummy.next;
  }
};
// @leet end
