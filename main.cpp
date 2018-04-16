/*
This is an implementation of the Kmeans++ algorithm based on the work of Arthur, D. & Vassilvitskii, S. (2007)--
Arazoo Hoseyni April 10, 2018.
*/
#include <iostream>
#include <fstream>
#include "Kmeans.h"

using std::endl;
using std::cout;

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  for(std::size_t i = 0; i < v.size() - 1; ++i) {
    out << v[i] << " ";
  }
  if(!v.empty()) {
    out << v[v.size() - 1];
  }
  return out;
}


template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<std::vector<T>> &v) {
  for(int i = 0; i < v.size() - 1; ++i) {
    out << v[i] << std::endl;
  }
  return out;
}
//showing the user how to run the program
int main(int argc, char **argv) {
  if(argc != 3) {
    std::cout << "Usage: ./kmeans <FileName> <k>" << std::endl;
    exit(1);
  }
  std::string fileName = argv[1];
  int k = atoi(argv[2]);
  std::ifstream file;
  file.open(fileName);
  const auto &dataset = kmeans::readDataSet(file);

  kmeans::Kmeans kmeans(dataset, k);
  std::vector<std::vector<double>> centres;
  kmeans.cluster(10, centres);
  std::cout << centres << endl;
  return 0;
}



