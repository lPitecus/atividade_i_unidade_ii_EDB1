import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os

def create_plots():
    """
    Lê os dados brutos e gera gráficos comparativos para as métricas
    de tempo, comparações e trocas.
    """
    # Define os caminhos para os arquivos
    csv_path = 'results/raw_data.csv'
    output_dir = 'results/graphs'

    # Verifica se o arquivo de dados existe
    if not os.path.exists(csv_path):
        print(f"Erro: O arquivo '{csv_path}' não foi encontrado.")
        print("Por favor, execute o programa em C++ primeiro para gerar os dados.")
        return

    # Cria o diretório para salvar os gráficos, se não existir
    os.makedirs(output_dir, exist_ok=True)

    # Carrega os dados usando pandas
    try:
        df = pd.read_csv(csv_path)
    except pd.errors.EmptyDataError:
        print(f"Erro: O arquivo '{csv_path}' está vazio.")
        return

    # Estilo dos gráficos
    sns.set_theme(style="whitegrid")

    # Lista das métricas que queremos plotar
    metrics_to_plot = {
        'Tempo(us)': {'ylabel': 'Tempo (microssegundos)', 'title_prefix': 'Tempo de Execução'},
        'Comparacoes': {'ylabel': 'Número de Comparações', 'title_prefix': 'Comparações'},
        'Trocas': {'ylabel': 'Número de Trocas/Movimentações', 'title_prefix': 'Trocas'}
    }

    # Gera um conjunto de gráficos para cada tipo de dado
    data_types = df['TipoDeDado'].unique()
    
    cont_ext = 1
    for metric, labels in metrics_to_plot.items():
        cont_int = 1
        for data_type in data_types:
            plt.figure(figsize=(12, 8))
            
            # Filtra o dataframe para o tipo de dado atual
            subset_df = df[df['TipoDeDado'] == data_type]
            
            # Cria o gráfico de linhas
            ax = sns.lineplot(
                data=subset_df,
                x='Tamanho',
                y=metric,
                hue='Algoritmo',
                style='Algoritmo',
                markers=True,
                dashes=False
            )
            
            # Usar escala logarítmica no eixo Y para melhor visualização,
            # já que algoritmos O(n^2) crescem muito mais rápido que O(n log n).
            ax.set_yscale('log')
            
            # Define títulos e rótulos claros para garantir a legibilidade 
            title = f"{labels['title_prefix']} vs. Tamanho do Vetor ({data_type})"
            plt.title(title, fontsize=16)
            plt.xlabel('Tamanho do Vetor (N)', fontsize=12)
            plt.ylabel(f"{labels['ylabel']} (Escala Logarítmica)", fontsize=12)
            plt.legend(title='Algoritmo')
            plt.tight_layout() # Ajusta o gráfico para caber na figura

            # Salva o gráfico em formato PNG 
            output_filename = os.path.join(output_dir, f'{cont_ext}.{cont_int}{metric.replace("(us)","")}_{data_type.replace(" ", "")}.png')
            plt.savefig(output_filename)
            plt.close() # Fecha a figura para liberar memória

            print(f"Gráfico salvo em: {output_filename}")
            cont_int += 1
        cont_ext += 1

if __name__ == '__main__':
    create_plots()
    print("\nProcesso de geração de gráficos concluído com sucesso!")