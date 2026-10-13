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
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {

    if (nums2.empty())
      return;
    else if (m == 0) {
      nums1 = nums2;
      return;
    }

    int ptr1 = m - 1, ptr2 = n - 1, back = m + n - 1;
    while (ptr2 >= 0) {
      if (ptr1 < 0 || nums2[ptr2] > nums1[ptr1])
        nums1[back--] = nums2[ptr2--];
      else
        nums1[back--] = nums1[ptr1--];
    }
  }
};
// @leet end
