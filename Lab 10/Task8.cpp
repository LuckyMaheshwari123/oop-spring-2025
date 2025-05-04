#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream createFile("config.txt");
    if (!createFile) {
        cerr << "Error creating file." << endl;
        return 1;
    }
    createFile << "AAAAAABBBBBCCCCC";
    createFile.close();

    fstream file("config.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    file.seekp(5, ios::beg);
    file << "XXXXX";

    file.close();
    ifstream checkFile("config.txt");
    string content;
    getline(checkFile, content);
    cout << "Updated file content: " << content << endl;
    checkFile.close();

    return 0;
}
