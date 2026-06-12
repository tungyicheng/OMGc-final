//Date and day of week calculator for 2026算這月這日幾天後是啥
#include<bits/stdc++.h>
using namespace std;

class Date2026 {
    private:
        int d;  // day
        int m;  // month

    public:
        Date2026() : d(1), m(1) {}
        
        Date2026(int mm, int dd) {
            // 驗證月份
            if(mm < 1 || mm > 12) {
                cout << "the day or the month is not legitimate" << endl;
                exit(1);
            }
            
            // 驗證日期
            if(dd < 1) {
                cout << "the day or the month is not legitimate" << endl;
                exit(1);
            }
            
            // 檢查月份的最大日期
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
                // 2026年不是閏年
                if(dd > 28) {
                    cout << "the day or the month is not legitimate" << endl;
                    exit(1);
                }
            }
            
            m = mm;
            d = dd;
        }
        
        // 取得月份名稱
        string getMonthName() const {
            string months[] = {"", "January", "February", "March", "April", "May", "June",
                              "July", "August", "September", "October", "November", "December"};
            return months[m];
        }
        
        // 取得星期名稱
        string getDayOfWeekName() const {
            string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
            int firstDay[] = {0, 5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};
            int dayIndex = (firstDay[m] + (d - 1)) % 7;
            return daysOfWeek[dayIndex];
        }
        
        // 計算該日期是該年的第幾天
        int getDayOfYear() const {
            int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int dayOfYear = 0;
            for (int i = 1; i < m; i++) {
                dayOfYear += daysInMonth[i];
            }
            dayOfYear += d;
            return dayOfYear;
        }
        
        // 輸出日期和星期幾
        void print() const {
            cout << getDayOfWeekName() << ", " << getMonthName() << " " << d << ", 2026";
        }
        
        // 將日期向後推進 days 天
        void plusday(int days) {
            int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            
            d += days;
            
            while (d > daysInMonth[m]) {
                d -= daysInMonth[m];
                m++;
                if (m > 12) {
                    // 超出2026年
                    m = -1;
                    d = -1;
                    return;
                }
            }
        }
        
        // 檢查是否有效（在2026年內）
        bool isValid() const {
            return m >= 1 && m <= 12 && d >= 1;
        }
};

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int month, day, daysAfter;
        cin >> month >> day >> daysAfter;
        
        Date2026 originalDate(month, day);
        Date2026 newDate(month, day);
        newDate.plusday(daysAfter);
        
        if (!newDate.isValid()) {
            cout << "a date not in 2026" << endl;
        } else {
            cout << daysAfter << " days after ";
            originalDate.print();
            cout << " is ";
            newDate.print();
            cout << "." << endl;
        }
    }
    
    return 0;
}
