// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    int n = position.size();
    vector<pair<int, double>> posHours;
    for (int i = 0; i < n; ++i) {
      posHours.push_back(
          {position[i], (target - position[i]) / (double)speed[i]});
    }

    sort(posHours.begin(), posHours.end(),
         [](auto &left, auto &right) { return left.first < right.first; });

    stack<pair<int, double>> stk;
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && posHours[i].second >= stk.top().second) {
        stk.pop();
      }
      stk.push(posHours[i]);
    }
    return stk.size();
  }
};
// @leet end
