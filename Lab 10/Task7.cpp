#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("sensor_log.txt");

    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    outFile << "Temperature: 24C\n";
    cout << "Position after first write: " << outFile.tellp() << " bytes" << endl;

    outFile << "Humidity: 50%\n";
    cout << "Position after second write: " << outFile.tellp() << " bytes" << endl;

    outFile << "Pressure: 1013hPa\n";
    cout << "Position after third write: " << outFile.tellp() << " bytes" << endl;

    outFile.close();
    cout << "File closed." << endl;

    return 0;
}
