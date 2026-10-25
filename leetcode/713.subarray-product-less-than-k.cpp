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
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int count = 0;
    int n = nums.size();

    int l = 0;
    int product = 1;
    for (int r = 0; r < n; ++r) {
      product *= nums[r];
      while (l <= r && product >= k)
        product /= nums[l++];
      count += r - l + 1;
    }
    return count;
  }
};
// @leet end
