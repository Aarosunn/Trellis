#include <algorithm>
#include <cctype>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  os << p.first << ": " << p.second;
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto &e : v) {
    os << e << " ";
  }
  os << '\n';
  return os;
}

void sumOfDigitChars(const string &s) {
  int sum = 0;
  for (auto &c : s)
    if (isdigit(c))
      sum += c - '0';
  cout << sum << '\n';
}

void swapCase(const string &s) {
  string res = "";
  for (auto &c : s)
    res += isupper(c) ? tolower(c) : toupper(c);

  cout << res << '\n';
}

void addStrings(const string &s1, const string &s2) {
  try {
    int sum = stoi(s1) + stoi(s2);
    string ans = to_string(sum) += " is the answer\n";
    cout << ans;
  } catch (const invalid_argument &e) {
    cout << "error: pass in strings of ints into parameter\n";
  }
}

void sortByLength(vector<string> v) {
  sort(v.begin(), v.end(), [](const string &s1, const string &s2) {
    return s1.size() != s2.size() ? s1.size() > s2.size() : s1 < s2;
  });
  cout << v;
}

void sortByCharFreq(string s) {
  vector<int> freq(26);
  for (auto &c : s)
    freq[c - 'a']++;

  sort(s.begin(), s.end(), [&freq](char c1, char c2) {
    int count1 = freq[c1 - 'a'];
    int count2 = freq[c2 - 'a'];
    return count1 == count2 ? c1 < c2 : count1 > count2;
  });
  cout << s << '\n';
}

void sortPairBySecond(vector<pair<string, int>> leaderboard) {
  sort(leaderboard.begin(), leaderboard.end(),
       [](const pair<string, int> &p1, const pair<string, int> &p2) {
         return p1.second == p2.second ? p1.first < p2.first
                                       : p1.second > p2.second;
       });
  cout << leaderboard;
}

int main() {
  cout << "Hello World!\n";
  sumOfDigitChars("a1b2c3");
  swapCase("HeLLo 42");
  addStrings("42", "673");
  addStrings("1", "abc");
  sortByLength(vector<string>{"bb", "a", "ccc", "ab"});
  sortByCharFreq("cccaaab");
  sortByCharFreq("tree");
  sortPairBySecond(
      vector<pair<string, int>>{{"Bob", 5}, {"Amy", 9}, {"Cal", 5}});
}
