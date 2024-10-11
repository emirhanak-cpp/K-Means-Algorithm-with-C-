#include<iostream>
#include "KMeans.h"
#include "matplotlibcpp.h"
using namespace matplotlibcpp;
using namespace std;


int main() {
	int K;
	cout << "Please enter the number of K point " << endl;
	cin >> K;

	KMeans kmeans(K);
	kmeans.runKMeans(""); //enter the directory of the data
	kmeans.plotResults();
	return 0;
}
