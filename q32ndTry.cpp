#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> matrix, vector<string> commands) {

    auto swapRows = [&](int r1, int r2) {
        swap(matrix[r1], matrix[r2]);
    };

    auto swapColumns = [&](int c1, int c2) {
        for (int i = 0; i < matrix.size(); ++i)
            swap(matrix[i][c1], matrix[i][c2]);
    };

    auto reverseRow = [&](int r) {
        reverse(matrix[r].begin(), matrix[r].end());
    };

    auto reverseColumn = [&](int c) {
        int top = 0, bottom = matrix.size() - 1;
        while (top < bottom) {
            swap(matrix[top][c], matrix[bottom][c]);
            top++;
            bottom--;
        }
    };

    auto rotate90Clockwise = [&]() {
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<int>> res(C, vector<int>(R));
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                res[j][R - 1 - i] = matrix[i][j];
        matrix = res;
    };

    for (string cmd : commands) {
        stringstream ss(cmd);
        string op;
        ss >> op;

        if (op == "swapRows") {
            int r1, r2; ss >> r1 >> r2;
            swapRows(r1, r2);
        }
        else if (op == "swapColumns") {
            int c1, c2; ss >> c1 >> c2;
            swapColumns(c1, c2);
        }
        else if (op == "reverseRow") {
            int r; ss >> r;
            reverseRow(r);
        }
        else if (op == "reverseColumn") {
            int c; ss >> c;
            reverseColumn(c);
        }
        else if (op == "rotate90Clockwise") {
            rotate90Clockwise();
        }
    }

    return matrix;
}
