#include "abc.hpp"


ABC::ABC(Tsplib *tsp) {
  /* PARAMETERS */
  this->colony_size = COLONY_SIZE;
  this->half_colony = HALF_COLONY;
  this->max_iter = MAX_ITER;
  this->max_forage = MAX_FORAGE;
  this->limit = LIMIT;

  /* TSP */
  this->tsp = tsp;
  this->D = this->tsp->city_count;

  this->better_fitness = 0;
  this->attempts = std::vector<int>(HALF_COLONY);
  this->fitness = std::vector<double>(HALF_COLONY);
  this->better_solution = std::vector<double>(this->D);
  this->better_fitnesses = std::vector<double>(MAX_ITER);
  this->better_solutions = std::vector<std::vector<double>>(MAX_ITER, std::vector<double>(this->D));
  this->colony = std::vector<std::vector<double>>(HALF_COLONY, std::vector<double>(this->D));

  this->fill_vectors();
}

ABC::~ABC(){
  this->food_sources.clear();
}

void ABC::fill_vectors(){
  /* colony */
  for ( auto i = 0; i < HALF_COLONY; i++){
    for ( auto j = 0; j < this->D; j++){
      this->colony.at(i).at(j) = j;
    }
  }

  /* attempts & fitness */
  for ( auto i = 0; i < HALF_COLONY; i++){
    this->attempts.at(i) = 0;
    this->fitness.at(i) = 0;
  }

  /* better_fitnesses */
  for ( auto i = 0; i < MAX_ITER; i++){
    this->better_fitnesses.at(i) = 0;
  }

  /* better_solutions */
  for ( auto i = 0; i < MAX_ITER; i++){
    for ( auto j = 0; j < this->D; j++){
      this->better_solutions.at(i).at(j) = 0;
    }
  }

  /* better_solution */
  for ( auto i = 0; i < this->D; i++){
    this->better_solution.at(i) = 0;
  }

}

void ABC::print_colony() {
  for ( auto i = 0; i != HALF_COLONY; i++ ){
    std::cout << "Bee " << i << ":" << std::endl;
    for ( auto j = 0; j < COLONY_SIZE; j++)
      std::cout << "    Food Source " << j << " = " << colony[i][j] << std::endl;
  }
}

void ABC::generate_population() {
  for ( auto i = 0; i < HALF_COLONY; i++){
    std::random_shuffle ( this->colony.at(i).begin(), this->colony.at(i).end() );  // TODO: USE CUSTOM RANDOM ALGORITHM
    this->fitness.at(i) = this->calculate_fitness(this->colony.at(i));
  }
}

double ABC::calculate_fitness(std::vector<double> solutions){
  double fitness = 0.0;
  for ( auto i = 0; i < solutions.size() - 1; i++){
    fitness += this->tsp->distances.at(solutions.at(i)).at(solutions.at(i+1));
  }
  fitness += this->tsp->distances.at(solutions.at(solutions.size()-1)).at(solutions.at(0));
  return fitness;
}
