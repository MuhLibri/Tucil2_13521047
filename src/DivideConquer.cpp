#include "DivideConquer.hpp"
#include <iostream>
using namespace std;


DivideConquer::DivideConquer() : euclideanCount(0), shortestDistance(9999) {}

DivideConquer::DivideConquer(std::vector<double>* listVector, int size) {
    double middlePoint;
    std::vector<double>* stripList;
    int leftIndex = size/2;
    int rightIndex = (size/2) + 1;
    bool out_of_strip_left = false;
    bool out_of_strip_right = false;
    this->euclideanCount = 0;
    sortList(listVector, size, 0);

    if (size > 2) {
        auto smallest1 = DivideConquer::dncShortestEuclidean(listVector, 0, leftIndex);
        auto smallest2 = DivideConquer::dncShortestEuclidean(listVector, rightIndex, size-1);
        middlePoint = (listVector[leftIndex].at(0) + listVector[rightIndex].at(0))/2.0;

        if (get<0>(smallest1) <= get<0>(smallest2)) {
            this->shortestDistance = get<0>(smallest1);
            this->p1 = listVector[get<1>(smallest1)];
            this->p2 = listVector[get<2>(smallest1)];
        }
        else {
            this->shortestDistance = get<0>(smallest2);
            this->p1 = listVector[get<1>(smallest2)];
            this->p2 = listVector[get<2>(smallest2)];        
        }

        while ((leftIndex > 0) && (!out_of_strip_left)) {
            if (listVector[leftIndex].at(0) > (middlePoint - this->shortestDistance)) {
                leftIndex--;
            }
            else {
                out_of_strip_left = true;
            }
        }

        while ((rightIndex < size-1) && (!out_of_strip_right)) {
            if (listVector[rightIndex].at(0) < (middlePoint + this->shortestDistance)) {
                rightIndex++;
            }
            else {
                out_of_strip_right = true;
            }
        }
        stripShortestEuclidean(listVector, leftIndex, rightIndex);
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
    double current_euclidean = 0;
    double next_euclidean = 0;

    // Basis
    if (start == end) {
        return {100000, start, end};
    }
    else if (start+1 == end) {
        this->euclideanCount++;
        return {calculateEuclidean(list[start], list[start+1]), start, start+1};
    }
    // Rekurens
    else {
        current_euclidean = calculateEuclidean(list[start], list[start+1]);
        this->euclideanCount++;

        auto next_enum = dncShortestEuclidean (list, start+1, end);
        next_euclidean = get<0>(next_enum);
        if (current_euclidean <= next_euclidean) {
            return {current_euclidean, start, start+1};
        }
        else {
            return next_enum;
        }   
    }
}

void DivideConquer::stripShortestEuclidean(vector<double>* listVector, int leftIndex, int rightIndex) {
    double temp_euclidean;

    for (int i = leftIndex+1; i < rightIndex; i++) {
        for (int j = i + 1; j < rightIndex; j++) {
            temp_euclidean = calculateEuclidean(listVector[i], listVector[j]);
            this->euclideanCount++;
            if (temp_euclidean < this->shortestDistance) {
                this->shortestDistance = temp_euclidean;
                this->p1 = listVector[i];
                this->p2 = listVector[j];
            }
        }
    }
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