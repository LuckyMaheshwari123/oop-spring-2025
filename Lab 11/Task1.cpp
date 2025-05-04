#include <iostream>
#include <exception>
using namespace std;

class InvalidException : public exception {
    string message;
public:
    InvalidException(string msg) {
        message = msg;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

void checkAge(int age) {
    if (age < 0)
        throw InvalidException("Age can't be negative!");
    else if (age > 120)
        throw InvalidException("Age can't be greater than 120!");
    else
        cout << "Age is valid: " << age << endl;
}

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    try {
        checkAge(age);
    } catch (const InvalidException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
