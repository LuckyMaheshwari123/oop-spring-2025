#include <iostream>
#include <exception>
using namespace std;

class StackException : public exception {
    string message;
public:
    StackException(string msg) {
        message = msg;
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class Stack {
    T* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    void push(T value) {
        if (top >= capacity - 1)
            throw StackException("Stack Exception: Full Stack!");
        arr[++top] = value;
    }

    T pop() {
        if (top == -1)
            throw StackException("Stack Exception: No Member to Pop!");
        return arr[top--];
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    Stack<int> s(size);

    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.display();

        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;
        s.display();
    } catch (const StackException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
