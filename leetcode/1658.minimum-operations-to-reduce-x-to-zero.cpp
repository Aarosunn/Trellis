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
  int minOperations(vector<int> &nums, int x) {
    int total = 0, n = nums.size();
    for (auto i : nums)
      total += i;
    int target = total - x;

    int l = 0, sum = 0, maxLen = -1;
    for (int r = 0; r < nums.size(); ++r) {
      sum += nums[r];

      while (l <= r && sum > target)
        sum -= nums[l++];

      if (sum == target) {
        maxLen = max(maxLen, r - l + 1);
      }
    }
    return maxLen == -1 ? -1 : n - maxLen;
  }
};
// @leet end
