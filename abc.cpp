#include "abc.hpp"


ABC::ABC() : colony(), attempts(), fitness(), better_fitness(), better_fitnesses() {
  this->colony_size = COLONY_SIZE;
  this->half_colony = HALF_COLONY;
  this->max_iter = MAX_ITER;
  this->max_forage = MAX_FORAGE;
  this->limit = LIMIT;
}

ABC::~ABC(){
  this->food_sources.clear();
}

void ABC::print_colony() {
  for ( auto i = 0; i != HALF_COLONY; i++ ){
    std::cout << "Bee " << i << ":" << std::endl;
    for ( auto j = 0; j < COLONY_SIZE; j++)
      std::cout << "    Food Source " << j << " = " << colony[i][j] << std::endl;
  }
}
