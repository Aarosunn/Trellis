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
  int subarraySum(vector<int> &nums, int k) {
    int subarrays = 0;
    int prevSum = 0;
    unordered_map<int, int> count;
    count[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      prevSum += nums[i];
      subarrays += count[prevSum - k];
      count[prevSum]++;
    }

    return subarrays;
  }
};
// @leet end
