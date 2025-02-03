
#include <iostream>
using namespace std;

#include <iostream>
#include <string>

using namespace std;

class Markerpen {
public:
    string brand;
    string color;
    int inklevel;
    int maxink;


    void set(string b, string c, int i, int r) {
        brand = b;
        color = c;
        inklevel = i;
        maxink = r;
    }


    void write() {
        if (inklevel <= 0) {
            cout << "You cannot write due to insufficient ink." << endl;
            return;
        } else {
            inklevel--;
            cout << "Written successfully." << endl;
        }
    }


    void refill(int level) {
        if (inklevel >= maxink) {
            cout << "Your marker is already fully filled." << endl;
            return;
        }

        int amountToRefill = maxink - inklevel;
        inklevel += amountToRefill; // Refill to maximum level
        cout << "Refilled successfully." << endl;
    }
};

int main() {
    Markerpen m1;
    string b, c;
    int r, i;

    cout << "Enter the brand name: ";
    cin >> b;
    cout << "Enter the color: ";
    cin >> c;
    cout << "Enter the current ink level: ";
    cin >> i;
    cout << "Enter the maximum ink level: ";
    cin >> r;

    m1.set(b, c, i, r);

    int choice = 1;

    while (choice != 4) {
        cout << "\nEnter 1 to write\nEnter 2 to check level\nEnter 3 to refill\nEnter 4 to exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                m1.write();
                break;
            case 2:
                cout << "Current ink level is: " << m1.inklevel << endl;
                break;
            case 3:
                m1.refill(m1.inklevel);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid input." << endl;
        }
    }

    return 0;
}
