#include <iostream>
#include "book.h"

using namespace std;

int main()
{
    Book *b1 = new Book("work Hard Enough to get Lucky", "Lucky Maheshwari", "123456789");
    Book *b2 = new Book("Fiction by srk", "ShahRukh Khan", "12345678978");
    Book *b3 = new Book("From Rags to Rich", "Elon Musk", "12345678689");
    cout << "The title is:" << b1->getTitle() << endl;
    cout << "The author is:" << b1->getAuthor() << endl;
    cout << "The isbn is:" << b1->getIsbn() << endl;
    Library l1;
    l1.addBook(*b1);
    l1.addBook(*b2);
    l1.addBook(*b3);
    l1.searchBook("123456789");
    l1.removeBook("12345678922");

    return 0;
}
