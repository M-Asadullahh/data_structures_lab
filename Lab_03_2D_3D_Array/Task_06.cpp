#include <iostream>
using namespace std;

int main() {
    int arr3D[2][2][2] = {
        {
            {10, 20},
            {30, 40}
        },
        {
            {50, 60},
            {70, 80}
        }
    };
    int targetVal = 70;

    cout << "3D Array:\n\n";

    int lay = 0;
    while (lay < 2) {
        cout << "Layer " << (lay + 1) << ":\n";
        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < 2; c++) {
                cout << arr3D[lay][r][c] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        lay++;
    }
    cout << "Searching for: " << targetVal << "\n\n";

    bool found = false;
    int foundLayer = -1, foundRow = -1, foundCol = -1;

    for (int l = 0; l < 2; l++) {
        int rIdx = 0;
        while (rIdx < 2) {
            for (int cIdx = 0; cIdx < 2; cIdx++) {
                if (arr3D[l][rIdx][cIdx] == targetVal) {
                    found = true;
                    foundLayer = l + 1;
                    foundRow = rIdx + 1;
                    foundCol = cIdx + 1;
                    break;
                }
            }
            if (found) break;
            rIdx++;
        }
        if (found) break;
    }
    if (found) {
        cout << "Element found!\n";
        cout << "Layer: " << foundLayer << "\n";
        cout << "Row: " << foundRow << "\n";
        cout << "Column: " << foundCol << "\n";
    }
    else {
        cout << "Element not found!\n";
    }

    return 0;
}