#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

#ifndef _STORE_H_
#define _STORE_H_

class Store {
private:
    
    string book_name1;
    string author_name;
    int price;
    int quantity;
    
public:
    void get_data ();
    void modify ();
    
    
    string get_name () {
        return book_name1;
    }
    string get_a_name () {
        return author_name;
    }
    
    int get_qty () {
        return quantity;
    }
    
    int get_price () {
        return price;
    }
};

#endif // _STORE_H_
