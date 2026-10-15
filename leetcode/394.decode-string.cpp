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
    stack<pair<int, string>> stk;
    string cur = "";
    int k = 0;

    for (char c : s) {
      if (isdigit(c)) {
        k = k * 10 + (c - '0');
      } else if (c == '[') {
        stk.push({k, cur});
        cur.clear();
        k = 0;
      } else if (c == ']') {
        auto [times, before] = stk.top();
        stk.pop();
        string rep;
        while (times--)
          rep += cur;
        cur = before + rep;
      } else {
        cur += c;
      }
    }
    return cur;
  }
};
// @leet end
