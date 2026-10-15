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
  int findMaxLength(vector<int> &nums) {
    int running = 0, maxLength = 0;
    unordered_map<int, int> seen;
    seen[0] = -1;

    for (int i = 0; i < nums.size(); ++i) {
      running += nums[i] ? 1 : -1;
      if (seen.count(running)) {
        int firstSeen = seen[running];
        maxLength = max(maxLength, i - firstSeen);
      } else {
        seen[running] = i;
      }
    }

    return maxLength;
  }
};
// @leet end
