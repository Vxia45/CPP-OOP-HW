#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Library lib;
    Author a{"Ivan Vazov", 1850};
    Author a2{"Yordan Yovkov", 1880};
    Book b1{"Pod igoto", a, 1894, 25.50, "ISBN-001"};
    Book b2{"Nema zemya", a, 1900, 18.90, "ISBN-002"};
    Book b3("Staroplaninski legendi", a2, 1927, 15.00, "ISBN-003");

    // Adding books to the lib
    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    // Adding members to the library
    lib.addMember(Member{"Andrey Tinchev", "M001", 2025});
    lib.addMember(Member("Petar Petrov", "M002", 2023));

    cout << lib.to_string() << "\n";

    cout << "\n=== Book Loans ===" << endl;
    if (lib.loanBook("ISBN-001", "M001", "2025-11-03", "2025-11-17"))
        cout << "\nLoan created.\n";

    cout << "\n=== Book Availability ===" << endl;
    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";
    cout << "Available ISBN-002? " << boolalpha << lib.isBookAvailable("ISBN-002") << "\n";
    cout << "Available ISBN-003? " << boolalpha << lib.isBookAvailable("ISBN-003") << "\n";
    
    cout << "\n=== Book Returns ==="<< endl;
    lib.returnBook("ISBN-001", "M001");
    cout << "Available ISBN-001? " << boolalpha << lib.isBookAvailable("ISBN-001") << "\n";

    cout << "\n=== Find By Author ===" << endl;
    for (const auto& bk : lib.findByAuthor("Vazov")) {
        cout <<  bk.to_string() << "\n";
    }

    cout << "\n=== Testing Rule of 5 ===\n";
    Book b4 = b1; 
    cout << "Copied book: " << b4.to_string() << "\n";
    
    Book b5 = move(b3); 
    cout << "Moved book: " << b5.to_string() << "\n";

    cout << "\n=== Final Result ==="<<endl;
    cout << lib.to_string() << "\n";

     cout << "\n=== Validations ===\n";
    try {
        Author invalidAuthor("Test", 1800); 
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
    
    try {
        Book invalidBook("Test", a, 2030, -10.0, "ISBN-999");
    } catch (const exception& e) {
        cout << "Error:" << e.what() << "\n";
    }
}