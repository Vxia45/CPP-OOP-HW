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
    // Конструктор по подразбиране
    Loan() : isbn(""), memberId(""), startDate(""), dueDate(""), returned(false) {}
    
    // Параметризиран конструктор
    Loan(const string& isbn, const string& memberId, 
         const string& startDate, const string& dueDate)
        : isbn(isbn), memberId(memberId), startDate(startDate), 
          dueDate(dueDate), returned(false) {

        if (dueDate < startDate) {
            throw invalid_argument("Due date must be after or equal to start date");
        }
    }
    
    // Getters
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
    
    // Маркира заема като върнат
    void markReturned() {
        returned = true;
    }
    
    // Проверява дали е просрочен
    bool isOverdue(const string& today) const {
        return !returned && (today > dueDate);
    }
    
    // Представяне като string (без ostringstream)
    string to_string() const {
        return "Loan: ISBN=" + isbn +
               ", Member=" + memberId +
               ", Start=" + startDate +
               ", Due=" + dueDate +
               ", Returned=" + (returned ? "Yes" : "No");
    }
};
