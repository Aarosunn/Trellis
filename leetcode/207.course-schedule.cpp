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
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);

    for (auto &e : prerequisites) {
      indegree[e[0]]++;
      adj[e[1]].push_back(e[0]);
    }

    queue<int> ready;

    for (int i = 0; i < numCourses; ++i)
      if (indegree[i] == 0)
        ready.push(i);

    while (!ready.empty()) {
      int course = ready.front();
      ready.pop();
      for (int next : adj[course])
        if (--indegree[next] == 0)
          ready.push(next);
    }
    for (auto &i : indegree)
      if (i != 0)
        return false;
    return true;
  }
};
// @leet end
