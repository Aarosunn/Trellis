// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;

    sort(nums.begin(), nums.end());

    while (l < r) {
      if (nums[l] + nums[r] == target)
        return {l, r};
      else if (nums[l] + nums[r] < target)
        ++l;
      else
        --r;
    }
    return {};
  }
};
// @leet end
