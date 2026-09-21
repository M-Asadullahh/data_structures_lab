#include <iostream>

using namespace std;

int main() {
    int parkGrid[4][5] = {
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 1}
    };

    int occCount = 0;
    int emptyCount = 0;

    cout << "--- Current Parking Layout ---\n";
    cout << "      Col 0 Col 1 Col 2 Col 3 Col 4\n";

    int r = 0;
    while (r < 4) {
        cout << "Row " << r << ":  ";
        for (int c = 0; c < 5; c++) {
            cout << parkGrid[r][c] << "     ";

            if (parkGrid[r][c] == 1) {
                occCount++;
            }
            else {
                emptyCount++;
            }
        }
        cout << "\n";
        r++;
    }

    int totalCap = 4 * 5; 

    cout << "\n--- Parking Summary ---\n";
    cout << "Total Capacity: " << totalCap << " spaces\n";
    cout << "Occupied Spaces: " << occCount << "\n";
    cout << "Empty Spaces: " << emptyCount << "\n";

    int userRow, userCol;
    cout << "\nEnter row (0-3) and column (0-4) to check: ";
    cin >> userRow >> userCol;

    if (userRow >= 0 && userRow < 4 && userCol >= 0 && userCol < 5) {
        if (parkGrid[userRow][userCol] == 1) {
            cout << "Space at [" << userRow << "][" << userCol << "] is currently OCCUPIED.\n";
        }
        else {
            cout << "Space at [" << userRow << "][" << userCol << "] is AVAILABLE.\n";
        }
    }
    else {
        cout << "Invalid row or column entered!\n";
    }

    return 0;
}