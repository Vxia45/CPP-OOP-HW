#include <iostream>
using namespace std;

class DanceSchool {
protected:
    int dancersCount;
    double fee;

public:
    DanceSchool(double fee) : fee(fee), dancersCount(0) {}

    void setDancersCount(int count) {
        if (count < 10 || count > 25) {
            cout << "Dancers should be between 10 and 25!" << endl;
        } else {
            dancersCount = count;
        }
    }

    int getDancersCount() const {
        return dancersCount;
    }

    ~DanceSchool() {
        cout << "Dancers: " << dancersCount << endl;
        cout << "Fee: " << fee << endl;
    }
};

class DanceSchoolChitalishte : public DanceSchool {
private:
    string location = "Salona na NPG po KTS";

public:
    DanceSchoolChitalishte(double fee, const string& loc) : DanceSchool(fee), location(loc) {}

    DanceSchoolChitalishte() : DanceSchool(0) {}   

    ~DanceSchoolChitalishte() {
        cout << "Location: " << location << endl;
    }
};

int main() {
    DanceSchool school1(100);
    school1.setDancersCount(5);
    school1.setDancersCount(12);

    DanceSchoolChitalishte school2(120, "Chitalishte Vuzrashdane");
    school2.setDancersCount(20);

    DanceSchoolChitalishte school3;  

    return 0;
}
