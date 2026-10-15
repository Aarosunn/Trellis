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
  string decodeString(string s) {
    int count = 0;
    stack<pair<int, string>> stk;
    int l = 0;
    string ans = "";
    string partial = "";
    string prevPartial = "";
    bool isNested = false;

    while (l < s.length()) {
      if (isdigit(s[l])) {
        count = count * 10 + (s[l] - '0');
      } else if (s[l] == '[') {
        stk.push({count, partial});
        partial = "";
        count = 0;
      } else if (s[l] == ']') {
        auto res = stk.top();
        stk.pop();
        prevPartial = res.second;
        for (int i = 0; i < res.first; ++i)
          prevPartial += partial;
        partial = prevPartial;
      } else {
        partial += s[l];
      }
      ++l;
    }
    ans += partial;

    return ans;
  }
};
// @leet end
