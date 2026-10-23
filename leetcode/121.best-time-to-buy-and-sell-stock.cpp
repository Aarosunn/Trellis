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
  int maxProfit(vector<int> &prices) {
    int l = 0, r = 1;
    int runningProfit = 0;
    while (r < prices.size()) {
      if (prices[r] < prices[l]) {
        l = r++;
      } else {
        runningProfit = max(runningProfit, prices[r] - prices[l]);
        ++r;
      }
    }
    return runningProfit;
  }
};
// @leet end
