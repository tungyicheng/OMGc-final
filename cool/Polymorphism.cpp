// use the virtual function to implement the polymorphism
#include <iostream>
#include <vector>
using namespace std;
class Date {
protected:
    int d, m, y;
public:
    Date() : d(1), m(1), y(2026) {}
    Date(int mm, int dd, int yyyy) : d(dd), m(mm), y(yyyy) {}

    virtual int getFirstDayWeek() const = 0;

    int getDay() const { return d; }
    int getMonth() const { return m; }
    int getYear() const { return y; }

    string getMonthName() const {
        string months[] = {"", "January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};
        return months[m];
    }
};

class Date2026 : public Date {
public:
    Date2026(int mm, int dd) : Date(mm, dd, 2026) {}
    int getFirstDayWeek() const override { return 4; } // 2026/1/1 是 Thursday (index 4)
};

class Date2027 : public Date {
public:
    Date2027(int mm, int dd) : Date(mm, dd, 2027) {}
    int getFirstDayWeek() const override { return 5; } // 2027/1/1 是 Friday (index 5)
};

void printDate(const Date* date, int year) {
    string daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // 1. 先取得那一年的 1/1 是星期幾
    int firstDay = date->getFirstDayWeek();

    // 2. 計算這一天在年內第幾天
    int day = date->getDay();
    int month = date->getMonth();

    int mdays[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
    int dayOfYear = day;
    for (int i = 1; i < month; ++i) dayOfYear += mdays[i];

    int weekIdx = (firstDay + dayOfYear - 1) % 7;
    cout << daysOfWeek[weekIdx] << ", " << date->getMonthName() << " " << date->getDay() << ", " << year << endl;
}

void calculateDays(const Date* date, int year) {
    // not specified, leave empty
}

int main() {
    int n;
    cin >> n;
    vector<Date*> dates(n);
    vector<int> years(n);

    for (int i = 0; i < n; i++) {
        int m, d, y;
        cin >> m >> d >> y;
        years[i] = y;
        if (y == 2026)
            dates[i] = new Date2026(m, d);
        else if (y == 2027)
            dates[i] = new Date2027(m, d);
        else
            dates[i] = nullptr;
    }

    for (int i = 0; i < n; i++) {
        if (dates[i]) printDate(dates[i], years[i]);
        else cout << "Unsupported year: " << years[i] << endl;
    }

    for (auto p : dates) delete p;
    return 0;
}