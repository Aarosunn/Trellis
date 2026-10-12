// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
  int characterReplacement(string s, int k) {
    int l = 0;
    int maxCount = 0;
    int maxLen = 0;
    unordered_map<char, int> cnt;

    for (int r = 0; r < s.size(); ++r) {
      cnt[s[r]]++;
      maxCount = max(maxCount, cnt[s[r]]);
      while (r - l + 1 - maxCount > k) {
        cnt[s[l]]--;
        ++l;
      }
      maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
  }
};
// @leet end
