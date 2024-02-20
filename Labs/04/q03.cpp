/*
 * Creator: Fasih Hasan Khan 23K-0018
 */

#include <iostream>

using namespace std;

class WeekDays{
private:
    string days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int CurrentDay;
public:
    /*
        the question asked to init the days array in the default constructor and not in the parameterized one
        however, when instantiating a class using a param. cons., the days array will have null strings stored.
        therefore, i've moved the init of the days array to the top
    */
    WeekDays() : CurrentDay(0) {}
   
    WeekDays(unsigned today) : CurrentDay(today%7) {}

    string getCurrentDay() { return days[CurrentDay] ;}
   
    string getNextDay() { return days[abs(CurrentDay-1)%7] ;}
   
    string getPreviousDay() { return days[(CurrentDay+6)%7] ;}
   
    string getNthDay(int n) { return days[abs(CurrentDay+n)%7] ;}
};

int main() {
    int day;
    cin >> day;
    WeekDays days(day);

    cout << "Current day: " << days.getCurrentDay() << endl;
    cout << "Next day: " << days.getNextDay() << endl;
    cout << "Previous day: " << days.getPreviousDay() << endl;

    int n;
    cin >> n;
    cout << "Nth day: " << days.getNthDay(n) << endl;
   
    return 0;
}