# Nome do compilador C++
CXX = g++

# Flags do compilador: -std=c++17 para usar a versão 17 do C++,
# -O2 para otimização de velocidade e -Wall para exibir todos os avisos.
CXXFLAGS = -std=c++17 -O2 -Wall

# Diretório do código-fonte
SRCDIR = src

# Diretório de saída para o binário
BINDIR = bin

# Nome do arquivo executável final
TARGET = $(BINDIR)/analysis_app

# Encontra todos os arquivos .cpp no diretório de código-fonte
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# A regra padrão (executada quando você digita 'make')
all: $(TARGET)

# Regra para construir o executável
$(TARGET): $(SOURCES)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para limpar os arquivos gerados (o binário e a pasta)
clean:
	@echo "Limpando builds anteriores..."
	rm -rf $(BINDIR)

# Declara que 'all' e 'clean' não são nomes de arquivos.
.PHONY: all clean