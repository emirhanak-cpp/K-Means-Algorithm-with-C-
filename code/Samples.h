#pragma once
#ifndef SAMPLE_H
#define SAMPLE_H
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <fstream>
#include <utility>
#include <string>


using namespace std;

class Sample {
private:
    int index;
    int cluster_id;
    double x, y;

public:
    Sample(int idx, double x_coord, double y_coord);

    void setIndex(int indx);
    int getIndex() const;
    int getClusterId() const;
    void setClusterId(int cluster);
    double getX() const;       
    void setX(double x_coord); 
    double getY() const;       
    void setY(double y_coord); 
    void setCoordinates(double x_coord, double y_coord);
};

#endif // SAMPLE_H
