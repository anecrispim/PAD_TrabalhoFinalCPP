#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Função para multiplicar duas matrizes
vector<vector<int>> multiplicarMatrizes(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();
    
    vector<vector<int>> C(n, vector<int>(p, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return C;
}

// Função para imprimir uma matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& linha : matriz) {
        for (int valor : linha) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

// Função para criar uma matriz com valores aleatórios
vector<vector<int>> criarMatrizAleatoria(int linhas, int colunas) {
    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            matriz[i][j] = rand() % 10;
        }
    }
    return matriz;
}

int main() {
    int tamanho = 100;
    
    vector<vector<int>> A = criarMatrizAleatoria(tamanho, tamanho);
    vector<vector<int>> B = criarMatrizAleatoria(tamanho, tamanho);
    
    clock_t startTime = clock();
    vector<vector<int>> C = multiplicarMatrizes(A, B);
    clock_t endTime = clock();
    
    cout << "Matriz resultante C (100x100):" << endl;
    imprimirMatriz(C);
    
    // Tempo de execução
    double tempoExecucao = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Tempo de execução: " << tempoExecucao << " segundos" << endl;
    
    return 0;
}
