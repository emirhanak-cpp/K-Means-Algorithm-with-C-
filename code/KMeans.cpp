#include<iostream>
#include "KMeans.h"
#include "matplotlibcpp.h"
using namespace matplotlibcpp;

using namespace std;

KMeans::KMeans(int num_clusters) {
    setNumberofClusters(num_clusters);

}

KMeans::~KMeans() {}


void KMeans::setNumberofClusters(int numofclusters)
{
    k = numofclusters;
}

void KMeans::loadSamplesFromFile(const std::string& file_path) {
    std::ifstream file(file_path);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << file_path << std::endl;
        return;
    }
        
    double x, y;
    for (int index = 0; index < 40; ++index) {
        file >> x >> y;
        samples.emplace_back(index, x, y);
    }

    file.close();
}

void KMeans::initializeClusters() {
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 1; i <= k; ++i) {
        clusters.emplace_back(i);
        int randomIndex = rand() % samples.size();
        auto& initialSample = samples[randomIndex];
        clusters.back().addSample(initialSample);
        clusters.back().updateCenter();
    }
}

void KMeans::assignSamplesToClusters() {
    for (auto& sample : samples) {
        double minDistance = std::numeric_limits<double>::max();
        int assignedCluster = -1;

        for (auto& cluster : clusters) {
            double distance = std::hypot(sample.getX() - cluster.getCenter().first,
                sample.getY() - cluster.getCenter().second);

            if (distance < minDistance) {
                minDistance = distance;
                assignedCluster = cluster.getClusterId();
            }
        }

        sample.setClusterId(assignedCluster);
    }
}

void KMeans::updateClusterCenters() {
    for (auto& cluster : clusters) {
        cluster.clearSamples();
    }

    for (auto& sample : samples) {
        clusters[sample.getClusterId() - 1].addSample(sample);
    }

    for (auto& cluster : clusters) {
        cluster.updateCenter();
    }
}

void KMeans::printResults() {
    for (size_t i = 0; i < clusters.size(); ++i) {
        const auto& cluster = clusters[i];
        std::cout << "Cluster " << cluster.getClusterId() << " - Center: ("
            << cluster.getCenter().first << ", " << cluster.getCenter().second << ")\n";
    }   

    cout << "\nDetails for each sample:\n";
    for (size_t i = 0; i < samples.size(); ++i) {
        const auto& sample = samples[i];
        std::cout << "Sample Index: " << sample.getIndex() << " - Coordinates: ("
            << sample.getX() << ", " << sample.getY() << ") - Assigned Cluster ID: " << sample.getClusterId() << "\n";
    }
}

void KMeans::runKMeans(const std::string& file_path) {
    loadSamplesFromFile(file_path);
    initializeClusters();

    const int max_iterations = 150;
    const double convergence_threshold = 0.001;

    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        assignSamplesToClusters();
        updateClusterCenters();
    }

    printResults();
}

void KMeans::plotResults()
{
    vector<string> colors = { "red", "green", "blue", "black", "magenta", "yellow", };
    std::vector<std::vector<double>> clusterData(k);

    for (const auto& sample : samples)
    {
        double x = sample.getX();
        double y = sample.getY();
        int cId = sample.getClusterId();

        plot({ x }, { y }, { {"color",colors[cId]}, {"marker", "o"} });
    }


    vector<double> center_x, center_y;
    for (int i = 0; i < k; ++i)
    {
        double center_x = samples[i].getX();
        double center_y = samples[i].getY();

        plot({ center_x }, { center_y }, { {"color","red"},{"marker","x"} }); // Cluster centers as red 'x'
    }

    show();
}

