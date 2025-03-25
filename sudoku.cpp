#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        { // Recorrer las filas

            // Crear vectores para verificar filas, columnas y subcuadrículas
            vector<int> row(9, 0);
            vector<int> col(9, 0);
            vector<int> box(9, 0);

            for (int j = 0; j < 9; j++)
            {
                // Verificar fila
                if (board[i][j] != '.')
                { // Si la casilla no está vacía
                    if (row[board[i][j] - '1'] == 1)
                    {
                        return false;
                    }
                    row[board[i][j] - '1'] = 1;
                }

                // Verificar columna
                if (board[j][i] != '.')
                {
                    if (col[board[j][i] - '1'] == 1)
                    {
                        return false;
                    }
                    col[board[j][i] - '1'] = 1;
                }

                // Verificar subcuadrícula de 3x3
                int x = 3 * (i / 3) + j / 3;
                int y = 3 * (i % 3) + j % 3;
                if (board[x][y] != '.')
                {
                    if (box[board[x][y] - '1'] == 1)
                    {
                        return false;
                    }
                    box[board[x][y] - '1'] = 1;
                }
            }
        }
        return true;
    }
};

bool isValidSudoku(vector<vector<char>> &board)
{
    Solution s;
    return s.isValidSudoku(board);
}
int main()
{
    vector<vector<char>> board(9, vector<char>(9, '.')); // Matriz 9x9 inicializada con '.'

    cout << "Ingresa el Sudoku fila por fila (usa '.' para espacios vacíos):\n";

    // Entrada del usuario
    for (int i = 0; i < 9; i++)
    {
        string row;
        cout << "Fila " << i + 1 << ": ";
        cin >> row; // Lee una línea de 9 caracteres
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = row[j]; // Asigna cada carácter a la celda correspondiente
        }
    }

    // Llamar a la función para verificar si el Sudoku es válido
    if (isValidSudoku(board))
    {
        cout << "El Sudoku es válido.\n";
    }
    else
    {
        cout << "El Sudoku NO es válido.\n";
    }

    return 0;
}