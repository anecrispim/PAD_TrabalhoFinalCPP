#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

// Função para multiplicar duas matrizes usando OpenMP
vector<vector<int>> multiplicarMatrizesParalela(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();
    
    vector<vector<int>> C(n, vector<int>(p, 0));
    
    // Paralelizar o loop sobre as linhas da matriz resultante
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0; // Inicializa o elemento C[i][j]
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
    
    // Multiplicando as matrizes A e B usando OpenMP
    double startTime = omp_get_wtime();
    vector<vector<int>> C = multiplicarMatrizesParalela(A, B);
    double endTime = omp_get_wtime();
    
    cout << "Matriz resultante C (100x100):" << endl;
    imprimirMatriz(C);
    
    // Tempo de execução
    double tempoExecucao = endTime - startTime;
    cout << "Tempo de execução: " << tempoExecucao << " segundos" << endl;
    
    return 0;
}
