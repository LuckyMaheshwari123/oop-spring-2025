#include <iostream>
#include <string>
using namespace std;

class FileEx {
public:
    virtual string what() const {
        return "FileEx";
    }
};

class NotFoundEx : public FileEx {
public:
    string what() const override {
        return "NotFoundEx - File not found!";
    }
};

class DeniedEx : public FileEx {
public:
    string what() const override {
        return "DeniedEx - Access denied!";
    }
};

void read(const string& fname) {
    if (fname == "missing.txt") throw NotFoundEx();
    else if (fname == "secret.txt") throw DeniedEx();
    else cout << "Reading file: " << fname << endl;
}

int main() {
    string files[] = {"data.txt", "missing.txt", "secret.txt"};
    for (const string& f : files) {
        try {
            read(f);
        } catch (const NotFoundEx& e) {
            cout << "Reading '" << f << "': " << e.what() << endl;
        } catch (const DeniedEx& e) {
            cout << "Reading '" << f << "': " << e.what() << endl;
        } catch (const FileEx& e) {
            cout << "Reading '" << f << "': " << e.what() << endl;
        }
    }
    return 0;
}
