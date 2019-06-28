#ifndef TSPLIB_HPP
#define TSPLIB_HPP

#include <fstream>
#include <cstdlib>
#include <vector>
#include <iostream>
//#include <iomanip>  // for setw() and ws
#include <string>

class Tsplib {
public:
  int city_count;
  std::vector<double> xCord;
  std::vector<double> yCord;
  std::vector<std::vector<double>> distances;
  Tsplib();
  void addContents(std::ifstream&);
  void print_instance();
  void print_distances();
  void distances_calc();
  double euclidean_distance(double x1, double y1, double x2, double y2);
};

#endif
