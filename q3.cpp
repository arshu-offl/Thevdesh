#include <bits/stdc++.h>
using namespace std;

using Matrix = vector<vector<int>>;

void swapRows(Matrix &mat, int r1, int r2) {
    swap(mat[r1], mat[r2]);
}

void swapColumns(Matrix &mat, int c1, int c2) {
    int rows = mat.size();
    for (int i = 0; i < rows; ++i) {
        swap(mat[i][c1], mat[i][c2]);
    }
}

void reverseRow(Matrix &mat, int r) {
    reverse(mat[r].begin(), mat[r].end());
}

void reverseColumn(Matrix &mat, int c) {
    int rows = mat.size();
    for (int i = 0, j = rows - 1; i < j; ++i, --j) {
        swap(mat[i][c], mat[j][c]);
    }
}

Matrix rotate90Clockwise(const Matrix &mat) {
    int r = mat.size();
    int c = mat.empty() ? 0 : mat[0].size();
    Matrix res(c, vector<int>(r));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            res[j][r - 1 - i] = mat[i][j];
    return res;
}

void applyCommand(Matrix &mat, const string &cmd) {
    // split command by spaces
    stringstream ss(cmd);
    string op;
    ss >> op;

    if (op == "swapRows") {
        int r1, r2; ss >> r1 >> r2;
        swapRows(mat, r1, r2);
    } else if (op == "swapColumns") {
        int c1, c2; ss >> c1 >> c2;
        swapColumns(mat, c1, c2);
    } else if (op == "reverseRow") {
        int r; ss >> r;
        reverseRow(mat, r);
    } else if (op == "reverseColumn") {
        int c; ss >> c;
        reverseColumn(mat, c);
    } else if (op == "rotate90Clockwise") {
        mat = rotate90Clockwise(mat);
    } else {
        // unknown op - ignore or throw
        // For safety, we'll ignore silently (problem guarantees valid commands)
    }
}

void printMatrix(const Matrix &mat) {
    cout << "[\n";
    for (const auto &row : mat) {
        cout << "  [";
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j];
            if (j + 1 < row.size()) cout << ", ";
        }
        cout << "],\n";
    }
    cout << "]\n";
}

int main() {
    // Example 1 from screenshot:
    // matrix = [
    //  [1,2,3],
    //  [4,5,6],
    //  [7,8,9]
    // ]
    // commands = ["swapRows 0 2", "swapColumns 1 2", "reverseRow 0", "reverseColumn 2", "rotate90Clockwise"]
    Matrix m1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<string> cmds1 = {
        "swapRows 0 2",
        "swapColumns 1 2",
        "reverseRow 0",
        "reverseColumn 2",
        "rotate90Clockwise"
    };

    cout << "Example 1 - before:\n";
    printMatrix(m1);
    for (auto &c : cmds1) applyCommand(m1, c);
    cout << "Example 1 - after:\n";
    printMatrix(m1);
    // Expected (from screenshot):
    // [
    //  [1, 4, 8],
    //  [3, 6, 9],
    //  [7, 5, 2]
    // ]

    // Example 2 from screenshot (smaller rectangular example):
    // matrix = [
    //  [1, 4, 2],
    //  [5, 2, 7]
    // ]
    // commands = ["reverseRow 0", "swapColumns 0 2", "reverseColumn 1", "rotate90Clockwise"]
    Matrix m2 = {
        {1,4,2},
        {5,2,7}
    };
    vector<string> cmds2 = {
        "reverseRow 0",
        "swapColumns 0 2",
        "reverseColumn 1",
        "rotate90Clockwise"
    };

    cout << "\nExample 2 - before:\n";
    printMatrix(m2);
    for (auto &c : cmds2) applyCommand(m2, c);
    cout << "Example 2 - after:\n";
    printMatrix(m2);
    // Expected (per screenshot): final 3x2 matrix shown in examples

    // Note: screenshot reference: /mnt/data/Screenshot 2025-11-22 at 12.25.27 AM.png

    return 0;
}
