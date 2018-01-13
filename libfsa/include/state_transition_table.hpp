//
// Created by fexolm on 07.01.18.
//

#pragma once
#include <set>
#include <map>
#include <vector>
namespace jilag {
namespace __internal {
struct __state_translation_table {
  std::set<int> finals;
  std::vector<std::map<int, int>> states;
};
}
}
