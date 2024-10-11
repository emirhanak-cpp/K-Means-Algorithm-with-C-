#include "./Samples.h"
#include<iostream>
using namespace std;

Sample::Sample(int idx, double x_coord, double y_coord){
    setIndex(idx);
    setClusterId(-1);
    setCoordinates(x_coord, y_coord);
}

void Sample::setIndex(int indx)
{
    index = indx;
}

int Sample::getIndex() const {
    return index;
}

int Sample::getClusterId() const {
    return cluster_id;
}

void Sample::setClusterId(int cluster) {
    cluster_id = cluster;
}

double Sample::getX() const {
    return x;
}

void Sample::setX(double x_coord) {
    x = x_coord;
}

double Sample::getY() const {
    return y;
}

void Sample::setY(double y_coord) {
    y = y_coord;
}

void Sample::setCoordinates(double x_coord, double y_coord) {
    setX(x_coord);
    setY(y_coord);
}
