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
  vector<vector<int>> adj;
  vector<int> state; // 0 untouched | 1 tracked | 2 finished

  bool dfs(int course) {

    state[course] = 1;

    for (auto &next : adj[course]) {
      if (state[next] == 1)
        return false;
      if (state[next] == 2)
        continue;
      if (!dfs(next))
        return false;
    }

    state[course] = 2;

    return true;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    adj.resize(numCourses);
    vector<int> indegree(numCourses, 0);
    queue<int> ready;
    int taken = 0;

    for (auto &e : prerequisites) {
      adj[e[1]].push_back(e[0]);
      indegree[e[0]]++;
    }

    for (int i = 0; i < numCourses; ++i)
      if (indegree[i] == 0)
        ready.push(i);

    while (!ready.empty()) {
      int course = ready.front();
      ready.pop();
      ++taken;
      for (auto &e : adj[course])
        if (--indegree[e] == 0)
          ready.push(e);
    }

    return taken == numCourses;

    // DFS
    // // Build adj list
    // adj.resize(numCourses);
    // state.resize(numCourses, 0);
    // for (auto &e : prerequisites)
    //   adj[e[0]].push_back(e[1]);
    //
    // // loop sweep call dfs
    // for (int i = 0; i < numCourses; ++i)
    //   if (state[i] == 0 && !dfs(i))
    //     return false;
    //
    // return true;
  }
};
// @leet end
