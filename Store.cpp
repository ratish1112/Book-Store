#include "Store.h"

void Store::get_data() {
    // Gets data from the user for adding to the file
    
    cin.ignore();
    
    cout << "\nEnter the name of the book:" << endl;
    getline (cin, book_name1);
    
    cout << "\nEnter author's name: ";
    getline(cin,author_name);
    
    cout << "\nEnter price(in Rs.): ";
    cin >> price;
    
    cout << "\nEnter quantity:\n";
    cin >> quantity;
}

void Store::modify() {
    // Edits entry 
    
    cout << "\nEnter the new name of the book:" << endl;
    getline (cin, book_name1);
    
    cout << "\nEnter new author's name: ";
    getline(cin,author_name);
    
    cout << "\nEnter new price(in Rs.): ";
    cin >> price;
    
    cout << "\nEnter new quantity:\n";
    cin >> quantity;
    
}

