#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("data_records.txt");

    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    
    int offset = 9 * 2;


    file.seekg(offset, ios::beg);

    string line;
    getline(file, line);
    cout << "Third record: " << line << endl;

    file.close();
    return 0;
}
