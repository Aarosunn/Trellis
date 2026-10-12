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
  double findMaxAverage(vector<int> &nums, int k) {
    double sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += nums[i];
    }

    double maxSum = sum;
    for (int i = k; i < nums.size(); ++i) {
      sum += (nums[i] - nums[i - k]);
      maxSum = max(maxSum, sum);
    }

    return maxSum / k;
  }
};
// @leet end
