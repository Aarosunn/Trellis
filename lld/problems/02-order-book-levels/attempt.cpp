#include <iostream>
#include <string>

void handle(const std::string &line) {
  // TODO
}

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    handle(line);
  }
}
