#include "bee.hpp"

Bee::Bee(){
  this->scout = false;
  this->distance = 0.0;
}

Bee::~Bee(){
  this->choosen_nodes.clear();
}
