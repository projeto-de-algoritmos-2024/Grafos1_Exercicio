#include <iostream>
#include <queue>
using namespace std;

struct Coord {
    int row, col;
    Coord(int r, int c) : row(r), col(c) {}
};

bool isValid(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

void floodFill(int** matrix, int rows, int cols, int start_row, int start_col, int new_color) {
    int original_color = matrix[start_row][start_col];
    if (original_color == new_color) return;

    queue<Coord> q;
    q.push(Coord(start_row, start_col));

    while (!q.empty()) {
        Coord current = q.front();
        q.pop();
        int row = current.row;
        int col = current.col;
        matrix[row][col] = new_color;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; ++i) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];
            if (isValid(new_row, new_col, rows, cols) && matrix[new_row][new_col] == original_color) {
                q.push(Coord(new_row, new_col));
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main (){
    int linha, coluna;
    cout << "Digite o número de linhas da matriz: ";
    cin >> linha;
    cout << "Digite o número de colunas da matriz: ";
    cin >> coluna;

    int** matrix = new int*[linha];
    for (int i = 0; i < linha; ++i) {
        matrix[i] = new int[coluna];
    }

    cout << "Digite os elementos da matriz:" << endl;
    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            cin >> matrix[i][j];
        }
    }

    int preencer_linha, preencher_coluna;
    cout << "Digite a linha de partida (de 0 a " << linha-1 << ") para o flood fill: ";
    cin >> preencer_linha;
    cout << "Digite a coluna de partida (de 0 a " << coluna-1 << ") para o flood fill: ";
    cin >> preencher_coluna;

    int cor;
    cout << "Digite a nova cor para preencher: ";
    cin >> cor;

    floodFill(matrix, linha, coluna, preencer_linha, preencher_coluna, cor);

    cout << "\nMatriz após o flood fill:" << endl;
    printMatrix(matrix, linha, coluna);

    for (int i = 0; i < linha; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}