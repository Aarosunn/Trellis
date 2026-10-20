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
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    vector<int> order;
    queue<int> ready;

    // Build Adjacency List
    for (auto &edge : prerequisites) {
      adj[edge[1]].push_back(edge[0]);
      indegree[edge[0]]++;
    }

    // Find nodes with indegree 0
    for (int i = 0; i < numCourses; ++i)
      if (indegree[i] == 0)
        ready.push(i);

    // BFS
    while (!ready.empty()) {
      int course = ready.front();
      ready.pop();
      order.push_back(course);

      for (auto &e : adj[course])
        if (--indegree[e] == 0)
          ready.push(e);
    }

    vector<int> empty;
    return order.size() == numCourses ? order : empty;
  }
};
// @leet end
