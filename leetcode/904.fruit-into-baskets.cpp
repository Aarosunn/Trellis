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
  int totalFruit(vector<int> &fruits) {
    unordered_map<int, int> chosen;
    int maxLength = 0;

    int l = 0;
    for (int r = 0; r < fruits.size(); ++r) {

      chosen[fruits[r]]++;
      while (chosen.size() > 2) {
        if (--chosen[fruits[l]] == 0)
          chosen.erase(fruits[l]);
        ++l;
      }

      maxLength = max(maxLength, r - l + 1);
    }

    return maxLength;
  }
};
// @leet end
