#include <string>
#include <stdexcept>
using namespace std;

class Loan {
private:
    string isbn;
    string memberId;
    string startDate;
    string dueDate;
    bool returned;

public:
    Loan() : isbn(""), memberId(""), startDate(""), dueDate(""), returned(false) {}
    
    Loan(const string& isbn, const string& memberId, 
         const string& startDate, const string& dueDate)
        : isbn(isbn), memberId(memberId), startDate(startDate), 
          dueDate(dueDate), returned(false) {

        if (dueDate < startDate) {
            throw invalid_argument("Due date must be after or equal to start date");
        }
    }
    
    string getIsbn() const { 
        return isbn; 
    }
    string getMemberId() const { 
        return memberId; 
    }
    string getStartDate() const { 
        return startDate; 
    }
    string getDueDate() const { 
        return dueDate; 
    }
    bool isReturned() const { 
        return returned; 
    }
    
    void markReturned() {
        returned = true;
    }
    
    bool isOverdue(const string& today) const {
        return !returned && (today > dueDate);
    }
    
    string to_string() const {
        return "Loan: ISBN=" + isbn +
               ", Member=" + memberId +
               ", Start=" + startDate +
               ", Due=" + dueDate +
               ", Returned=" + (returned ? "Yes" : "No");
    }
};
