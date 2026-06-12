// 計算這是星期幾
#include <bits/stdc++.h>
using namespace std;
class Date2026
{
private:
    int d;
    int m;

public:
    Date2026() : d(1), m(1) {}
    Date2026(int mm, int dd)
    {
        //For the two-parameter constructor Date2026(int dd, int mm),\
            you just need to make sure that month (mm) and day (dd) are legitimate and set d = dd,\
            and m = dd. If either the day or the month is not legitimate, the code should report error and exit.
        // 痾 exit(1) is ai code ?                                                                      sus\
            還是老師下次藏隱形字
        // 或者特殊肉眼看不到的浮水印 通常是這樣吧sus
        if (mm < 1 or mm > 12)
        {
            cout << "the day or the month is not legitimate" << endl;
        }
        if (dd < 1)
        {
            cout << "the day or the month is not legitimate" << endl;
        }
        if (mm == 1 or mm == 3 or mm == 5 or mm == 7 or mm == 8 or mm == 10 or mm == 12)
        {
            if (dd > 31)
            {
                cout << "the day or the month is not legitimate" << endl;
            }
        }
        if (mm == 4 or mm == 6 or mm == 9 or mm == 11)
        {
            if (dd > 30)
            {
                cout << "the day or the month is not legitimate" << endl;
            }
        }
        if (mm == 2)
        {
            if (dd > 28)
            {
                cout << "the day or the month is not legitimate" << endl;
            }
        }
        m = mm;
        d = dd;
    }
    void print()
    {
        string months[] = {"", "January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};
        string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        // 有點想存365天的表
        // 不然要每個月存一天去找
        // 或者從第一天去推       Thursday, January 1, 2026 阿這可以叫AI算嗎雖然我按右下角可以自己茶就是了
        /**
         *
         * Thursday, January 1, 2026
         * Sunday, February 1, 2026
         * Sunday, March 1, 2026
         * Wednesday, April 1, 2026
         * Friday, May 1, 2026
         * Monday, June 1, 2026
         * Wednesday, July 1, 2026
         * Saturday, August 1, 2026
         * Tuesday, September 1, 2026
         * Thursday, October 1, 2026
         * Sunday, November 1, 2026
         * Tuesday, December 1, 2026
         *
         *
         */
        int firstDay[] = {0, 5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};
        // 就看的出來應該是這樣吧
        int dayIndex = (firstDay[m] + (d - 1)) % 7;
        // cout << "pm: " << pm << " pd: " << pd << endl;
        cout << daysOfWeek[dayIndex] << ", " << months[m] << " " << d << ", 2026"; // 1base真好用的時刻 ouob
    }
};
int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int month, day;
        cin >> month;
        cin >> day;
        Date2026 date = Date2026(month, day);
        date.print();
        cout << endl;
    }
}