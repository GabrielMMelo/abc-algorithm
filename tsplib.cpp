#include "tsplib.hpp"
#include <math.h>

using namespace std;


const char* filename = "instances/burma14.tsp";

Tsplib::Tsplib() {
  ifstream datafile {filename};
  this->addContents(datafile);
  datafile.close();
  this->distances = vector<vector<double>>(this->city_count, vector<double>(this->city_count));
  this->distances_calc();
}

void Tsplib::distances_calc() {
  for( auto i = 0; i < city_count; i++){
    for ( auto j = 0; j < city_count; j++){
      distances.at(i).at(j) = euclidean_distance(xCord.at(i), yCord.at(i), xCord.at(j), yCord.at(j));
    }
  }
}

double Tsplib::euclidean_distance(double x1, double y1, double x2, double y2) {
  return  sqrt(pow(y1 - x1, 2.0) + pow(y2 - x2, 2.0));
}

void Tsplib::addContents(ifstream& ff) {
  double xCurrentLine;
  double yCurrentLine;
  int cityNumber;
  ff >> city_count;
  cout << "numberCities: " << city_count << endl;
  for(int i = 0; i < city_count; i++){
    ff >> cityNumber;
    ff >> xCurrentLine;
    ff >> yCurrentLine;
    xCord.push_back(xCurrentLine);
    yCord.push_back(yCurrentLine);
  }
}

void Tsplib::print_instance(){
  for (int i = 0; i<xCord.size(); i++){
    cout << xCord.at(i) << " " << yCord.at(i) << endl;
  }
}

void Tsplib::print_distances(){
  for (int i = 0; i < xCord.size(); i++){
    for (int j = 0; j < xCord.size(); j++){
      cout << distances.at(i).at(j) << " ";
    }
    cout << endl;
  }
}
