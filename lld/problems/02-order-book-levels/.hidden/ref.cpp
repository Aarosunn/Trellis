#include <cctype>
#include <charconv>
#include <format>
#include <functional>
#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using ll = long long;

enum class Side { Buy, Sell };

struct Order {
  Side side;
  ll price;
  ll qty;
};

struct Level {
  ll qty = 0;
  ll count = 0;
};

constexpr ll kMaxId = 1'000'000'000'000'000'000LL;
constexpr ll kMaxValue = 1'000'000'000LL;

bool inRange(ll v, ll hi) { return v >= 1 && v <= hi; }

class OrderBook {
public:
  enum class AddResult { Ok, Duplicate, Crosses };

  AddResult add(ll id, Side side, ll price, ll qty) {
    if (everAdded_.contains(id)) return AddResult::Duplicate;
    if (crosses(side, price)) return AddResult::Crosses;
    everAdded_.insert(id);
    orders_[id] = {.side = side, .price = price, .qty = qty};
    Level &lvl = side == Side::Buy ? bids_[price] : asks_[price];
    lvl.qty += qty;
    ++lvl.count;
    return AddResult::Ok;
  }

  bool cancel(ll id) {
    auto it = orders_.find(id);
    if (it == orders_.end()) return false;
    const Order &o = it->second;
    if (o.side == Side::Buy) removeFrom(bids_, o.price, o.qty);
    else removeFrom(asks_, o.price, o.qty);
    orders_.erase(it);
    return true;
  }

  bool modify(ll id, ll newQty) {
    auto it = orders_.find(id);
    if (it == orders_.end()) return false;
    Order &o = it->second;
    Level &lvl = o.side == Side::Buy ? bids_.at(o.price) : asks_.at(o.price);
    lvl.qty += newQty - o.qty;
    o.qty = newQty;
    return true;
  }

  std::string best() const {
    return std::format("BEST {} {}", top(bids_), top(asks_));
  }

  std::string depth(ll k) const {
    return std::format("BID{}\nASK{}", levels(bids_, k), levels(asks_, k));
  }

private:
  std::unordered_map<ll, Order> orders_;
  std::unordered_set<ll> everAdded_;
  std::map<ll, Level, std::greater<>> bids_;
  std::map<ll, Level> asks_;

  bool crosses(Side side, ll price) const {
    if (side == Side::Buy) return !asks_.empty() && price >= asks_.begin()->first;
    return !bids_.empty() && price <= bids_.begin()->first;
  }

  template <class Map> static void removeFrom(Map &m, ll price, ll qty) {
    auto it = m.find(price);
    it->second.qty -= qty;
    if (--it->second.count == 0) m.erase(it);
  }

  template <class Map> static std::string top(const Map &m) {
    if (m.empty()) return "-";
    return std::format("{}x{}", m.begin()->first, m.begin()->second.qty);
  }

  template <class Map> static std::string levels(const Map &m, ll k) {
    if (m.empty()) return " -";
    std::string out;
    for (const auto &[price, lvl] : m) {
      if (k-- == 0) break;
      out += std::format(" {}:{}:{}", price, lvl.qty, lvl.count);
    }
    return out;
  }
};

std::vector<std::string_view> split(std::string_view line) {
  std::vector<std::string_view> tokens;
  size_t i = 0;
  while (i < line.size()) {
    while (i < line.size() && std::isspace(static_cast<unsigned char>(line[i]))) ++i;
    size_t j = i;
    while (j < line.size() && !std::isspace(static_cast<unsigned char>(line[j]))) ++j;
    if (j > i) tokens.push_back(line.substr(i, j - i));
    i = j;
  }
  return tokens;
}

std::optional<ll> parseInt(std::string_view s) {
  ll v{};
  auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), v);
  if (ec != std::errc{} || ptr != s.data() + s.size()) return std::nullopt;
  return v;
}

class CommandHandler {
public:
  // Returns the output for one command; empty optional = no output (blank line).
  std::optional<std::string> handle(std::string_view line) {
    auto t = split(line);
    if (t.empty()) return std::nullopt;
    if (t[0] == "ADD") return add(t);
    if (t[0] == "CANCEL") return cancel(t);
    if (t[0] == "MODIFY") return modify(t);
    if (t[0] == "BEST") return t.size() == 1 ? book_.best() : "E1";
    if (t[0] == "DEPTH") return depth(t);
    return "E1";
  }

private:
  OrderBook book_;

  std::string add(const std::vector<std::string_view> &t) {
    if (t.size() != 5 || (t[2] != "B" && t[2] != "S")) return "E1";
    auto id = parseInt(t[1]), price = parseInt(t[3]), qty = parseInt(t[4]);
    if (!id || !price || !qty) return "E1";
    if (!inRange(*id, kMaxId) || !inRange(*price, kMaxValue) || !inRange(*qty, kMaxValue))
      return "E2";
    Side side = t[2] == "B" ? Side::Buy : Side::Sell;
    switch (book_.add(*id, side, *price, *qty)) {
    case OrderBook::AddResult::Duplicate: return "E4";
    case OrderBook::AddResult::Crosses: return "E5";
    case OrderBook::AddResult::Ok: return "OK";
    }
    return "OK";
  }

  std::string cancel(const std::vector<std::string_view> &t) {
    if (t.size() != 2) return "E1";
    auto id = parseInt(t[1]);
    if (!id) return "E1";
    if (!inRange(*id, kMaxId)) return "E2";
    return book_.cancel(*id) ? "OK" : "E3";
  }

  std::string modify(const std::vector<std::string_view> &t) {
    if (t.size() != 3) return "E1";
    auto id = parseInt(t[1]), qty = parseInt(t[2]);
    if (!id || !qty) return "E1";
    if (!inRange(*id, kMaxId) || !inRange(*qty, kMaxValue)) return "E2";
    return book_.modify(*id, *qty) ? "OK" : "E3";
  }

  std::string depth(const std::vector<std::string_view> &t) {
    if (t.size() != 2) return "E1";
    auto k = parseInt(t[1]);
    if (!k) return "E1";
    if (!inRange(*k, kMaxValue)) return "E2";
    return book_.depth(*k);
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  CommandHandler handler;
  std::string line, out;
  while (std::getline(std::cin, line)) {
    if (auto r = handler.handle(line)) {
      out += *r;
      out += '\n';
    }
  }
  std::cout << out;
}
