#include <iostream>
#include <cstring>

using namespace std;


char* inputString() {
    char* str = new char[100];  
    cout << "Enter a string: ";
    cin.getline(str, 100);  
    return str;
}


char* concatenateStrings(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    char* result = new char[len1 + len2 + 1];  


    strcpy(result, str1);
 
    strcat(result, str2);

    return result;
}


int compareStrings(const char* str1, const char* str2) {
    return strcmp(str1, str2); 
}


int getStringLength(const char* str) {
    return strlen(str); 
}

int main() {

   char* str1 = inputString();
   char* str2 = inputString();

  
    cout << "\nLength of first string: " << getStringLength(str1);
    cout << "\nLength of second string: " << getStringLength(str2);

    char* concatenatedString = concatenateStrings(str1, str2);
    cout << "\nConcatenated string: " << concatenatedString;

 
   int comparisonResult = compareStrings(str1, str2);
    if (comparisonResult == 0) {
        cout << "\nThe two strings are equal.";
    } else if (comparisonResult < 0) {
        cout << "\nThe first string is lexicographically smaller than the second string.";
        cout << "\nThe first string is alphabetically smaller than the second string.";
    } else {
        cout << "\nThe first string is lexicographically greater than the second string.";
        cout << "\nThe first string is alphabetically greater than the second string.";
    }


    delete[] str1;
    delete[] str2;
    delete[] concatenatedString;

    return 0;
}
