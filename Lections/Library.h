#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Member> members;
    vector<Loan> loans;

public:
    void addBook(const Book& b) {
        books.push_back(b);
    }
    
    bool hasBook(const string& isbn) const {
        for (const auto& book : books) {
            if (book.getIsbn() == isbn) {
                return true;
            }
        }
        return false;
    }
    
    bool isBookAvailable(const string& isbn) const {
        if (!hasBook(isbn)) {
            return false;
        }
        
        for (const auto& loan : loans) {
            if (loan.getIsbn() == isbn && !loan.isReturned()) {
                return false;
            }
        }
        return true;
    }
    
    void addMember(const Member& m) {
        members.push_back(m);
    }
    
    bool hasMember(const string& memberId) const {
        for (const auto& member : members) {
            if (member.getMemberId() == memberId) {
                return true;
            }
        }
        return false;
    }
    
    bool loanBook(const string& isbn, const string& memberId,
                  const string& start, const string& due) {
        if (!hasBook(isbn)) return false;
        if (!hasMember(memberId)) return false;
        if (!isBookAvailable(isbn)) return false;
        
        try {
            Loan newLoan(isbn, memberId, start, due);
            loans.push_back(newLoan);
            return true;
        } catch (const exception&) {
            return false;
        }
    }
    
    bool returnBook(const string& isbn, const string& memberId) {
        for (auto& loan : loans) {
            if (loan.getIsbn() == isbn && 
                loan.getMemberId() == memberId && 
                !loan.isReturned()) {
                loan.markReturned();
                return true;
            }
        }
        return false;
    }
    
    vector<Book> findByAuthor(const string& authorName) const {
        vector<Book> result;
        for (const auto& book : books) {
            string bookAuthorName = book.getAuthor().getName();
            if (bookAuthorName.find(authorName) != string::npos ||
                authorName.find(bookAuthorName) != string::npos) {
                result.push_back(book);
            }
        }
        return result;
    }
    
string to_string() const {
    int activeLoans = 0;
    for (const auto& loan : loans) {
        if (!loan.isReturned()) {
            activeLoans++;
        }
    }

    string result = "=== Library ===\n";
    result += "Total books: " + std::to_string(books.size()) + "\n";

    if (!books.empty()) {
        result += "Books:\n";
        for (const auto& book : books) {
            result += " - " + book.to_string() + "\n";
        }
    }

    result += "\nTotal members: " + std::to_string(members.size()) + "\n";

    if (!members.empty()) {
        result += "Members:\n\n";
        for (const auto& member : members) {
            result += "" + member.to_string() + "\n";
        }
    }

    result += "Active loans: " + std::to_string(activeLoans) + "\n";
    result += "Total books in memory: " + std::to_string(Book::getTotalBooks());

    return result;
}

};
