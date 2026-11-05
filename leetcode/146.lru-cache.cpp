// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @leet start
class LRUCache {
  int capacity_;
  struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;

    Node() : key(0), val(0), next(nullptr), prev(nullptr) {}
    Node(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
  };

  unordered_map<int, Node *> store;
  Node *head, *tail;

public:
  LRUCache(int capacity)
      : capacity_(capacity), tail(new Node()), head(new Node()) {
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (store.count(key)) {
      Node *curr = store[key];
      remove(curr);
      addToBack(curr);
      return curr->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (store.count(key)) {
      Node *curr = store[key];
      curr->val = value;
      remove(curr);
      addToBack(curr);
    } else {
      if (store.size() == capacity_) {
        Node *lru = head->next;
        remove(lru);
        store.erase(lru->key);
        delete lru;
      }
      addToBack(new Node(key, value));
    }
  }

  void remove(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = nullptr;
    node->prev = nullptr;
  }

  void addToBack(Node *node) {
    node->prev = tail->prev;
    tail->prev->next = node;
    tail->prev = node;
    node->next = tail;
    store[node->key] = node;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
