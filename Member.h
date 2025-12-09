#include <string>
#include <stdexcept>
using namespace std;

class Member {
private:
    string name;
    string memberId;
    int yearJoined;

public:
    Member() : name("Unknown"), memberId(""), yearJoined(2000) {}
    
    Member(const string& name, const string& memberId, int yearJoined)
        : name(name), memberId(memberId), yearJoined(yearJoined) {
        if (memberId.empty()) {
            throw invalid_argument("Member ID cannot be empty");
        }
        if (yearJoined < 1900 || yearJoined > 2025) {
            throw invalid_argument("Year joined must be between 1900 and 2025");
        }
    }
    
    string getName() const {
        return name;
    }
    
    string getMemberId() const {
        return memberId;
    }
    
    int getYearJoined() const {
        return yearJoined;
    }
    
    string to_string() const {
    return "Member: " + name + ",\n"
           "Member ID: " + memberId + 
           ",\nJoined: " + std::to_string(yearJoined) + "\n";
}

};

