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
  vector<int> topKFrequent(vector<int> &nums, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    unordered_map<int, int> counts;
    vector<int> res(k);

    for (int i = 0; i < nums.size(); ++i)
      counts[nums[i]]++;

    for (auto count : counts) {
      pq.push({count.second, count.first});
      if (pq.size() > k)
        pq.pop();
    }

    for (int i = 0; i < k; ++i) {
      res[i] = pq.top().second;
      pq.pop();
    }
    return res;
  }
};
// @leet end
