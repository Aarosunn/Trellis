
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

int main() {
  std::ios::sync_with_stdio(false);
  std::unordered_map<std::string, long long> map;

  std::string line;
  while (std::getline(std::cin, line)) {
    std::istringstream in(line);
    std::string cmd;

    if (!(in >> cmd))
      continue; // if blank, skip

    std::string extra;
    std::string key;
    if (cmd == "SET") {

      long long val;
      if (!(in >> key >> val) || (in >> extra)) {
        std::cout << "E1\n";
        continue;
      }
      // SET stuff
      std::cout << "OK\n";
      map[key] = val;

    } else if (cmd == "GET") {

      if (!(in >> key) || (in >> extra)) {
        std::cout << "E1\n";
        continue;
      }
      // GET stuff
      if (map.count(key)) {
        long long val = map[key];
        std::cout << val << '\n';
      } else {
        std::cout << "E2\n";
      }

    } else if (cmd == "ADD") {

      long long delta;
      if (!(in >> key >> delta) || (in >> extra)) {
        std::cout << "E1\n";
        continue;
      }
      // ADD Stuff
      if (map.count(key)) {
        long long newVal = map[key] + delta;
        map[key] = newVal;
        std::cout << newVal << '\n';

      } else {
        std::cout << "E2\n";
      }
    } else {
      std::cout << "E1\n";
    }
  }
}
