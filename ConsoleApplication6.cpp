#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

// Function to find the maximum element in the array
int find_max_element(int arr[][COLS]) {
    int max_val = arr[0][0];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (arr[i][j] > max_val) {
                max_val = arr[i][j];
            }
        }
    }
    return max_val;
}

// Function to find the row and column indices of the maximum element
void find_max_element_indices(int arr[][COLS], int max_val, int& row, int& col) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (arr[i][j] == max_val) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Function to swap the row and column at the intersection of the maximum element
void swap_at_max_element(int arr[][COLS], int row, int col) {
    for (int i = 0; i < ROWS; ++i) {
        int temp = arr[i][row];
        arr[i][row] = arr[col][i];
        arr[col][i] = temp;
    }
}

// Function to find the row and column numbers with zero elements
void find_zero_elements(int arr[][COLS]) {
    cout << "Row and column numbers with zero elements:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (arr[i][j] == 0) {
                cout << "Row " << i + 1 << ", Column " << j + 1 << endl;
            }
        }
    }
}

int main() {
    int array[ROWS][COLS] = { {1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9} };

    // 1. Find the maximum element
    int max_val = find_max_element(array);

    // 2. Find the row and column with the maximum element
    int row, col;
    find_max_element_indices(array, max_val, row, col);

    // 3. Swap the row and column at the intersection of the maximum element
    swap_at_max_element(array, row, col);

    // Display the modified array
    cout << "Array after swapping:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    // 4. Find the row and column numbers with zero elements
    find_zero_elements(array);

    return 0;
}
