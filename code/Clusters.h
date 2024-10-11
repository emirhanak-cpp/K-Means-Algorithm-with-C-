#pragma once
#ifndef CLUSTER_H
#define CLUSTER_H

#include "Samples.h"
#include <iostream>


using namespace std;

class Cluster {
private:
    int cluster_id;
    vector<Sample> samples;
    pair<double, double> center;
    std::pair<double, double> previousCenter;


public:
    Cluster(int id);
    ~Cluster() ;
    int getClusterId() const;
    void setClusterId(int id);
    const std::vector<Sample>& getSamples() const;
    void addSample(const Sample& sample);
    void updateCenter();
    std::pair<double, double> getCenter() const;
    void clearSamples();
};

#endif // CLUSTER_H
