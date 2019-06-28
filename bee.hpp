#ifndef BEE_HPP
#define BEE_HPP

#include <vector>

class Bee {
public:
  bool scout;
  double distance;
  std::vector<int> choosen_nodes;
  Bee();
  ~Bee();
};

#endif
