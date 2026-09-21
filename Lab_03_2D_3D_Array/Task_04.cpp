#include <iostream>
using namespace std;

int main() {
    int hospitalGrid[3][3][4] = {
        {
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1}
        },
        {
            {1, 1, 0, 0},
            {0, 0, 1, 1},
            {1, 0, 0, 1}
        },
        {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 0, 1, 0}
        }
    };
    int totalOccupied = 0;
    int totalAvailable = 0;
    int floorOccupied[3] = { 0, 0, 0 };

    cout << "=== Hospital Bed Status ===\n";

    int flr = 0;
    while (flr < 3) {
        cout << "\n--- Floor " << flr << " ---\n";

        for (int wrd = 0; wrd < 3; wrd++) {
            cout << "Ward " << wrd << ": [ ";

            int bd = 0;
            while (bd < 4) {
                int status = hospitalGrid[flr][wrd][bd];
                cout << status << " ";

                if (status == 1) {
                    totalOccupied++;
                    floorOccupied[flr]++;
                }
                else {
                    totalAvailable++;
                }
                bd++;
            }
            cout << "]\n";
        }
        flr++;
    }

    cout << "\n=== Hospital Summary ===\n";
    cout << "Total Occupied Beds: " << totalOccupied << "\n";
    cout << "Total Available Beds: " << totalAvailable << "\n";

    cout << "\n--- Occupied Beds Per Floor ---\n";
    for (int fIdx = 0; fIdx < 3; fIdx++) {
        cout << "Floor " << fIdx << ": " << floorOccupied[fIdx] << " occupied beds\n";
    }

    int selFloor, selWard, selBed;
    cout << "\nEnter Floor (0-2), Ward (0-2), and Bed (0-3) to check: ";
    cin >> selFloor >> selWard >> selBed;

    if (selFloor >= 0 && selFloor < 3 && selWard >= 0 && selWard < 3 && selBed >= 0 && selBed < 4) {
        if (hospitalGrid[selFloor][selWard][selBed] == 1) {
            cout << "Bed at Floor " << selFloor << ", Ward " << selWard << ", Bed " << selBed << " is OCCUPIED.\n";
        }
        else {
            cout << "Bed at Floor " << selFloor << ", Ward " << selWard << ", Bed " << selBed << " is AVAILABLE.\n";
        }
    }
    else {
        cout << "Invalid Floor, Ward, or Bed number entered!\n";
    }

    return 0;
}
