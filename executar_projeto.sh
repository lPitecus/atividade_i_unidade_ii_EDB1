#!/bin/bash

# Script refatorado para automatizar todo o fluxo do projeto,
# incluindo a criação e gerenciamento de um ambiente virtual Python.
#
# O comando 'set -e' garante que o script pare imediatamente se qualquer
# um dos comandos falhar.
set -e

# Nome do diretório do ambiente virtual
VENV_DIR=".venv"

echo "=================================================="
echo "    INICIANDO WORKFLOW DE ANÁLISE DE ALGORITMOS   "
echo "=================================================="
echo ""

# ETAPA 1: Compilar o código-fonte C++
echo "==> ETAPA 1: Compilando o código C++ de 'src/'..."
g++ -std=c++17 -O2 src/*.cpp -o bin/analysis_app
echo "--> Compilação C++ concluída com sucesso!"
echo ""

# ETAPA 2: Executar o programa C++ para gerar o arquivo de dados
echo "==> ETAPA 2: Executando o binário para gerar 'raw_data.csv'..."
./bin/analysis_app
echo "--> Arquivo 'raw_data.csv' gerado com sucesso em 'results/'!"
echo ""

# ETAPA 3: Preparar o ambiente Python e executar a análise
echo "==> ETAPA 3: Preparando o ambiente Python..."

# 3.1: Criar ambiente virtual se ele não existir
if [ ! -d "$VENV_DIR" ]; then
    echo "--> Ambiente virtual '$VENV_DIR' não encontrado. Criando..."
    python3 -m venv $VENV_DIR
    echo "--> Ambiente virtual criado."
else
    echo "--> Ambiente virtual '$VENV_DIR' já existe."
fi

# 3.2: Ativar o ambiente virtual
source "$VENV_DIR/bin/activate"
echo "--> Ambiente virtual ativado."

# 3.3: Instalar as dependências do requirements.txt
echo "--> Instalando/verificando dependências do Python..."
pip install -r requirements.txt
echo "--> Dependências prontas."

# 3.4: Executar o script Python de análise
echo "--> Executando o script Python para gerar os gráficos..."
python3 analysis/analyze_results.py
echo "--> Geração de gráficos concluída!"
echo ""

# Desativa o ambiente virtual ao final do script (boa prática)
deactivate

echo "=================================================="
echo "          PROCESSO FINALIZADO COM SUCESSO!        "
echo "=================================================="