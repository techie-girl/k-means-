/*
This is an implementation of the Kmeans++ algorithm based on the work of Arthur, D. & Vassilvitskii, S. (2007)--
Arazoo Hoseyni April 10, 2018.
*/

#ifndef ARAZOO_KMEANS_H
#define ARAZOO_KMEANS_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

namespace kmeans{
using std::string;
using std::vector;
using std::endl;
using std::cout;

vector<double> split(const string &s, const char &delim);
vector<vector<double>> readDataSet(std::istream &file);

class Kmeans{
private:
  int maxIterations_;
  std::vector<std::vector<double>> dataset_;
  void computeSeeds(const unsigned long long  &k, std::vector<std::vector<double>> &centres);
  double runIteration( std::vector<std::vector<double>> &centres);
  void runIterations(const unsigned long long  &k, std::vector<std::vector<double>> &centres);
public:
  inline explicit Kmeans(const std::vector<std::vector<double>> &dataset, int maxIterations = 200)
      : dataset_(dataset), maxIterations_(maxIterations) {}
  void cluster(const unsigned long long &k, std::vector<std::vector<double>> &centres);


};
}//namespace kmeans


#endif //ARAZOO_KMEANS_H
