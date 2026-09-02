// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
  int trap(vector<int> &height) {

    int l = 0, r = height.size() - 1;
    int water = 0;
    int maxL = height[l], maxR = height[r];
    while (l < r) {
      if (maxL <= maxR) {
        maxL = max(maxL, height[l]);
        water += maxL - height[l];
        ++l;
      } else {
        --r;
        maxR = max(maxR, height[r]);
        water += maxR - height[r];
      }
    }
    return water;
  }
};
// @leet end
