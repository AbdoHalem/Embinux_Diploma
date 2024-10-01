#include "LibraryCatalog.hpp"

int menu();

int main()
{
    LibraryCatalog books;
    int choice = 0;
    while (choice != 4)
    {
        choice = menu();
        if(choice == 1){
            std::string title, author; int year;
            cout << "Enter the title of the book: "; cin.ignore(); std::getline(std::cin, title);
            cout << "Enter name of the author of the book: "; std::getline(std::cin, author);
            cout << "Enter the year of publication: "; cin >> year;
            books.addBook(title, author, year);
        }
        else if(choice == 2){
            std::string author;
            cout << "Enter the author's name: "; 
            cin.ignore(); std::getline(std::cin, author);
            books.searchByAuthor(author);
        }
        else if(choice == 3){
            books.displayCatalog();
        }
        else if(choice > 4){
            cout << "Invalid Choice!" << endl;
        }
    }
    
    return 0;
}

int menu(){
    cout << "\nMenu:" << endl;
    cout << "1. Add a book\n2. Search by author\n3. Display catalog\n4. Exit" <<endl;
    cout << "Enter your choice: "; 
    int choice = 0;
    cin >> choice;
    cout << endl;
    return choice;
}