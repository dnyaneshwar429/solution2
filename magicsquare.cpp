// 6)Write a program to construct and verify a magic square of order 'n' (for both even
// & odd) such that all rows, columns, and diagonals sum to the same value.
#include <iostream>
#include <vector>
using namespace std;

// ------------------ Verify Magic Square ------------------------
bool verifyMagicSquare(const vector<vector<int>>& magic, int n) {
    int magicSum = n * (n * n + 1) / 2;

    // Check rows
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++)
            rowSum += magic[i][j];
        if (rowSum != magicSum) return false;
    }

    // Check columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++)
            colSum += magic[i][j];
        if (colSum != magicSum) return false;
    }

    // Check diagonals
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        d1 += magic[i][i];
        d2 += magic[i][n - 1 - i];
    }
    if (d1 != magicSum || d2 != magicSum) return false;

    return true;
}

// ------------ Construct Magic Square (Odd Order) -----------------
vector<vector<int>> oddMagic(int n) {
    vector<vector<int>> magic(n, vector<int>(n, 0));

    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magic[i][j] = num;

        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (magic[newi][newj] != 0) 
            i = (i + 1) % n;
        else {
            i = newi;
            j = newj;
        }
    }

    return magic;
}

// ------------ Construct Magic Square (Doubly Even 4k) --------------
vector<vector<int>> doublyEvenMagic(int n) {
    vector<vector<int>> magic(n, vector<int>(n));

    int num = 1;
    int total = n * n;

    // Fill the matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magic[i][j] = num++;

    // Inverse certain positions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if ((i % 4 == j % 4) || (i % 4 + j % 4 == 3))
                magic[i][j] = total + 1 - magic[i][j];
        }
    }

    return magic;
}

// ------------ Construct Magic Square (Singly Even 4k+2) --------------
vector<vector<int>> singlyEvenMagic(int n) {
    int half = n / 2;
    int subSize = half * half;

    vector<vector<int>> sub = oddMagic(half);
    vector<vector<int>> magic(n, vector<int>(n));

    // Fill 4 sub-squares
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            int value = sub[i][j];

            magic[i][j] = value;
            magic[i][j + half] = value + 2 * subSize;
            magic[i + half][j] = value + 3 * subSize;
            magic[i + half][j + half] = value + subSize;
        }
    }

    // Swap left columns
    int k = (n - 2) / 4;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (i < half) 
                swap(magic[i][j], magic[i + half][j]);
        }
        for (int j = n - k + 1; j < n; j++) {
            if (i < half)
                swap(magic[i][j], magic[i + half][j]);
        }
    }

    // Special middle column swap
    swap(magic[k][0], magic[k + half][0]);
    swap(magic[k][k], magic[k + half][k]);

    return magic;
}

// ------------------ MAIN FUNCTION ----------------------
int main() {
    int n;
    cout << "Enter order of Magic Square (n >= 3): ";
    cin >> n;

    vector<vector<int>> magic;

    if (n % 2 == 1) {
        magic = oddMagic(n);
    } 
    else if (n % 4 == 0) {
        magic = doublyEvenMagic(n);
    } 
    else {
        magic = singlyEvenMagic(n);
    }

    // Print Magic Square
    cout << "\nMagic Square of order " << n << ":\n";
    for (auto &row : magic) {
        for (auto &x : row)
            cout << x << "\t";
        cout << "\n";
    }

    // Verify
    if (verifyMagicSquare(magic, n))
        cout << "\nThis is a VALID Magic Square.\n";
    else
        cout << "\nInvalid Magic Square.\n";

    return 0;
}
