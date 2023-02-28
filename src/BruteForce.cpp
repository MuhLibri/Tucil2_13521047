#include "BruteForce.hpp"
#include "iostream"
using namespace std;

BruteForce::BruteForce() : euclideanCount(0), shortestDistance(9999) {}

BruteForce::BruteForce(std::vector<double>* listVector, int size) {
    this->shortestDistance = calculateEuclidean(listVector[0], listVector[1]);
    this->euclideanCount = 1;
    this->p1 = listVector[0];
    this->p2 = listVector[1];
    double temp_euclidean;

    if (size > 2) {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
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
}

BruteForce::~BruteForce() {}

int BruteForce::getEuclideanCount() {
    return this->euclideanCount;
}

double BruteForce::getShortestDistance() {
    return this->shortestDistance;
}

std::vector<double> BruteForce::getPoint1() {
    return this->p1;
}

std::vector<double> BruteForce::getPoint2() {
    return this->p2;
}

void BruteForce::print() {
    cout << "Hasil menggunakan algoritma brute force: " << endl;
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