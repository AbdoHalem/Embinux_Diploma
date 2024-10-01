#ifndef __LIBRARYCATALOG__H__
#define __LIBRARYCATALOG__H__

#include "Book.hpp"

class LibraryCatalog
{
private:
   std::vector<Book> books;
public:
    /* Default Constructor */
    LibraryCatalog(){}
    /* Destructor */
    ~LibraryCatalog(){}

    /* Member Functions */
    /* Add new book to the catalog */
    void addBook(string title, string author, int year){
        Book book(title, author, year);
        books.push_back(book);      // Add new book to the catalog
        cout << "Book is added successfully!" << endl;
    }
    /* Search for Author's Books */
    void searchByAuthor(string author){
        cout << "\nBooks by " << author << endl;
        for(auto book : books){
            if(book.get_author() == author){
                book.displayInfo();
            }
        }
    }
    void displayCatalog(){
        for(auto book : books){
            cout << "Display all books in the catalog: " << endl;
            book.displayInfo();
        }
    }
};


#endif  //!__LIBRARYCATALOG__H__
