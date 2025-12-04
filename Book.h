#include "Author.h"
#include <string>
#include <stdexcept>
#include <utility>
using namespace std;

class Book {
private:
    string title;
    Author author;
    int year;
    double price;
    string isbn;
    static int totalBooks;


public:
    Book() : title("Untitled"), author(), year(2000), price(0.0), isbn("") {
        totalBooks++;
    }
    
    Book(const string& title, const Author& author, int year, double price, const string& isbn)
        : title(title), author(author), year(year), price(price), isbn(isbn) {
        if (year < 1450 || year > 2025) {
            throw invalid_argument("Year must be between 1450 and 2025");
        }
        if (price < 0) {
            throw invalid_argument("Price cannot be negative");
        }
        totalBooks++;
    }
    
    Book(const Book& other) 
        : title(other.title), author(other.author), year(other.year), 
          price(other.price), isbn(other.isbn) {
        totalBooks++;
    }
    
    Book(Book&& other) noexcept
        : title(move(other.title)), author(move(other.author)), year(other.year),
          price(other.price), isbn(move(other.isbn)) {
        totalBooks++;
    }
    
 
    Book& operator=(const Book& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
            year = other.year;
            price = other.price;
            isbn = other.isbn;
        }
        return *this;
    }
    
    Book& operator=(Book&& other) noexcept {
        if (this != &other) {
            title = move(other.title);
            author = move(other.author);
            year = other.year;
            price = other.price;
            isbn = move(other.isbn);
        }
        return *this;
    }
    
    ~Book() {
        totalBooks--;
    }
    
    string getTitle() const { 
        return title; 
    }
    Author getAuthor() const { 
        return author; 
    }
    int getYear() const { 
        return year; 
    }
    double getPrice() const { 
        return price; 
    }
    string getIsbn() const { 
        return isbn; 
    }
    
    // Setters
    void setYear(int y) {
        if (y < 1450 || y > 2025) {
            throw invalid_argument("Year must be between 1450 and 2025");
        }
        year = y;
    }
    
    void setPrice(double p) {
        if (p < 0) {
            throw invalid_argument("Price cannot be negative");
        }
        price = p;
    }
    
    string to_string() const {
        return "\"" + title + "\" by " + author.to_string()
             + ", Year: " + std::to_string(year)
             + ", ISBN: " + isbn
             + ", Price: " + std::to_string(price) + " leva";
    }
    
    static int getTotalBooks() {
        return totalBooks;
    }
};


   int Book::totalBooks = 0;