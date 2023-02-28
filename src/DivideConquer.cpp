#include "DivideConquer.hpp"
#include <iostream>
using namespace std;


DivideConquer::DivideConquer() : euclideanCount(0), shortestDistance(9999) {}

DivideConquer::DivideConquer(std::vector<double>* listVector, int size) {
    this->euclideanCount = 0;
    std::tuple<double, int, int> retVal;
    sortList(listVector, size, 0);

    if (size > 2) {
        retVal = dncShortestEuclidean(listVector, 0, size-1);
        this->shortestDistance = get<0>(retVal);
        this->p1 = listVector[get<1>(retVal)];
        this->p2 = listVector[get<2>(retVal)];
    }
    else {
        this->shortestDistance = calculateEuclidean(listVector[0], listVector[1]);
        this->p1 = listVector[0];
        this->p2 = listVector[1];
        this->euclideanCount++;
    }
}

DivideConquer::~DivideConquer() {}

int DivideConquer::getEuclideanCount() {
    return this->euclideanCount;
}

double DivideConquer::getShortestDistance() {
    return this->shortestDistance;
}

std::vector<double> DivideConquer::getPoint1() {
    return this->p1;
}

std::vector<double> DivideConquer::getPoint2() {
    return this->p2;
}

std::tuple<double, int, int> DivideConquer::dncShortestEuclidean (vector<double>* list, int start, int end) {
    double middlePoint, d;
    int leftIndex = (start+end)/2;
    int rightIndex = ((start+end)/2) + 1;
    bool out_of_strip_left = false;
    bool out_of_strip_right = false;
    std::tuple<double, int, int> retVal, strip;

    // Basis
    if (end-start<=2) {
        double temp_euclidean = calculateEuclidean(list[start], list[start+1]);
        this->euclideanCount++;
        double shortest_euclidean = temp_euclidean;
        retVal = {temp_euclidean, start, start+1};
        
        if (end - start > 1) {
            for (int i = start; i <= end; i++) {
                for (int j = i + 1; j <= end; j++) {
                    temp_euclidean = calculateEuclidean(list[i], list[j]);
                    this->euclideanCount++;
                    if (temp_euclidean < shortest_euclidean) {
                        retVal = {temp_euclidean, i, j};
                    }
                }
            }
        }        
        return retVal;
    }
    // Rekurens
    else {
        auto leftPart = dncShortestEuclidean (list, start, leftIndex);
        auto rightPart = dncShortestEuclidean (list, rightIndex, end);

        if (get<0>(leftPart) <= get<0>(rightPart)) {
            retVal = leftPart;
        }
        else {
            retVal = rightPart;
        }

        d = get<0>(retVal);
        middlePoint = (list[leftIndex].at(0) + list[rightIndex].at(0))/2.0;
        while ((leftIndex > start) && (!out_of_strip_left)) {
            if (list[leftIndex].at(0) > (middlePoint - d)) {
                leftIndex--;
            }
            else {
                out_of_strip_left = true;
            }
        }

        while ((rightIndex < end) && (!out_of_strip_right)) {
            if (list[rightIndex].at(0) < (middlePoint + d)) {
                rightIndex++;
            }
            else {
                out_of_strip_right = true;
            }
        }
        strip = stripShortestEuclidean(list, leftIndex+1, rightIndex-1, d);
        if (get<0>(strip) < get<0>(retVal)) {
            retVal = strip;
        } 
        return retVal;
    }
}

std::tuple<double, int, int> DivideConquer::stripShortestEuclidean(vector<double>* listVector, int start, int end, double d) {
    double temp_euclidean = calculateEuclidean(listVector[start], listVector[start+1]);
    this->euclideanCount++;
    double shortest_euclidean = d;
    std::tuple<double, int, int> retVal = {temp_euclidean, start, start+1};
    
    if (end - start > 1) {
        for (int i = start; i <= end; i++) {
            for (int j = i + 1; j <= end; j++) {
                temp_euclidean = calculateEuclidean(listVector[i], listVector[j]);
                this->euclideanCount++;
                if (temp_euclidean < shortest_euclidean) {
                    shortest_euclidean = temp_euclidean;
                    retVal = {temp_euclidean, i, j};
                }
            }
        }
    }

    return retVal;
}

void DivideConquer::print() {
    cout << "Hasil menggunakan algoritma divide and conquer: " << endl;
    cout << "Jarak terdekat = " << this->shortestDistance << endl;

    cout << "Titik 1 = {";
    for (int i = 0; i < this->p1.size(); i++) {
        cout << this->p1.at(i);
        if (i != this->p1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    
    cout << "Titik 2 = {";
    for (int i = 0; i < this->p2.size(); i++) {
        cout << this->p2.at(i);
        if (i != this->p2.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;    

    cout << "Banyaknya operasi euclidean = " << this->euclideanCount << endl;
}