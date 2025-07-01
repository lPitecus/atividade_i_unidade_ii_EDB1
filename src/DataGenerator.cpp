#include "DataGenerator.h"
#include <algorithm>
#include <numeric>
#include <random>

// Gera um vetor com dados inteiramente aleatórios.
std::vector<int> generateRandomData(int size) {
    std::vector<int> data(size);
    // std::iota preenche o vetor com valores crescentes: 0, 1, 2, ...
    std::iota(data.begin(), data.end(), 1);

    // Usa um gerador de números aleatórios de alta qualidade para embaralhar o vetor.
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(data.begin(), data.end(), g);

    return data;
}

// Gera um vetor quase ordenado.
std::vector<int> generateNearlySortedData(int size) {
    std::vector<int> data(size);
    // Começa com um vetor perfeitamente ordenado.
    std::iota(data.begin(), data.end(), 1);

    // Realiza um pequeno número de trocas aleatórias (5% do tamanho).
    int swaps = size * 0.05;
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> distrib(0, size - 1);

    for (int i = 0; i < swaps; ++i) {
        int idx1 = distrib(g);
        int idx2 = distrib(g);
        std::swap(data[idx1], data[idx2]);
    }

    return data;
}

// Gera um vetor em ordem inversa (decrescente).
std::vector<int> generateReverseSortedData(int size) {
    std::vector<int> data(size);
    // Começa com um vetor ordenado e depois o inverte.
    std::iota(data.begin(), data.end(), 1);
    std::reverse(data.begin(), data.end());
    return data;
}