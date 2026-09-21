#include <iostream>
using namespace std;

int main() {
    int labGrid[2][3][5] = {
        {
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 1},
            {1, 0, 0, 0, 1}
        },
        {
            {0, 0, 1, 1, 0},
            {1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1}
        }
    };
    int totalAvailable = 0;
    int totalInUse = 0;
    int labAvailable[2] = { 0, 0 };

    cout << "=== Computer Labs Status ===\n";

    int lb = 0;
    while (lb < 2) {
        cout << "\n--- Lab " << (lb + 1) << " ---\n";

        for (int rw = 0; rw < 3; rw++) {
            cout << "Row " << rw << ": [ ";

            int pc = 0;
            while (pc < 5) {
                int status = labGrid[lb][rw][pc];
                cout << status << " ";

                if (status == 0) {
                    totalAvailable++;
                    labAvailable[lb]++;
                }
                else {
                    totalInUse++;
                }
                pc++;
            }
            cout << "]\n";
        }
        lb++;
    }
    cout << "\n=== Overall Summary ===\n";
    cout << "Total Available Computers: " << totalAvailable << "\n";
    cout << "Total Computers In Use: " << totalInUse << "\n";

    cout << "\n--- Available Computers Per Lab ---\n";
    for (int lIdx = 0; lIdx < 2; lIdx++) {
        cout << "Lab " << (lIdx + 1) << ": " << labAvailable[lIdx] << " available\n";
    }

    int selLab, selRow, selComp;
    cout << "\nEnter Lab (1-2), Row (0-2), and Computer (0-4) to check: ";
    cin >> selLab >> selRow >> selComp;

    int adjustedLab = selLab - 1;

    if (adjustedLab >= 0 && adjustedLab < 2 && selRow >= 0 && selRow < 3 && selComp >= 0 && selComp < 5) {
        if (labGrid[adjustedLab][selRow][selComp] == 0) {
            cout << "Computer at Lab " << selLab << ", Row " << selRow << ", Computer " << selComp << " is AVAILABLE.\n";
        }
        else {
            cout << "Computer at Lab " << selLab << ", Row " << selRow << ", Computer " << selComp << " is IN USE.\n";
        }
    }
    else {
        cout << "Invalid Lab, Row, or Computer number entered!\n";
    }

    return 0;
}