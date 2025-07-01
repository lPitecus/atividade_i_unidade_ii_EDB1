#ifndef SORTERS_H
#define SORTERS_H

#include <vector>

// Struct para coletar as métricas de cada algoritmo.
struct Metrics {
    long long comparisons = 0;
    long long swaps = 0;

    void reset() {
        comparisons = 0;
        swaps = 0;
    }
};

// --- Declarações das Funções de Ordenação ---

// Bubble Sort
void bubbleSort(std::vector<int>& arr, Metrics& metrics);

// Insertion Sort
void insertionSort(std::vector<int>& arr, Metrics& metrics);

// Selection Sort
void selectionSort(std::vector<int>& arr, Metrics& metrics);

// Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right, Metrics& metrics);

// Quick Sort
void quickSort(std::vector<int>& arr, int low, int high, Metrics& metrics);

#endif