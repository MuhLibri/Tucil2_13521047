#ifndef __UTILITY_HPP__
#define __UTILITY_HPP__

#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;


double getRandomNumber (int maxNum);
// maxNum merupakan nilai mutlak dari batas paling ujung (Asumsi niali mutlak kedua ujung bernilai sama)
// Mengembalikan satu angka yang random

double calculateEuclidean (vector<double> p1, vector<double> p2);
// Mengembalikan nilai euclidean dari dua buah titik

void sortList (vector<double>* list, int size, int plane);
// Mengembalikan list yang telah terurut membesar berdarkan plane (Menggunakan quicksort)

int partitionList (vector<double>* list, int start, int end, int plane);
// Mempartisi list dan mengembalikan index pivot
 
void quickSort (vector<double>* list, int start, int end, int plane);
// Secara rekursif memanggil partitionList dan mengurtkan elemen

#endif