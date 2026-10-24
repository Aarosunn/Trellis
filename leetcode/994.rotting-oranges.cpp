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
  int orangesRotting(vector<vector<int>> &grid) {

    struct coords {
      int i;
      int j;
    };

    queue<coords> bfs;
    int minutes = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int fresh = 0, converted = 0;

    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == 1)
          ++fresh;
        if (grid[i][j] == 2)
          bfs.push(coords{i, j});
      }

    if (fresh == 0)
      return 0;

    while (!bfs.empty()) {
      int levelSize = bfs.size();
      for (int i = 0; i < levelSize; ++i) {
        coords curr = bfs.front();
        bfs.pop();
        for (int d = 0; d < 4; ++d) {
          int ni = curr.i + dr[d], nj = curr.j + dc[d];
          if (ni < 0 || ni >= rows || nj < 0 || nj >= cols || grid[ni][nj] != 1)
            continue;
          grid[ni][nj] = 2;
          ++converted;
          bfs.push(coords{ni, nj});
        }
      }
      if (!bfs.empty())
        ++minutes;
    }

    return converted == fresh ? minutes : -1;
  }
};
// @leet end
