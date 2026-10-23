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

    int l = m - 1, r = n - 1, back = m + n - 1;
    while (r >= 0) {
      if (l < 0 || nums2[r] > nums1[l])
        nums1[back--] = nums2[r--];
      else
        nums1[back--] = nums1[l--];
    }
  }
};
// @leet end
