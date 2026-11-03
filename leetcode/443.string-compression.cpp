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
  int compress(vector<char> &chars) {
    int l = 0, r = 0, index = 0, n = chars.size();

    while (l < n) {
      while (r < n && chars[r] == chars[l])
        ++r;
      chars[index++] = chars[l];
      int count = r - l;
      if (count != 1)
        for (auto &c : to_string(count))
          chars[index++] = c;
      l = r;
    }
    return index;
  }
};
// @leet end
