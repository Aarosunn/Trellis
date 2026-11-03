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
  string frequencySort(string s) {
    vector<int> freq(128);
    for (auto &c : s)
      freq[c]++;

    sort(s.begin(), s.end(), [&freq](char c1, char c2) {
      int count1 = freq[c1];
      int count2 = freq[c2];
      return count1 != count2 ? count1 > count2 : c1 < c2;
    });

    return s;
  }
};
// @leet end
