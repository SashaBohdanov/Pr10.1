#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void findThirdCommaPosition(const string& filename);

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    findThirdCommaPosition(filename);

    return 0;
}

void findThirdCommaPosition(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening the file." << endl;
        return;
    }

    string line;
    int lineNumber = 0;
    int positionInLine;

    while (getline(file, line)) {
        lineNumber++;

        int commaCount = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                commaCount++;
                if (commaCount == 3) {
                    positionInLine = i + 1;  // Position is 1-indexed
                    cout << "The third comma is at line " << lineNumber << ", position " << positionInLine << endl;
                    file.close();  // Close the file after finding the third comma
                    return;
                }
            }
        }
    }

    cout << "The third comma was not found in the file." << endl;
    file.close();  // Close the file in case it was not found
}
