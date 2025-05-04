#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("large_log.txt");

    if (!file) {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    char buffer[11];
    file.read(buffer, 10);
    buffer[10] = '\0';
    cout << "First 10 characters: " << buffer << endl;
    cout << "Position after first read: " << file.tellg() << endl;

    file.read(buffer, 10);
    buffer[10] = '\0';
    cout << "Next 10 characters: " << buffer << endl;
    cout << "Position after second read: " << file.tellg() << endl;

    file.close();
    return 0;
}
