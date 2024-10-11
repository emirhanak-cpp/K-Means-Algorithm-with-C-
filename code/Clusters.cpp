#include "Clusters.h"
#include<iostream>
using namespace std;

Cluster::Cluster(int id) : center({ 0.0, 0.0 }) {
    
    setClusterId(id);

}

Cluster::~Cluster() {};

int Cluster::getClusterId() const {
    return cluster_id;
}

void Cluster::setClusterId(int id) {
    cluster_id = id;

}

const std::vector<Sample>& Cluster::getSamples() const {
    return samples;
}
void Cluster::addSample(const Sample& sample) {
    samples.push_back(sample);
}

void Cluster::updateCenter() {
    double sumX = 0.0, sumY = 0.0;
    for (const auto& sample : samples) {
        sumX += sample.getX();
        sumY += sample.getY();
    }

    if (!samples.empty()) {
        center.first = sumX / samples.size();
        center.second = sumY / samples.size();
    }
}

pair<double, double> Cluster::getCenter() const {
    return center;
}


void Cluster::clearSamples() {
    samples.clear();
}
