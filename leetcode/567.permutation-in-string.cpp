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
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;

    vector<int> s1Count(26);
    vector<int> windowCount(26);
    for (auto &c : s1)
      s1Count[c - 'a']++;

    int r = 0;
    for (; r + 1 < s1.size(); ++r) {
      windowCount[s2[r] - 'a']++;
    }
    for (; r < s2.size(); ++r) {
      ++windowCount[s2[r] - 'a'];
      if (windowCount == s1Count)
        return true;
      --windowCount[s2[r - s1.size() + 1] - 'a'];
    }

    return false;
  }
};
// @leet end
