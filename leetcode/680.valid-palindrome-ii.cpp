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
  bool skipped = false;

public:
  bool isPalindrome(const string &s, int l, int r) {
    while (l <= r) {
      if (s[l] == s[r]) {
        ++l;
        --r;
        continue;
      } else if (!skipped) {
        skipped = true;
        return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
      } else {
        return false;
      }
    }
    return true;
  }

  bool validPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    return isPalindrome(s, l, r);
  }
};
// @leet end
