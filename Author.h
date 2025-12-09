#include <string>
#include <stdexcept>
using namespace std;

class Author {
private:
    string name;
    int birthYear;

public:
    Author() : name("Unknown"), birthYear(1900) {}
    
    Author(const string& name, int birthYear) 
        : name(name), birthYear(birthYear) {
        if (birthYear < 1850 || birthYear > 2025) {
            throw invalid_argument("Invalid birth year");
        }
    }
    
    string getName() const {
        return name;
    }
    
    int getBirthYear() const {
        return birthYear;
    }
    
    void setBirthYear(int year) {
        if (year < 1850 || year > 2025) {
            throw invalid_argument("Invalid birth year");
        }
        birthYear = year;
    }
    
    string to_string() const {
        return name + " (born " + std::to_string(birthYear) + ")";
    }
};
