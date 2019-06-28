#include <iostream>

#include "abc.hpp"
#include "bee.hpp"
#include "tsplib.hpp"

using namespace std;


int main(){
  Bee tester_bee;
  tester_bee.choosen_nodes.push_back(1);
  /*
  cout << *tester_bee.choosen_nodes.begin() << endl;
  cout << tester_bee.distance << endl;
  cout << tester_bee.scout << endl;
  */
  Tsplib tsplib;
  // tsplib.print_instance();
  tsplib.print_distances();
  ABC abc(&tsplib);
  abc.print_colony();

  return 0;
}
