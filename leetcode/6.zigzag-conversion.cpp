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
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    string ans = "";
    int numCols = s.size();
    vector<string> zigzag = vector(numRows, string(""));

    int index = 0, row = 0, col = 0;
    while (index < s.size()) {
      for (; index < s.size() && row < numRows; ++row)
        zigzag[row] += s[index++];

      row -= 2;

      while (index < s.size() && row > 0)
        zigzag[row--] += s[index++];
    }

    for (row = 0; row < numRows; ++row)
      ans += zigzag[row];

    return ans;
  }
};
// @leet end
