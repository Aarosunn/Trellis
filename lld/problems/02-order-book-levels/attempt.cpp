#include <charconv>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

/*
 * Notes:
 *
 * Maintain Book and level queries
 * E5 order that would trade against the opposite side
 * need to use long long for values, decimal integer
 *
 * Requirements:
 * 1. primary capabilities
 * 2. error handling
 * 3. scope boundaries
 *
 * Datastructure to keep track of orders, fast update, fast queries
 * ADD, CANCEL, MODIFY - structural commands
 * BEST, DEPTH - query commands
 *
 * id not reused, continuously incremented, error does not use id
 *
 * Error handling:
 * E1, E2: IO errors
 * E3, E4: ID errors
 * E5: Application error
 * empty oppsoite side does not trigger E5
 * print lowest one
 * DEPTH range check
 * input: blank lines, case-sensitive
 *
 * Out of scope:
 * - Matching Orders
 *
 * Entities:
 * - IO handling
 * - Book(queries reside inside book)
 *
 * Class Design:
 *
 * Book needs to support all the commands
 * Handle E3, E4, E5
 * Hold the datastructure to keep track
 *
 */

constexpr long long MAX_THRESHOLD = 1'000'000'000;      // 10^9
constexpr long long MAX_ID = 1'000'000'000'000'000'000; // 10^18
void E1() { std::cout << "E1\n"; }
void E2() { std::cout << "E2\n"; }
void E3() { std::cout << "E3\n"; }
void E4() { std::cout << "E4\n"; }
void E5() { std::cout << "E5\n"; }

struct Order {
  std::string side;
  long long price;
  long long qty;
};

struct Level {
  long long qty;
  long long orderCount;
};

class OrderBook {
  std::unordered_map<long long, Order> orders;
  std::unordered_set<long long> usedIDS;
  std::map<long long, Level, std::greater<long long>> bids;
  std::map<long long, Level> asks;

public:
  OrderBook() {}

  void add(long long id, Order order) {
    // Handle Duplicate ID
    auto it = usedIDS.find(id);
    if (it != usedIDS.end()) {
      E4();
      return;
    }
    // Cross logic
    if (order.side == "S") {
      if (!bids.empty() && order.price <= bids.begin()->first) {
        E5();
        return;
      }

      auto it = asks.find(order.price);
      if (it == asks.end()) {
        asks[order.price] = Level{order.qty, 1};
      } else {
        it->second.qty += order.qty;
        it->second.orderCount++;
      }

    } else if (order.side == "B") {
      if (!asks.empty() && order.price >= asks.begin()->first) {
        E5();
        return;
      }

      auto it = bids.find(order.price);
      if (it == bids.end()) {
        bids[order.price] = Level{order.qty, 1};
      } else {
        it->second.qty += order.qty;
        it->second.orderCount++;
      }
    }
    // Add Order & Add ID
    orders[id] = order;
    usedIDS.insert(id);
    std::cout << "OK\n";
  }

  void cancel(long long id) {
    // Unknown ID
    auto it = orders.find(id);
    if (it == orders.end()) {
      E3();
      return;
    }
    // Update Level
    if (it->second.side == "S") {
      auto levelIt = asks.find(it->second.price);
      levelIt->second.qty -= it->second.qty;
      if (--levelIt->second.orderCount == 0)
        asks.erase(levelIt);
    } else if (it->second.side == "B") {
      auto levelIt = bids.find(it->second.price);
      levelIt->second.qty -= it->second.qty;
      if (--levelIt->second.orderCount == 0)
        bids.erase(levelIt);
    }
    // Erase entry
    orders.erase(it);
    std::cout << "OK\n";
  }

  void modify(long long id, long long qty) {
    // Unknown ID
    auto it = orders.find(id);
    if (it == orders.end()) {
      E3();
      return;
    }
    // modify levels
    if (it->second.side == "S") {
      auto levelIt = asks.find(it->second.price);
      levelIt->second.qty += (qty - it->second.qty);
    } else if (it->second.side == "B") {
      auto levelIt = bids.find(it->second.price);
      levelIt->second.qty += (qty - it->second.qty);
    }
    // modify order
    it->second.qty = qty;
    std::cout << "OK\n";
  }

  void best() {
    // print best
    auto bestBid = bids.begin();
    auto bestAsk = asks.begin();
    std::cout << "BEST ";
    if (bestBid != bids.end())
      std::cout << bestBid->first << 'x' << bestBid->second.qty << ' ';
    else
      std::cout << "- ";

    if (bestAsk != asks.end())
      std::cout << bestAsk->first << 'x' << bestAsk->second.qty;
    else
      std::cout << "-";

    std::cout << '\n';
  }

  void depth(long long k) {
    // print best ks for each side
    std::cout << "BID";
    int printed = 0;
    auto it = bids.begin();
    if (it == bids.end())
      std::cout << " -";
    for (; it != bids.end() && printed < k; ++it, ++printed) {
      std::cout << ' ' << it->first << ':' << it->second.qty << ':'
                << it->second.orderCount;
    }
    std::cout << '\n';

    std::cout << "ASK";
    auto it2 = asks.begin();
    if (it2 == asks.end())
      std::cout << " -";
    printed = 0;
    for (; it2 != asks.end() && printed < k; ++it2, ++printed) {
      std::cout << ' ' << it2->first << ':' << it2->second.qty << ':'
                << it2->second.orderCount;
    }
    std::cout << '\n';
  }
};

OrderBook ob;

bool within_bounds(long long val, long long threshold) {
  if (val < 1 || val > threshold) {
    E2();
    return false;
  }
  return true;
}

bool parseNum(const std::string &s, long long &out) {
  auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), out);
  return ec == std::errc{} && ptr == s.data() + s.size();
}

void handle(const std::string &line) {
  std::istringstream in(line);
  std::string cmd;

  // blank line skip
  if (!(in >> cmd))
    return;

  std::string idTok, qtyTok, extra;

  if (cmd == "ADD") {
    std::string side, priceTok;
    long long id, price, qty;
    if (!(in >> idTok >> side >> priceTok >> qtyTok) || (in >> extra)) {
      E1();
      return;
    }
    if (!parseNum(idTok, id) || !parseNum(priceTok, price) ||
        !parseNum(qtyTok, qty) || (side != "S" && side != "B")) {
      E1();
      return;
    }
    if (!within_bounds(id, MAX_ID))
      return;
    if (!within_bounds(price, MAX_THRESHOLD))
      return;
    if (!within_bounds(qty, MAX_THRESHOLD))
      return;

    ob.add(id, Order{side, price, qty});

  } else if (cmd == "CANCEL") {
    long long id;
    if (!(in >> idTok) || (in >> extra) || !parseNum(idTok, id)) {
      E1();
      return;
    }
    if (!within_bounds(id, MAX_ID))
      return;
    ob.cancel(id);

  } else if (cmd == "MODIFY") {
    long long id, qty;
    if (!(in >> idTok >> qtyTok) || (in >> extra) || !parseNum(idTok, id) ||
        !parseNum(qtyTok, qty)) {
      E1();
      return;
    }
    if (!within_bounds(id, MAX_ID))
      return;
    if (!within_bounds(qty, MAX_THRESHOLD))
      return;
    ob.modify(id, qty);

  } else if (cmd == "BEST") {
    if (in >> extra) {
      E1();
      return;
    }
    ob.best();

  } else if (cmd == "DEPTH") {
    std::string kTok;
    long long k;
    if (!(in >> kTok) || (in >> extra) || !parseNum(kTok, k)) {
      E1();
      return;
    }
    if (!within_bounds(k, MAX_THRESHOLD))
      return;
    ob.depth(k);

  } else {
    E1();
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::string line;
  while (std::getline(std::cin, line)) {
    handle(line);
  }
}
