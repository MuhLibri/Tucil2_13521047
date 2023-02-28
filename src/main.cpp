#include "Utility.hpp"
#include "BruteForce.hpp"
#include "DivideConquer.hpp"
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

int main() {
    int n;
    int dimensi = 3;
    int maxNum = 100;
    srand(time(NULL));
    vector<double>* listVector;

    cout << "Masukkan banyak titik" << endl;
    cin >> n;
    cout << "Masukkan banyak dimensi" << endl;
    cin >> dimensi;
    cout << "Masukkan batas ujung (batas ujung diasumsikan simetri)" << endl;
    cin >> maxNum;

    while (n < 2) {
        cout << "Masukan salah, silahkan masukkan kembali" << endl;
        cin >> n;
    }
    cout << endl;

    listVector = new vector<double>[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < dimensi; j++) {
            listVector[i].push_back(getRandomNumber(maxNum));
        }
    }


    auto start1 = high_resolution_clock::now();
    BruteForce bruteForce(listVector, n);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    bruteForce.print();
    cout << "Waktu eksekusi = " << duration1.count() << " microseconds" << endl;
    cout << endl;

    auto start2 = high_resolution_clock::now();
    DivideConquer divideConquer(listVector, n);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    divideConquer.print();
    cout << "Waktu eksekusi = " << duration2.count() << " microseconds" << endl;
    cout << endl;

    return 0;
}