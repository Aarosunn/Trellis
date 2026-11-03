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
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size())
      return {};

    vector<int> res;
    vector<int> pCount(26);
    vector<int> windowCount(26);

    for (auto &c : p)
      pCount[c - 'a']++;

    int r = 0;
    for (; r + 1 < p.size(); ++r)
      windowCount[s[r] - 'a']++;
    for (; r < s.size(); ++r) {
      windowCount[s[r] - 'a']++;
      int l = r - p.size() + 1;
      if (pCount == windowCount)
        res.push_back(l);
      windowCount[s[l] - 'a']--;
    }

    return res;
  }
};
// @leet end
