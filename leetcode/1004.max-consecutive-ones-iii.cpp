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
  int longestOnes(vector<int> &nums, int k) {
    int l = 0, r = 0;

    int zeroes = 0;
    int maxOnes = 0;
    while (r < nums.size()) {
      if (nums[r] == 0)
        zeroes++;

      while (zeroes > k)
        if (nums[l++] == 0)
          zeroes--;

      maxOnes = max(maxOnes, r - l + 1);

      ++r;
    }

    return maxOnes;
  }
};
// @leet end
