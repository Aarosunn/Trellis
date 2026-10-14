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
  int rob(vector<int> &nums) {
    vector<int> dp(nums.size() + 1);
    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= nums.size(); ++i)
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);

    return dp[nums.size()];
  }
};
// @leet end
