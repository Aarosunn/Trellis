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
  void printHelper(vector<int> &nums) {
    for (auto i : nums) {
      cout << i << " ";
    }
    cout << '\n';
  }

  void moveZeroes(vector<int> &nums) {

    int w = 0;
    for (int r = 0; r < nums.size(); ++r) {
      if (nums[r] != 0)
        swap(nums[w++], nums[r]);
    }
  }
};
// @leet end
