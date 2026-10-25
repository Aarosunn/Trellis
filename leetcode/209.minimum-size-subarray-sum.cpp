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
  int minSubArrayLen(int target, vector<int> &nums) {
    int l = 0, r = 0, sum = 0;
    int len = nums.size() + 1;

    for (int r = 0; r < nums.size(); ++r) {
      sum += nums[r];
      while (sum >= target) {
        len = min(len, r - l + 1);
        sum -= nums[l++];
      }
    }

    return len == nums.size() + 1 ? 0 : len;
  }
};
// @leet end
