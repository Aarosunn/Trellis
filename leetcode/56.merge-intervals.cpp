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
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    int startmerge = intervals[0][0];
    int endmerge = intervals[0][1];
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= endmerge) {
        endmerge = max(endmerge, intervals[i][1]);
      } else {
        res.push_back({startmerge, endmerge});
        startmerge = intervals[i][0];
        endmerge = intervals[i][1];
      }
    }
    res.push_back({startmerge, endmerge});

    return res;
  }
};
// @leet end
