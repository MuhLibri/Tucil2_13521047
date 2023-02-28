#include "Utility.hpp"


double getRandomNumber (int maxNum) {
    double random_num;
    int random_operand1, random_operand2, random_operand3;
    int range1 = 10;
    int range2 = 21;
    int range3 = 10;

    random_operand1 = rand() % range1 + 1;
    random_operand2 = rand() % range2 - 10;
    random_operand3 = rand() % range3 + 11;

    random_num = (random_operand1 * random_operand2 * random_operand3) % (maxNum);

    return random_num;
}

double calculateEuclidean (vector<double> p1, vector<double> p2) {
    double sum = 0;
    double euclidean;

    for (int i = 0; i < p1.size(); i++) {
        sum += pow((p1.at(i) - p2.at(i)), 2);
    }

    euclidean = sqrt(sum);

    return euclidean;
}

void sortList (vector<double>* list, int size, int plane) {
    quickSort(list, 0, size-1, plane);
}

int partitionList (vector<double>* list, int start, int end, int plane) {
    vector<double> pivot = list[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (list[i].at(plane) <= pivot.at(plane)) {
            count++;
        }
    }
 
    int pivotIndex = start + count;
    swap(list[pivotIndex], list[start]);
 
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
        while (list[i].at(plane) <= pivot.at(plane)) {
            i++;
        }
        while (list[j].at(plane) > pivot.at(plane)) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(list[i++], list[j--]);
        }
    }

    return pivotIndex;
}
 
void quickSort(vector<double>* list, int start, int end, int plane) {
    // Basis
    if (start >= end)
        return;

    // Rekurens
        // Mempartisi list
    int pivotIndex = partitionList(list, start, end, plane);
        // Mengurutkan bagian kiri pivot
    quickSort(list, start, pivotIndex - 1, plane);
        // Mengurutkan bagian kanan pivot
    quickSort(list, pivotIndex + 1, end, plane);
}