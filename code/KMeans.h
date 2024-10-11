#pragma once
#ifndef KMEANS_H
#define KMEANS_H
#include <iostream>
#include "Clusters.h"
#include "Samples.h"

using namespace std;

class KMeans {
private:
    int k;
    std::vector<Sample> samples;
    std::vector<Cluster> clusters;

public:
    KMeans(int num_clusters);
    ~KMeans();
    void setNumberofClusters(int numofclusters);
    void loadSamplesFromFile(const std::string& file_path);
    void initializeClusters();
    void assignSamplesToClusters();
    void updateClusterCenters();
    void printResults();
    void plotResults();
    void runKMeans(const std::string& file_path);
   
};

#endif // KMEANS_H
