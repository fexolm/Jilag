//
// Created by fexolm on 03.01.18.
//

#pragma once
#include <cstdint>
#include <vector>
#include <unordered_map>
#include "index_tree.hpp"
#include "nsa.hpp"
namespace jilag {
namespace __internal {

class __IndexTree {
private:
  struct __TreeNode {
    int index;
    intptr_t value;
    std::unordered_map<intptr_t, __TreeNode *> children_;
  };
  __TreeNode *root_;
  uint cur_index_;
  void destroy(__TreeNode *node);
  __TreeNode *insert(__NSA_State::ptr_t, __TreeNode *);
public:
  __IndexTree();
  __IndexTree(const __IndexTree &) = delete;
  __IndexTree &operator=(const __IndexTree &) = delete;
  virtual ~__IndexTree();
  int get_index(const std::vector<__NSA_State::ptr_t> &);
};
} // namespace __internal
} // namespace jilag
