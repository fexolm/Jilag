//
// Created by fexolm on 03.01.18.
//

#include "index_tree.hpp"

namespace jilag {
namespace __internal {

__IndexTree::__IndexTree()
    : root_(new __TreeNode),
      cur_index_(0) {
  root_->index = -1;
  root_->value = INTPTR_MAX;
}
__IndexTree::~__IndexTree() {
  destroy(root_);
}
int __IndexTree::get_index(const std::vector<__NSA_State::ptr_t> &ptr_list) {
  auto node = root_;
  for (auto ptr : ptr_list) {
    node = insert(ptr, root_);
  }
  if (node->index==-1) {
    node->index = cur_index_;
    ++cur_index_;
  }
  return node->index;
}
void __IndexTree::destroy(__TreeNode *node) {
  for (auto &p : node->children_)
    delete p.second;
  delete node;
}
__IndexTree::__TreeNode *__IndexTree::insert(__NSA_State::ptr_t ptr, __TreeNode *node) {
  auto size = reinterpret_cast<intptr_t>(ptr);
  if (!node->children_.count(size)) {
    auto nnode = new __TreeNode;
    nnode->value = size;
    nnode->index = -1;
    node->children_[size] = nnode;
  }
  return node->children_[size];
}
} // namespace __internal
} // namespace jilag
