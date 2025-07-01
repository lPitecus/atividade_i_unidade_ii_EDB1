# Análise Comparativa de Algoritmos de Ordenação

Este projeto é uma implementação prática para a disciplina **IMD0029 - Estrutura de Dados Básicas 1** da Universidade Federal do Rio Grande do Norte (UFRN).

O objetivo é realizar uma análise comparativa do desempenho de cinco algoritmos de ordenação clássicos:
* Bubble Sort
* Insertion Sort
* Selection Sort
* Merge Sort
* Quick Sort

O sistema foi desenvolvido em C++ para a execução e coleta de métricas de alta performance e utiliza Python para a análise e visualização dos dados coletados.

## Pré-requisitos

Antes de executar, garanta que você tenha os seguintes softwares instalados em seu sistema:
* Um compilador C++ moderno (ex: `g++`)
* Python 3.8 ou superior
* `pip` (gerenciador de pacotes do Python)

## Como Executar o Projeto Completo

O projeto foi configurado com um script de automação que cuida de todo o processo: compilação, execução e análise.

Para executar o workflow completo, basta seguir os passos:

1.  **Clone o repositório:**
    ```sh
    git clone https://github.com/lPitecus/atividade_i_unidade_ii_EDB1
    cd atividade_i_unidade_ii_EDB1
    ```

2.  **Execute o script principal:**
    ```sh
    chmod +x excutar_projeto.sh
    ./executar_projeto.sh
    ```
    *Este único comando irá:*
    1.  Compilar o código-fonte C++ localizado na pasta `/src`.
    2.  Criar um ambiente virtual para o Python na pasta `/.venv`.
    3.  Instalar as dependências listadas em `requirements.txt`.
    4.  Executar o programa C++ para coletar as métricas de desempenho.
    5.  Executar o script Python para analisar os dados e gerar os gráficos comparativos.

## Onde os Resultados são Salvos

Após a execução do script, todos os resultados gerados serão salvos na pasta `/results` na raiz do projeto:

* **Dados Brutos:** O arquivo com todas as métricas coletadas (tempo, comparações, trocas) será salvo em:
    * `results/raw_data.csv`

* **Gráficos Comparativos:** Os gráficos em formato de imagem (`.png`) gerados pela análise do Python serão salvos no diretório:
    * `results/graphs/`