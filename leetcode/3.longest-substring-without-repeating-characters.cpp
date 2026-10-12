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
  int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0;
    int maxLength = 0;
    unordered_map<char, int> seen;

    while (r < s.length()) {
      seen[s[r]]++;
      while (seen[s[r]] > 1)
        seen[s[l++]]--;

      maxLength = max(maxLength, r - l + 1);
      ++r;
    }
    return maxLength;
  }
};
// @leet end
