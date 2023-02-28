#ifndef __DIVIDECONQUER_HPP__
#define __DIVIDECONQUER_HPP__

#include "Utility.hpp"


class DivideConquer {
private:
    int euclideanCount;
    double shortestDistance;
    std::vector<double> p1;
    std::vector<double> p2;

public:
    // CTOR
    DivideConquer();
    DivideConquer(std::vector<double>* listVector, int size);
    // DTOR
    ~DivideConquer();

    // Getter
    int getEuclideanCount();
    double getShortestDistance();
    std::vector<double> getPoint1();
    std::vector<double> getPoint2();

    // Other
    std::tuple<double, int, int> dncShortestEuclidean (vector<double>* list, int start, int end);
    // Mengembailikan euclidean terpendek dari list

    void stripShortestEuclidean (vector<double>* listVector, int start, int end);
    // Mencari euclidean terpendek dari stripList

    void print();
    // Menampilkan jarak terdekat, pasangan titik terdekat, dan banyaknya operasi euclidean
};

#endif