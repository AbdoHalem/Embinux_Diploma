#ifndef __BOOK__H__
#define __BOOK__H__
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
    std::string title_;     // store the title of the book
    std::string author_;    // store the author of the book
    int year_;              // store the publication year of the book
    
public:
    /* Parameterized constructor with member init list */
    Book(string title, string author, int year) : title_(title), author_(author), year_(year) {}
    /* Destructor */
    ~Book(){}
    /* Getter Methods */
    string get_title(){return title_;}
    string get_author(){return author_;}
    int get_year(){return year_;}
    /* Member Functions */
    void displayInfo(){
        cout << "Title: " << title_ << ", Author: " << author_ << ", Year: " << year_ <<endl;
    }
};


#endif  //!__BOOK__H__