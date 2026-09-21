#include <iostream>
#include <string>

using namespace std;

int main() {
    int marksArr[6][4];
    float totalMarks[6];
    float avgMarks[6];
    string subNames[4] = { "English", "Mathematics", "Programming", "AI" };

    float maxTotal = -1.0f; 
    int topStudent = 0;

    for (int stIndex = 0; stIndex < 6; stIndex++) {
        cout << "Enter marks for Student " << (stIndex + 1) << ":\n";
        float tempSum = 0;
        int subIndex = 0;

        while (subIndex < 4) {
            cout << "  " << subNames[subIndex] << ": ";
            cin >> marksArr[stIndex][subIndex];
            tempSum += marksArr[stIndex][subIndex];
            subIndex++;
        }

        totalMarks[stIndex] = tempSum;
        avgMarks[stIndex] = tempSum / 4.0f;

        if (tempSum > maxTotal) {
            maxTotal = tempSum;
            topStudent = stIndex + 1;
        }
        cout << "\n";
    }
    cout << "--- Marks Table ---\n";
    cout << "Student\tEng\tMath\tProg\tAI\tTotal\tAvg\n";

    int r = 0;
    while (r < 6) {
        cout << "Student " << (r + 1) << "\t";
        for (int c = 0; c < 4; c++) {
            cout << marksArr[r][c] << "\t";
        }
        cout << totalMarks[r] << "\t" << avgMarks[r] << "\n";
        r++;
    }
    cout << "\nHighest score in each subject:\n";
    for (int col = 0; col < 4; col++) {
        int highestVal = marksArr[0][col];
        int row = 1;

        while (row < 6) {
            if (marksArr[row][col] > highestVal) {
                highestVal = marksArr[row][col];
            }
            row++;
        }
        cout << subNames[col] << ": " << highestVal << "\n";
    }
    cout << "\nStudent with highest overall marks: Student " << topStudent << " (" << maxTotal << " total)\n";

    return 0;
}