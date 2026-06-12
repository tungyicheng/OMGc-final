// 就多加一個2027 去算這星期幾
#include <bits/stdc++.h>
using namespace std;
class Date
{
protected:
    int d; // day
    int m; // month
    int y; // year

public:
    Date() : d(1), m(1), y(2026) {}

    Date(int mm, int dd, int yyyy)
    {
        if (mm < 1 || mm > 12)
        {
            cout << "the day or the month is not legitimate" << endl;
            exit(1);
        }

        if (dd < 1)
        {
            cout << "the day or the month is not legitimate" << endl;
            exit(1);
        }
        if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        {
            if (dd > 31)
            {
                cout << "the day or the month is not legitimate" << endl;
                exit(1);
            }
        }
        else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        {
            if (dd > 30)
            {
                cout << "the day or the month is not legitimate" << endl;
                exit(1);
            }
        }
        else if (mm == 2)
        {
            int maxDay = isLeapYear() ? 29 : 28;
            if (dd > maxDay)
            {
                cout << "the day or the month is not legitimate" << endl;
                exit(1);
            }
        }

        m = mm;
        d = dd;
        y = yyyy;
    }

    virtual bool isLeapYear() const
    {
        return false;
    }

    virtual int getDayOfWeek() const
    {
        return 0;
    }

    // 取得月份名稱
    string getMonthName() const
    {
        string months[] = {"", "January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};
        return months[m];
    }

    virtual void print() const {}
};

class Date2026 : public Date
{
public:
    Date2026() : Date(1, 1, 2026) {}

    Date2026(int mm, int dd) : Date(mm, dd, 2026) {}

    bool isLeapYear() const override
    {
        return false;
    }

    int getDayOfWeek() const override
    {
        int firstDay[] = {0, 5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};
        int dayIndex = (firstDay[m] + (d - 1)) % 7;
        return dayIndex;
    }

    void print() const override
    {
        string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        int firstDay[] = {0, 5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};
        int dayIndex = (firstDay[m] + (d - 1)) % 7;
        // Debug: cerr << "2026: m=" << m << " d=" << d << " firstDay[m]=" << firstDay[m] << " dayIndex=" << dayIndex << endl;
        cout << daysOfWeek[dayIndex] << ", " << getMonthName() << " " << d << ", 2026";
    }
};

class Date2027 : public Date
{
public:
    Date2027() : Date(1, 1, 2027) {}

    Date2027(int mm, int dd) : Date(mm, dd, 2027) {}

    bool isLeapYear() const override
    {
        return false;
    }
    int getDayOfWeek() const override
    {
        int firstDay[] = {0, 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        int dayIndex = (firstDay[m] + (d - 1)) % 7;
        return dayIndex;
    }

    void print() const override
    {
        string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        int firstDay[] = {0, 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        int dayIndex = (firstDay[m] + (d - 1)) % 7;
        cout << daysOfWeek[dayIndex] << ", " << getMonthName() << " " << d << ", 2027";
    }
};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int month, day, year;
        cin >> month >> day >> year;

        if (year == 2026)
        {
            Date2026 date = Date2026(month, day);
            date.print();
        }
        else if (year == 2027)
        {
            Date2027 date = Date2027(month, day);
            date.print();
        }
        else
        {
            cout << "Unsupported year: " << year << endl;
        }

        cout << endl;
    }

    return 0;
}
