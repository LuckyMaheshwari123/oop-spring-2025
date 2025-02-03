#include <iostream>
using namespace std;
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    while (start < end) {
        swap(start, end);
        start++;
        end--;
    }
}

int main() {
    int n;

    
    cout << "Enter the size of the array: ";
    cin >> n;

   
    int *arr = new int[n];

    
    cout << "Enter " << n << " elements for the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    
    cout << "Swapping the first two elements..." << endl;
    if (n >= 2) {
        swap(&arr[0], &arr[1]);
    }

    cout << "Array after swapping the first two elements: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;


    reverseArray(arr, n);

  
    cout << "Array after reversing: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

 
    delete[] arr;

    return 0;
}
