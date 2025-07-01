#include "Sorters.h" 
#include <iostream>  


// Função auxiliar para trocar dois elementos e contabilizar a troca.
void swap_elements(int& a, int& b, Metrics& metrics) {
    int temp = a;
    a = b;
    b = temp;
    metrics.swaps++;
}

// Implementação do Bubble Sort
void bubbleSort(std::vector<int>& arr, Metrics& metrics) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            metrics.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap_elements(arr[j], arr[j + 1], metrics);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Implementação do Insertion Sort
void insertionSort(std::vector<int>& arr, Metrics& metrics) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            metrics.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                metrics.swaps++; 
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        if (j + 1 != i) {
             metrics.swaps++;
        }
    }
}

// Implementação do Selection Sort
void selectionSort(std::vector<int>& arr, Metrics& metrics) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            metrics.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap_elements(arr[i], arr[min_idx], metrics);
        }
    }
}

// Funções auxiliares e implementação do Merge Sort
void merge(std::vector<int>& arr, int left, int mid, int right, Metrics& metrics) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        metrics.comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        metrics.swaps++;
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        metrics.swaps++;
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        metrics.swaps++;
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right, Metrics& metrics) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, metrics);
        mergeSort(arr, mid + 1, right, metrics);
        merge(arr, left, mid, right, metrics);
    }
}

// Funções auxiliares e implementação do Quick Sort
int partition(std::vector<int>& arr, int low, int high, Metrics& metrics) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        metrics.comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap_elements(arr[i], arr[j], metrics);
        }
    }
    swap_elements(arr[i + 1], arr[high], metrics);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high, Metrics& metrics) {
    if (low < high) {
        int pi = partition(arr, low, high, metrics);
        quickSort(arr, low, pi - 1, metrics);
        quickSort(arr, pi + 1, high, metrics);
    }
}