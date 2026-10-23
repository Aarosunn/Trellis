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
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> adj(n);
    vector<int> indegree(n);

    for (int i = 0; i < n; ++i)                   // node
      for (int j = 0; j < graph[i].size(); ++j) { // outgoing edge
        adj[graph[i][j]].push_back(i);
        indegree[i]++;
      }

    // cout << "[";
    // for (int i = 0; i < n; ++i) {
    //   cout << "[";
    //   for (int j = 0; j < adj[i].size(); ++j) {
    //     cout << adj[i][j];
    //     if (j < adj[i].size() - 1)
    //       cout << ",";
    //   }
    //   cout << "]";
    //   if (i < n - 1)
    //     cout << ",";
    // }
    // cout << "]";

    queue<int> bfs;
    vector<int> res;

    for (int i = 0; i < n; ++i)
      if (indegree[i] == 0)
        bfs.push(i);

    while (!bfs.empty()) {
      int cur = bfs.front();
      bfs.pop();
      res.push_back(cur);

      for (auto &edge : adj[cur])
        if (--indegree[edge] == 0)
          bfs.push(edge);
    }
    sort(res.begin(), res.end());
    return res;
  }
};
// @leet end
