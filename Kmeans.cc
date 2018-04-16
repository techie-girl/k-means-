/*
This is an implementation of the Kmeans++ algorithm based on the work of Arthur, D. & Vassilvitskii, S. (2007)--
Arazoo Hoseyni April 10, 2018.
*/

#include <random>
#include <cassert>
#include "Kmeans.h"

namespace kmeans{

//implementing a tokenizer 
vector<double> split(const string &s, const char &delim) {
  std::stringstream ss(s);
  string item;
  vector<double> tokens;
  while(getline(ss, item, delim)) {
    tokens.push_back(std::stod(item));
  }
  return tokens;
}
//reading in the dataset 
vector<vector<double>> readDataSet(std::istream &file) {
  vector<vector<double>> dataset;
  string s;
  while(std::getline(file, s)) {
    dataset.push_back(split(s, ' '));
  }
  return dataset;
}

//forming clusters from the inputed dataset
void Kmeans::cluster(const unsigned long long &k, std::vector<std::vector<double>> &centres) {
  assert(k <= dataset_.size());
  computeSeeds(k, centres);

  assert(centres.size() == k);
  runIterations(k, centres);

}
//selecting k random seeds/centers 
void Kmeans::computeSeeds(const unsigned long long &k, std::vector<std::vector<double>> &centres) {

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, dataset_.size());

  for(int i = 0; i < k; ++i) {
    centres.push_back(dataset_[static_cast<int>((dis(gen)))]);
  }
}
//computing the distance 
double distance(const std::vector<double> &v1, const std::vector<double> &v2) {
  double dist = 0;
  assert(v1.size() == v2.size());
  for(int i = 0; i < v1.size(); ++i) {
    dist += (v1[i] - v2[i]) * (v1[i] - v2[i]);
  }
  return dist;
}
//running iterations until there is no longer any change in the seeds. 
double Kmeans::runIteration(std::vector<std::vector<double>> &centres) {

  std::vector<unsigned long long> sizes(centres.size(), 0);

  int closest;
  double closestDistance;
  double tempDistance;
  double totalDistance = 0;

  std::vector<std::vector<double>> newCentres = std::vector<std::vector<double>>(centres.size(),
                                                                                 std::vector<double>(centres[0].size(),
                                                                                                     0));
  for(int pointId = 0; pointId < dataset_.size(); ++pointId) {
    closest = -1;
    closestDistance = std::numeric_limits<double>::max();
    for(int centreId = 0; centreId < centres.size(); ++centreId) {
      tempDistance = distance(centres[centreId], dataset_[pointId]);
      if(tempDistance < closestDistance) {
        closestDistance = tempDistance;
        closest = centreId;
      }
    }
    for(int i = 0; i < centres[closest].size(); ++i) {
      newCentres[closest][i] += dataset_[pointId][i];
    }
    totalDistance += closestDistance;
    sizes[closest] += 1;
  }
  for(int centreId = 0; centreId < centres.size(); ++centreId) {
    if(sizes[centreId] == 0)continue;
    for(int i = 0; i < centres[centreId].size(); ++i) {
      newCentres[centreId][i] /= sizes[centreId];
    }
  }

  centres = newCentres;
  return totalDistance;
}

void Kmeans::runIterations(const unsigned long long &k, std::vector<std::vector<double>> &centres) {
  auto previousDistance = runIteration(centres);
  int numIterations = 1;
  for(int i = 0; i <maxIterations_; ++i) {
    const auto &currDistance = runIteration(centres);
    numIterations++;
    if(currDistance / previousDistance > 0.999999999) {
      break;
    }
    previousDistance=currDistance;
  }
}
}
