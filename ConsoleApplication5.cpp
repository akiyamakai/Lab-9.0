#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;

    cout << "k: ";
    cin >> rows;
    cout << "p: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Element massu:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int k, p;
    cout << "Delete k: ";
    cin >> k;
    cout << "Delete p: ";
    cin >> p;

    matrix.erase(matrix.begin() + k - 1);

    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i].erase(matrix[i].begin() + p - 1);
    }

    vector<int> odd_elements;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] % 2 != 0) {
                odd_elements.push_back(matrix[i][j]);
            }
        }
    }

    cout << "Neparni elementu: ";
    for (int i = 0; i < odd_elements.size(); ++i) {
        cout << odd_elements[i] << " ";
    }
    cout << endl;

    return 0;
}
