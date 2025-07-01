#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <vector>

// Gera um vetor com dados inteiramente aleatórios.
std::vector<int> generateRandomData(int size);

// Gera um vetor quase ordenado (95% dos elementos estão em ordem).
std::vector<int> generateNearlySortedData(int size);

// Gera um vetor em ordem inversa (decrescente).
std::vector<int> generateReverseSortedData(int size);

#endif