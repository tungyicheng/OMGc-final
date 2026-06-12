//比較這兩個日期的大小狀況 (三一律)
#include<bits/stdc++.h>
using namespace std;

class Date {
    protected:
        int d;  // day
        int m;  // month
        int y;  // year

    public:
        Date() : d(1), m(1), y(2026) {}
        
        Date(int mm, int dd, int yyyy) {
            if(mm < 1 || mm > 12) {
                cout << "the day or the month is not legitimate" << endl;
                exit(1);
            }
            
            if(dd < 1) {
                cout << "the day or the month is not legitimate" << endl;
                exit(1);
            }
            if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
                if(dd > 31) {
                    cout << "the day or the month is not legitimate" << endl;
                    exit(1);
                }
            }
            else if(mm == 4 || mm == 6 || mm == 9 || mm == 11) {
                if(dd > 30) {
                    cout << "the day or the month is not legitimate" << endl;
                    exit(1);
                }
            }
            else if(mm == 2) {
                int maxDay = isLeapYear() ? 29 : 28;
                if(dd > maxDay) {
                    cout << "the day or the month is not legitimate" << endl;
                    exit(1);
                }
            }
            
            m = mm;
            d = dd;
            y = yyyy;
        }
        
        virtual bool isLeapYear() const {
            return false;
        }
        
        virtual int getDayOfWeek() const {
            return 0;
        }
        
        // 取得月份名稱
        string getMonthName() const {
            string months[] = {"", "January", "February", "March", "April", "May", "June",
                              "July", "August", "September", "October", "November", "December"};
            return months[m];
        }
        
        int getDay() const { return d; }
        int getMonth() const { return m; }
        int getYear() const { return y; }
        
        // 計算該日期是該年的第幾天
        int getDayOfYear() const {
            int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (isLeapYear()) daysInMonth[2] = 29;
            
            int dayOfYear = 0;
            for (int i = 1; i < m; i++) {
                dayOfYear += daysInMonth[i];
            }
            dayOfYear += d;
            return dayOfYear;
        }
        
        // 比較操作符
        bool operator<(const Date& other) const {
            if (y != other.y) return y < other.y;
            if (m != other.m) return m < other.m;
            return d < other.d;
        }
        
        bool operator==(const Date& other) const {
            return y == other.y && m == other.m && d == other.d;
        }
        
        bool operator>(const Date& other) const {
            return other < *this;
        }
        
        virtual void print() const {}
};

class Date2026 : public Date {
    public:
        Date2026() : Date(1, 1, 2026) {}
        
        Date2026(int mm, int dd) : Date(mm, dd, 2026) {}
        
        bool isLeapYear() const override {
            return false;
        }

        int getDayOfWeek() const override {
            int firstDay[] = {0, 5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};
            int dayIndex = (firstDay[m] + (d - 1)) % 7;
            return dayIndex;
        }
        
        void print() const override {
            string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
            int firstDay[] = {0, 5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};
            int dayIndex = (firstDay[m] + (d - 1)) % 7;
            cout << daysOfWeek[dayIndex] << ", " << getMonthName() << " " << d << ", 2026";
        }
};

class Date2027 : public Date {
    public:
        Date2027() : Date(1, 1, 2027) {}
        
        Date2027(int mm, int dd) : Date(mm, dd, 2027) {}
        
        bool isLeapYear() const override {
            return false;
        }
        
        int getDayOfWeek() const override {
            int firstDay[] = {0, 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
            int dayIndex = (firstDay[m] + (d - 1)) % 7;
            return dayIndex;
        }
        
        void print() const override {
            string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
            int firstDay[] = {0, 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
            int dayIndex = (firstDay[m] + (d - 1)) % 7;
            cout << daysOfWeek[dayIndex] << ", " << getMonthName() << " " << d << ", 2027";
        }
};

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        Date2026 date1(m1, d1);
        Date2026 date2(m2, d2);
        
        if (date1 < date2) {
            cout << "<" << endl;
        } else if (date1 == date2) {
            cout << "=" << endl;
        } else {
            cout << ">" << endl;
        }
    }
    
    return 0;
}
