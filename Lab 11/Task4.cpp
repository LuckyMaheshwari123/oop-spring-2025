#include <iostream>
#include <cmath>
#include <stdexcept>
#include <type_traits>

using namespace std;

template<typename T>
T mySqrt(T value) {
    if constexpr (!is_arithmetic_v<T>) {
        throw invalid_argument("Non-numeric type is not allowed");
    } else {
        if (value < 0) {
            throw domain_error("Cannot calculate square root of a negative number");
        }
        return sqrt(value);
    }
}

int main() {
    try {
        cout << mySqrt(25.0) << endl;
        cout << mySqrt(-9) << endl;
        cout << mySqrt(string("test")) << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
