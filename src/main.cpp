#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <functional>

#include "Sorters.h"
#include "DataGenerator.h"

// Estrutura para agrupar as informações de um teste
struct TestConfig {
    std::string algorithmName;
    std::function<void(std::vector<int>&, Metrics&)> sortFunction;
};

int main() {
    // Abre (ou cria) o arquivo para salvar os resultados
    std::ofstream outputFile("results/raw_data.csv");
    if (!outputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de resultados!" << std::endl;
        return 1;
    }

    // Escreve o cabeçalho do CSV
    outputFile << "Algoritmo,TipoDeDado,Tamanho,Tempo(us),Comparacoes,Trocas\n";

    // --- Parâmetros do Experimento ---
    std::vector<int> sizes = {1000, 5000, 10000, 20000, 50000};
    std::vector<std::string> dataTypes = {"Aleatorio", "Quase Ordenado", "Inversamente Ordenado"};

    // Lista de algoritmos a serem testados
    std::vector<TestConfig> tests = {
        {"BubbleSort", [](std::vector<int>& arr, Metrics& m){ bubbleSort(arr, m); }},
        {"InsertionSort", [](std::vector<int>& arr, Metrics& m){ insertionSort(arr, m); }},
        {"SelectionSort", [](std::vector<int>& arr, Metrics& m){ selectionSort(arr, m); }},
        {"MergeSort", [](std::vector<int>& arr, Metrics& m){ mergeSort(arr, 0, arr.size() - 1, m); }},
        {"QuickSort", [](std::vector<int>& arr, Metrics& m){ quickSort(arr, 0, arr.size() - 1, m); }}
    };

    Metrics metrics;

    
    for (int size : sizes) {
        for (const auto& dataType : dataTypes) {
            std::cout << "------------------------------------------\n";
            std::cout << "Iniciando testes para vetores de tamanho " << size << " com dados do tipo '" << dataType << "'...\n";
            
            // Gera o dado base para este tamanho e tipo
            std::vector<int> baseData;
            if (dataType == "Aleatorio") baseData = generateRandomData(size);
            else if (dataType == "Quase Ordenado") baseData = generateNearlySortedData(size);
            else if (dataType == "Inversamente Ordenado") baseData = generateReverseSortedData(size);

            for (const auto& test : tests) {
                // Cria uma cópia do vetor para não afetar os outros testes
                std::vector<int> dataToSort = baseData;
                
                // Reseta as métricas
                metrics.reset();

                // Medição do tempo
                auto startTime = std::chrono::high_resolution_clock::now();
                
                test.sortFunction(dataToSort, metrics); // Executa a ordenação
                
                auto endTime = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

                // Salva os resultados no arquivo
                outputFile << test.algorithmName << ","
                           << dataType << ","
                           << size << ","
                           << duration << ","
                           << metrics.comparisons << ","
                           << metrics.swaps << "\n";
                
                std::cout << "  -> " << test.algorithmName << " concluido em " << duration << " us.\n";
            }
        }
    }

    outputFile.close();
    std::cout << "\nExperimento concluido! Resultados salvos em 'results/raw_data.csv'\n";

    return 0;
}