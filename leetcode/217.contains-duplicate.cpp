// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> seen;

    for (int i : nums) {
      if (seen.count(i))
        return true;
      seen.insert(i);
    }
    return false;
  }
};
// @leet end
