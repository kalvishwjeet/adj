#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool isSafeBacktracking(const vector<vector<char>>& board, int row, int col, int N) {
    // Check if there is a queen in the same column up to the current row
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void solveNQueensUtilBacktracking(vector<vector<char>>& board, int row, int N, vector<vector<vector<char>>>& solutions) {
    if (row == N) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafeBacktracking(board, row, col, N)) {
            board[row][col] = 'Q';
            solveNQueensUtilBacktracking(board, row + 1, N, solutions);
            board[row][col] = '.';
        }
    }
}

vector<vector<vector<char>>> solveNQueensBacktracking(int N) {
    vector<vector<vector<char>>> solutions;
    vector<vector<char>> board(N, vector<char>(N, '.'));
    solveNQueensUtilBacktracking(board, 0, N, solutions);
    return solutions;
}

void printSolutionsBacktracking(const vector<vector<vector<char>>>& solutions) {
    if(solutions.size()==0){
        cout<<"No Solution Found for backtracking\n";
        return;
    }
    cout << "Backtracking Solutions:\n";
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

bool isSafeBranchBound(const vector<int>& cols, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (cols[i] == col || abs(i - row) == abs(cols[i] - col)) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtilBranchBound(vector<vector<int>>& solutions, vector<int>& cols, int row, int N) {
    if (row == N) {
        solutions.push_back(cols);
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (isSafeBranchBound(cols, row, col)) {
            cols[row] = col;
            solveNQueensUtilBranchBound(solutions, cols, row + 1, N);
        }
    }
}

vector<vector<int>> solveNQueensBranchBound(int N) {
    vector<vector<int>> solutions;
    vector<int> cols(N, -1);
    solveNQueensUtilBranchBound(solutions, cols, 0, N);
    return solutions;
}

void printSolutionsBranchBound(const vector<vector<int>>& solutions) {
    if (solutions.size() == 0)
    {
        cout << "No Solution Found for Branch and Bound \n";
        return;
    }
    cout << "Branch and Bound Solutions:\n";
    for (const auto& solution : solutions) {
        for (int row = 0; row < solution.size(); ++row) {
            for (int col = 0; col < solution.size(); ++col) {
                if (col == solution[row]) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Enter the value of N for N Queens problem: ";
    cin >> N;

    // Backtracking
    vector<vector<vector<char>>> solutionsBacktracking = solveNQueensBacktracking(N);
    printSolutionsBacktracking(solutionsBacktracking);

    // Branch and Bound
    vector<vector<int>> solutionsBranchBound = solveNQueensBranchBound(N);
    printSolutionsBranchBound(solutionsBranchBound);

    return 0;
}