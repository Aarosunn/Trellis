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
  int numberOfSubstrings(string s) {
    vector<int> count(3);

    int l = 0, r = 0, substrings = 0;
    while (r < s.length()) {
      count[s[r] - 'a']++;

      while (all_of(count.begin(), count.end(), [](int i) { return i > 0; })) {
        substrings += s.length() - r;
        count[s[l++] - 'a']--;
      }
      ++r;
    }
    return substrings;
  }
};
// @leet end
