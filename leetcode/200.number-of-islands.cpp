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
  int numIslands(vector<vector<char>> &grid) {

    // variables
    // islandCount, bfs(queue)
    struct coords {
      int i;
      int j;
    };
    int islandCount = 0;
    std::queue<coords> bfs;
    int cols = grid[0].size();
    int rows = grid.size();
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    // loop through grid - check filled(skip) - fill - increase count
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == '0')
          continue;

        bfs.push(coords{i, j});
        grid[i][j] = '0';

        while (!bfs.empty()) {
          coords curr = bfs.front();
          bfs.pop();
          for (int d = 0; d < 4; ++d) {
            int ni = curr.i + dr[d], nj = curr.j + dc[d];
            if (ni < 0 || ni >= rows || nj < 0 || nj >= cols ||
                grid[ni][nj] != '1')
              continue;
            grid[ni][nj] = '0';
            bfs.push({ni, nj});
          }
        }
        ++islandCount;
      }
    }

    // return
    return islandCount;
  }
};
// @leet end
