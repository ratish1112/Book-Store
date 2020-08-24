// Book Store program that can add to, edit, display and/or delete records

#include "Store.h"  

void add() {
    // Adds a book to the file
    Store obj;
    
    cout << endl;
    cout << "Enter the following details: " << endl;
    obj.get_data();
    
    ofstream out_file {"Store.txt", ios::app};
    if (!out_file) {
        cout << "Error opening file..." << endl;
    }
    
    bool flag = false;
    
    while (flag != (true)) {
        out_file << endl;
        out_file << setw(45) << left << obj.get_name()
                 << setw(20) << left << obj.get_a_name()
                 << setw(10) << left << obj.get_price()
                 << setw(7) << right << obj.get_qty ();
        
        flag = true;
    }
    out_file.close();
}

void display () {
    // Displays the entire inventory
    ifstream in_file {"Store.txt"};
     if (!in_file) {
        cout << "Error opening file..." << endl;
    }
    
    string line{};
    
    cout << endl;
    cout << setw(45) << left << "Book Name"
                     << setw(20) << left << "Author"
                     << setw(10) << left << "Price(Rs)"
                     << setw(7) << right << "Qty" << endl;
    
    while (getline(in_file,line)) {
        if (line.length() == 0) {
            cout << endl;
        }
        else {
            cout << line << endl;
        }
    }
    in_file.close();    
}

void display_one () {
    // Displays a single book's details
    
    string name {};
    bool temp = false;
    
    cout << "Enter book name for details: " << endl;
    cin.ignore();
    getline (cin,name);
    
    string line {};
    
    ifstream in_file {"Store.txt"};
    if (!in_file) {
        cout << "Error opening file..." << endl;
    }
    
    while (getline(in_file,line)) {
        if (line.find(name) != string :: npos) {
            cout << endl << setw(45) << left << "Book Name"
                 << setw(20) << left << "Author"
                 << setw(10) << left << "Price(Rs)"
                 << setw(7) << right << "Qty" << endl << endl;
                 
            cout << line << endl; 
            temp = true;
        }
    }
    
    in_file.close();    
    if (temp == false) {
        cout << "Book not found....." << endl;
    }
}
void search_name() {
    // Searches a book by the name of the book and reports
    // the number of times it is found
    int count {0};
    string name;
    
    string line;
    
    cin.ignore();
    cout << "Enter the book name: ";
    getline(cin, name);
    
    ifstream in_file {"Store.txt"};
     if (!in_file) {
        cout << "Error opening file..." << endl;
    }
    
    while (!in_file.eof()) {
           getline (in_file,line); 
        
        if ((line.find(name)) != (string::npos)) {
            count ++;
        }
    }
    in_file.close();
    if (count ==0) {
        cout << "\nBook not found." << endl;
    }
    else {
        cout << "\nBook: " << name << " was found " << count << " time(s)." << endl;
    }    
}

void search_author_name() {
    // Searches by the name of the author and reports
    // the number of times it is found
    int count {0};
    string line;
    string a_name;
    
    
    cin.ignore();
    cout << "Enter the author's name: ";
    getline(cin, a_name);
    
    ifstream in_file {"Store.txt"};
     if (!in_file) {
        cout << "Error opening file..." << endl;
    }
    
    while (!(in_file.eof())) {
        getline (in_file,line);
        
        if ((line.find(a_name)) != string::npos) {
            count ++;
        }
    }
    in_file.close();
    if (count ==0) {
        cout << "\nBooks by author entered not found." << endl;
    }
    else {
        cout << "\n" << count << " book(s) written by " << a_name << " found." << endl;
    }    
}

void search_price() {
    // Searches the inventory by price and reports
    // the number of times books with that price are found
    int count {0};
    string price_entered;
    
    string line {};
    
    cout << "Enter the price (in Rs): ";
    cin >> price_entered;
    
    ifstream in_file {"Store.txt"};
     if (!in_file) {
        cout << "Error opening file..." << endl;
    }
    
    while (!(in_file.eof())) {
        getline (in_file,line);
        
        if ((line.find(price_entered) != string::npos)) {
            count ++;
        }
    }
    in_file.close();
    if (count ==0) {
        cout << "\nBooks for the price entered not found." << endl;
    }
    else {
        cout << "\nBook(s) for price " << price_entered << " found " << count << " times." << endl;
    }    
}

void mod () {
    // Edit entry
    
    int count {0};
    int count1 {0};
    string name;
    bool temp = false;
    Store obj;
    
    string line;
    string line2;
    
    cin.ignore();    
    cout << "Enter the name of the book you want to edit: ";
    getline (cin,name);
    
    ifstream in_file ("Store.txt");
    ofstream out_file ("Temp.txt");
    
    if ((!in_file) || (!out_file)) {
        cout << "Error opening file..." << endl;
    }
    
    while (getline(in_file,line2)) {
        count ++;
    }
    
    in_file.close();
    
    ifstream in_file2 ("Store.txt");
    
    if ((!in_file2)) {
        cout << "Error opening file..." << endl;
    }
    
    while (!in_file2.eof()) {
        getline(in_file2,line);
        count1++;
                 
        if ((line.find(name)) != string::npos) {
            temp = true;
            obj.modify();
            
            if (count1 !=count) {
                out_file << setw(45) << left << obj.get_name()
                         << setw(20) << left << obj.get_a_name()
                         << setw(10) << left << obj.get_price()
                         << setw(7) << right << obj.get_qty () << endl;
                         
            }
            
            else {
                out_file << setw(45) << left << obj.get_name()
                         << setw(20) << left << obj.get_a_name()
                         << setw(10) << left << obj.get_price()
                         << setw(7) << right << obj.get_qty ();
            }
        }
        
        else {
            if (count1 != count) {
                out_file << line << endl;
            }
            else {
                out_file << line;
            }
        }
    } 
    
    in_file2.close();
    out_file.close();
    
   if ( temp == true) {
       remove ("Store.txt");
       rename ("Temp.txt", "Store.txt");
   }
   else {
       remove ("Temp.txt");
       cout << "\nBook you were looking for was not found..." << endl;
   }
    
}

void Delete () {
    // Delete entry
    
    int count {0};
    int count1 {0};
    
    string name;
    bool temp = false;
    string line;
    string line2;
    
    cin.ignore();
    cout << "Enter the name of the book you want to delete: ";
    getline (cin,name);
    
    
    ifstream in_file2 ("Store.txt");
    ofstream out_file ("Temp.txt");
    
    if ((!in_file2) || (!out_file)) {
        cout << "Error opening file..." << endl;
    }
    
    while (getline(in_file2,line2)) {
        count ++;
    }
    
    in_file2.close();
    
    ifstream in_file ("Store.txt");
    if (!in_file) {
        cout << "Error opening file..." << endl;
    }
    
    while (!(in_file.eof())) {
        count1++;
        getline(in_file,line);
        if ((line.find(name)) != string::npos) {
            temp = true;
        }
        
        else {
            if (count1 != count) {
                out_file << line << endl;
            }
            else {
                out_file << line;
            }
        }
        
    }
    
    in_file.close();
    out_file.close();
        
    if ( temp == true) {
       remove ("Store.txt");
       rename ("Temp.txt", "Store.txt");
       cout << "\nBook deleted from record" << endl;
   }
   else {
       remove ("Temp.txt");
       cout << "\nBook you were looking for was not found..." << endl;
   }
}


int main() {
    
    char a;

    do {
    
        cout << "\n\n" << setw(20) << "MENU\n";
        cout << "\n" << setw(19) << "**\n";
        cout << "\nPRESS 1 to add a book to the inventory";
        cout << "\n\nPRESS 2 to display inventory";
        cout << "\nPRESS 3 to display details of a single book";
        cout << "\n\nPRESS 4 to search by book name";
        cout << "\nPRESS 5 to search by author's name";
        cout << "\nPRESS 6 to search by price";
        cout << "\nPRESS 7 to edit an entry";
        cout << "\nPRESS 8 to delete an entry";
        cout << "\n\nPRESS 9 to QUIT";
        cout << "\n\nEnter your choice: ";
        
        cin >> a;

        switch (a)
        {
        case '1': 
                add();
                break;

        case '2': 
                display();
                break;
        
        case '3':
                display_one();
                break;

        case '4': 
                search_name();
                break;

        case '5': 
                search_author_name();
                break;

        case '6': 
                search_price();
                break;

        case '7': 
                mod();
                break;

        case '8': 
                Delete();
                break;

        case '9': 
                cout << "\n\n\n Thank you for using this program !\n\n" << "Have a great day ahead!" << endl;
                break;

        default: 
                cout << "\n WRONG CHOICE! PLEASE TRY AGAIN. \n\n";
                break;
        }

    } while (a!= '9');
    
    return 0;
}