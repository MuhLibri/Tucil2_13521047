#ifndef __BruteForce_HPP__
#define __BruteForce_HPP__

#include "Utility.hpp"


class BruteForce {
private:
    int euclideanCount;
    double shortestDistance;
    std::vector<double> p1;
    std::vector<double> p2;

public:
    // CTOR
    BruteForce();
    BruteForce(std::vector<double>* listVector, int size);
    // DTOR
    ~BruteForce();

    // Getter
    int getEuclideanCount();
    double getShortestDistance();
    std::vector<double> getPoint1();
    std::vector<double> getPoint2();

    // Other
    void print();
    // Menampilkan jarak terdekat, pasangan titik terdekat, dan banyaknya operasi euclidean
};


#endif